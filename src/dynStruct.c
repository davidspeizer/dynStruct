#include "dr_api.h"
#include "dr_ir_opnd.h"
#include "dr_ir_instr.h"
#include "drutil.h"
#include "drwrap.h"
#include "drmgr.h"
#include "drsyms.h"
#include "../includes/utils.h"
#include "../includes/block_utils.h"
#include "../includes/allocs.h"
#include "../includes/rw.h"
#include "../includes/out.h"
#include "../includes/call.h"
#include "../includes/sym.h"
#include "../includes/tree.h"
#include "../includes/elf.h"
#include "../includes/args.h"

malloc_t *old_blocks = NULL;
tree_t *active_blocks = NULL;
int tls_stack_idx = -1;
void *lock;

static void thread_exit_event(void *drcontext)
{
  clean_stack(drcontext);
}

// app2app is the first step of instrumentation, only use to replace string
// instructions by a loop to have a better monitoring
static dr_emit_flags_t bb_app2app_event(void *drcontext,
                                        __attribute__((unused)) void *tag,
                                        instrlist_t *bb,
                                        __attribute__((unused)) bool for_trace,
                                        __attribute__((unused)) bool translating)
{
  DR_ASSERT(drutil_expand_rep_string(drcontext, bb));
  return DR_EMIT_DEFAULT;
}

// instrument each read or write instruction in order to monitor them
// also instrument each call/return to update our stack
static dr_emit_flags_t bb_insert_event(void *drcontext,
                                       __attribute__((unused)) void *tag,
                                       instrlist_t *bb, instr_t *instr,
                                       __attribute__((unused)) bool for_trace,
                                       __attribute__((unused)) bool translating,
                                       __attribute__((unused)) void *user_data)
{
  app_pc pc;
  instr_t *ctx_instr;
  app_pc ctx_pc;

  pc = instr_get_app_pc(instr);

  if (pc == NULL || instr_is_meta(instr))
    return DR_EMIT_DEFAULT;

  // if the module is not monitored, we don't have to instrument momery access
  // but we still have to maj our stack so we instrument call and return
  if (pc_is_monitored(pc))
  {
    if (instr_reads_memory(instr))
      for (int i = 0; i < instr_num_srcs(instr); i++)
        if (opnd_is_memory_reference(instr_get_src(instr, i)))
        {
          ctx_instr = instr_get_next_app(instr);
          if (ctx_instr)
            ctx_pc = instr_get_app_pc(ctx_instr);
          else
            ctx_pc = NULL;
          dr_insert_clean_call(drcontext, bb, instr, &memory_read,
                               false, 2, OPND_CREATE_INTPTR(pc),
                               OPND_CREATE_INTPTR(ctx_pc));
          // break to not instrument the same instruction 2 time
          break;
        }

    if (instr_writes_memory(instr))
      for (int i = 0; i < instr_num_dsts(instr); i++)
        if (opnd_is_memory_reference(instr_get_dst(instr, i)))
        {
          ctx_instr = instr_get_prev_app(instr);
          if (ctx_instr)
            ctx_pc = instr_get_app_pc(ctx_instr);
          else
            ctx_pc = NULL;
          dr_insert_clean_call(drcontext, bb, instr, &memory_write,
                               false, 2, OPND_CREATE_INTPTR(pc),
                               OPND_CREATE_INTPTR(ctx_pc));
          /* break to not instrument the same instruction 2 time */
          break;
        }
  }

  // if one day dynStruct has to be used on arm, maybe some call will be missed
  if (instr_is_app(instr) && instr_is_call_direct(instr))
    dr_insert_clean_call(drcontext, bb, instr, &dir_call_monitor,
                         false, 1,
                         OPND_CREATE_INTPTR(instr_get_branch_target_pc(instr)));
#ifdef BUILD_64
  else if (instr_is_app(instr) && instr_is_call_indirect(instr))
#else
  else if (instr_is_app(instr) && instr_is_call_indirect(instr) &&
           !indirect_call_ignore(instr))
#endif
    dr_insert_mbr_instrumentation(drcontext, bb, instr, &ind_call_monitor,
                                  SPILL_SLOT_1);
  else if (instr_is_app(instr) && instr_is_return(instr))
    dr_insert_clean_call(drcontext, bb, instr, &ret_monitor,
                         false, 1, OPND_CREATE_INTPTR(instr_get_app_pc(instr)));

  return DR_EMIT_DEFAULT;
}

static void load_event(void *drcontext,
                       const module_data_t *mod,
                       __attribute__((unused)) bool loaded)
{
  dr_printf("Loading module %s\n", dr_module_preferred_name(mod));
  app_pc malloc = (app_pc)dr_get_proc_address(mod->handle,
                                              "malloc");
  app_pc calloc = (app_pc)dr_get_proc_address(mod->handle,
                                              "calloc");
  app_pc realloc = (app_pc)dr_get_proc_address(mod->handle,
                                               "realloc");
  app_pc free = (app_pc)dr_get_proc_address(mod->handle,
                                            "free");
  ds_module_data_t tmp_data;

  dr_mutex_lock(lock);

  if (!add_to_module_list(mod))
    return;

  if (!maj_args(mod))
    return;

  tmp_data.start = mod->start;
  tmp_data.got = NULL;
  drsym_enumerate_symbols_ex(mod->full_path, sym_to_hashmap,
                             sizeof(drsym_info_t), &tmp_data,
                             DRSYM_DEMANGLE_FULL);

  // `start` here is the memory address of the beginning of the loaded program.
  // We'll want to save that to get memory offsets of malloc calls.
  dr_printf("Found data. start=%#p, got=%#p, malloc=%#p\n", tmp_data.start, tmp_data.got, malloc);

  add_plt(mod, tmp_data.got, drcontext);
  dr_mutex_unlock(lock);

  // free all data relative to symbols (like debug info) after loading symbol
  drsym_free_resources(mod->full_path);

  // Check if we've loaded libc and therefore want to hook
  if (!module_is_alloc(mod))
    return;

  // This registers hooks at the start and end of the malloc calls and at the start of the free call.
  // A user_data structure is passed to both pre and post, allowing the user to write data before the malloc
  // and check it afterwards.
  if (malloc)
    DR_ASSERT(drwrap_wrap(malloc, pre_malloc, post_malloc));

  if (calloc)
    DR_ASSERT(drwrap_wrap(calloc, pre_calloc, post_calloc));

  if (realloc)
    DR_ASSERT(drwrap_wrap(realloc, pre_realloc, post_realloc));

  if (free)
    DR_ASSERT(drwrap_wrap(free, pre_free, NULL));
}

void unload_event(__attribute__((unused)) void *drcontext,
                  const module_data_t *mod)
{
  remove_plt(mod);
}

static void exit_event(void)
{
  dr_mutex_lock(lock);

  output();

  clean_module_list();
  clean_old_sym();

  hashtable_delete(&sym_hashtab);

  clean_args();

  drmgr_unregister_tls_field(tls_stack_idx);

  dr_mutex_unlock(lock);
  dr_mutex_destroy(lock);

  drsym_exit();
  drwrap_exit();
  drmgr_exit();
  drutil_exit();
}

DR_EXPORT void dr_client_main(client_id_t __attribute__((unused)) id,
                              int argc, const char *argv[])
{
  drmgr_priority_t p = {
      sizeof(p),
      "reccord heap access and recover datas structures",
      NULL,
      NULL,
      0};

  dr_set_client_name("dynStruct", "ampotos@gmail.com");

  drsym_init(0);
  drwrap_init();
  drmgr_init();
  drutil_init();

  if (!parse_arg(argc, (char **)argv))
    dr_abort();
  dr_register_exit_event(&exit_event);
  // Whenever we load a new shared object or binary, load_event is called.
  // This function adds hook points at libc malloc, calloc, realloc, and free.
  // These hook points are:
  //    pre_malloc, post_malloc, pre_calloc, post_calloc, pre_realloc, post_realloc, pre_free, post_free
  if (!drmgr_register_module_load_event(&load_event) ||
      // only use to remove plt from plt tree if a library is unload at runtime
      !drmgr_register_module_unload_event(&unload_event) ||
      !drmgr_register_bb_app2app_event(&bb_app2app_event, &p) ||
      !drmgr_register_thread_exit_event(&thread_exit_event) ||
      // only use insert event because we only need to monitor single instruction
      !drmgr_register_bb_instrumentation_event(NULL, &bb_insert_event, &p))
    DR_ASSERT_MSG(false, "Can't register event handler\n");

  // register slot for each thread
  tls_stack_idx = drmgr_register_tls_field();
  DR_ASSERT_MSG(tls_stack_idx != -1, "Can't register tls field\n");

  hashtable_init(&sym_hashtab, 16, HASH_INTPTR, false);

  lock = dr_mutex_create();
  DR_ASSERT_MSG(lock, "Can't create mutex\n");
}
