#include "dr_api.h"
#include "drwrap.h"
#include "../includes/utils.h"
#include "../includes/block_utils.h"
#include "../includes/sym.h"
#include "../includes/call.h"
#include "../includes/out.h"

malloc_t *add_block(size_t size, void *pc, void *drcontext)
{
  dr_printf("New block of size %d at pc=%p\n", size, pc);
  // dr_custom_alloc(void* drcontext, dr_alloc_flags_t flags, size_t size, uint prot, void* addr)
  // Allocates memory with the properties requeted by FLAGS.
  malloc_t *new = dr_custom_alloc(NULL, 0, sizeof(*new),
                                  DR_MEMPROT_WRITE | DR_MEMPROT_READ, NULL);

  if (!new)
    dr_printf("dr_malloc fail\n");
  else
  {
    // Writes 0 to every byte of new.
    ds_memset(new, 0, sizeof(*new));
    new->size = size;
    new->alloc_pc = pc;
    // Populates address, symbol name, and module name of the alloc call.
    get_caller_data(&(new->alloc_func_pc),
                    &(new->alloc_func_sym),
                    &(new->alloc_module_name), drcontext, 1);
    printf("Got caller data. address=%p, symbol=%s, func=%s\n", new->alloc_func_pc, new->alloc_func_sym, new->alloc_module_name);
  }

  return new;
}

void set_addr_malloc(malloc_t *block, void *start, unsigned int flag,
                     int realloc)
{
  if (!start && block)
  {
    if (!realloc)
    {
      dr_printf("alloc of size %d failed\n", block->size);
      dr_custom_free(NULL, 0, block, sizeof(*block));
    }
    else if (!(block->flag & FREE))
    {
      dr_printf("Realloc of size %d on %p failed\n",
                block->size, block->start);
      block->flag |= FREE;
      block->next = old_blocks;
      old_blocks = block;

      del_from_tree(&active_blocks, block->start, NULL, false);
    }
  }
  else if (block)
  {
    block->start = start; // Start of the allocated block
    block->end = block->start + block->size;  // End of the allocated block
    block->flag = flag;

    block->node.min_addr = block->start;
    block->node.high_addr = block->end;
    block->node.data = block;
    if (!add_to_tree(&active_blocks, (tree_t *)block))
      dr_custom_free(NULL, 0, block, sizeof(*block));
  }
  else
    dr_printf("Error : *alloc post wrapping call without pre wrapping\n");
}
