import binascii
import _dynStruct
from ghidra.program.model.lang import Register
#import capstone

#unsigned_int_instr = [capstone.x86.X86_INS_ADCX, capstone.x86.X86_INS_ADOX,
#                      capstone.x86.X86_INS_DIV, capstone.x86.X86_INS_MUL,
#                      capstone.x86.X86_INS_MULX]

#xmm_regs = [xmm for xmm in range(capstone.x86.X86_REG_XMM0 - 1, capstone.x86.X86_REG_XMM31)]

class Access:

    def __init__(self, access, orig, addr_start, block, t):
        self.block = block
        self.offset = access
        self.addr = addr_start + self.offset
        self.size = orig["size_access"]
        self.t = t

        if len(orig["opcode"]) % 2:
            orig["opcode"] = "0" + orig["opcode"]
        self.instr_op = orig["opcode"]

        if orig["ctx_opcode"] and len(orig["ctx_opcode"]) % 2:
            orig["ctx_opcode"] = "0" + orig["ctx_opcode"]
        self.ctx_opcode = orig["ctx_opcode"]

        json_attrib = ["nb_access", "pc", "func_pc",
                       "func_sym", "func_module", "ctx_addr"]
        
        for k in json_attrib:
            setattr(self, k, (orig[k]))

        self.disass()

        self.instr_display = '<span class="text-success"><strong>%s</strong>\
        </span><span class="text-info">%s</span>' % (self.instr.mnemonic,
                                                     self.instr.op_str)
        self.instr_search = '%s %s' % (self.instr.mnemonic, self.instr.op_str)
        if self.ctx_opcode:
            if self.ctx_addr > self.pc:
                self.ctx_instr_display = "Next : "
            else:
                self.ctx_instr_display = "Prev : "
            self.ctx_instr_display += '<span class="text-success"><strong>%s</strong>\
            </span><span class="text-info">%s</span>' % (self.ctx_instr.mnemonic,
                                                         self.ctx_instr.op_str)
            self.ctx_instr_search = '%s %s' % (self.ctx_instr.mnemonic, self.ctx_instr.op_str)
        else:
            self.ctx_instr_search = 'No context'
            self.ctx_instr_display = '<span class="text-danger">No context</span>'

    def is_offset(self, offset):
        return self.offset == offset

    def is_in_range(self, start, end):
        if self.offset >= start and self.offset < end:
            return True

        if self.offset < start and self.offset + self.size >start:
            return True

        return False
        
    def in_member(self, member):
        if self.is_offset(member.offset):
            return True

        if self.offset >= member.offset and\
           self.offset < member.offset + member.size:
            return True

        return False

    def disass(self):
        print("Calling disass with pc=0x{:x}, ctx_addr=0x{:x}".format(self.pc, self.ctx_addr))
    #    if not _dynStruct.disasm:
    #        _dynStruct.create_disasm()

        if not hasattr(self, 'instr'):
            self.instr = getInstructionAt(toAddr(self.pc))
            if self.ctx_opcode:
                self.ctx_instr = getInstructionAt(toAddr(self.ctx_addr))

    def analyse_ctx(self, size):
        #TODO extend analyse to other instruction and
        # SSEX, AVX and other intel extension

        if not hasattr(self, 'instr'):
            self.disass()

        if self.t == 'write':
            # Detect if the written val is the result from a floating point register
            if self.instr.getMnemonicString().startswith("MOV"):
                src_op = self.instr.getRegister(1)
                if src_op is not None and src_op.getName().startswith("xmm"):
                    if size == 4:
                        return _dynStruct.float_str
                    elif size == 8:
                        return _dynStruct.double_str
                    else:
                        return None
                elif self.ctx_opcode and self.ctx_instr.getMnemonicString().startswith("MOV"):
                    # Check if the context was a MOV instruction that is being read by our current instruction.
                    dest_ctx_reg = self.ctx_instr.getRegister(0)
                    src_ctx_op = self.ctx_instr.getRegister(1)
                    if dest_ctx_reg is not None and self.instr.getRegister(1) == dest_ctx_reg and src_ctx_op.getName().startswith("xmm"):
                        if size == 4:
                            return _dynStruct.float_str
                        elif size == 8:
                            return _dynStruct.double_str
                        else:
                            return None
                        
            # Next analysis need a ctx_instr
            if not self.ctx_opcode:
                return None

            # detect ptr if ctx = lea and instr = mov with the reg value
            # get from lea. If yes it's a ptr
            if self.ctx_instr.getMnemonicString() == "LEA":
                dest_reg = self.ctx_instr.getRegister(0)
                if self.instr.getMnemonicString().startswith("MOV") and \
                   self.instr.getRegister(1) is not None and \
                   self.instr.getRegister(1) == dest_reg:
                    op_objs = self.ctx_instr.getOpObjects(1)
                    uses_rip = False
                    offset = None
                    for obj in op_objs:
                        if isinstance(obj, Register) and obj.getName() in ["RIP", "EIP"]:
                            uses_rip = True
                        elif isinstance(obj, Scalar):
                            offset = obj.getValue()
                    if uses_rip and offset is not None:
                        if self.instr.getAddress() + offset / 4096 == self.instr.getAddress() / 4096:
                            return _dynStruct.ptr_func_struct

                    # Here's where I'm at

         #   if self.ctx_instr.id == capstone.x86.X86_INS_LEA:
         #       dest_reg = self.ctx_instr.operands[0].reg
         #       if self.instr.mnemonic.startswith('mov') and\
         #          self.instr.op_find(capstone.x86.X86_OP_REG, 1) and\
         #          self.instr.op_find(capstone.x86.X86_OP_REG, 1).reg == dest_reg:

                    # if ptr is on the same memory page than rip/eip it's a func ptr
                    op_src = self.ctx_instr.operands[1]
                    if op_src.type == capstone.x86.X86_OP_MEM:
                        if op_src.mem.base in [capstone.x86.X86_REG_RIP,
                                               capstone.x86.X86_REG_EIP]:
                            if op_src.mem.index == 0 and\
                               int((op_src.mem.disp + self.instr.address) / 4096)\
                               == int(self.instr.address / 4096):
                                return _dynStruct.ptr_func_str

                    # if not it's just a ptr because we cannot have more information
                    return _dynStruct.ptr_str

            # when the mov is an imm value on the same page than rip => func_ptr
            if self.instr.mnemonic.startswith('mov') and\
               self.instr.op_find(capstone.x86.X86_OP_IMM, 1) and\
               size == _dynStruct.bits / 8:
                if int(self.instr.address / 4096) ==\
                   int(self.instr.operands[1].imm / 4096):
                    return _dynStruct.ptr_func_str

            # detecting if signed or unsigned
            if self.instr.mnemonic.startswith('mov') and len(self.ctx_instr.operands) == 2:
                dest_ctx_op = self.ctx_instr.operands[0]
                src_op = self.instr.operands[1]
                if dest_ctx_op.type == capstone.x86.X86_OP_REG and\
                   src_op.type == capstone.x86.X86_OP_REG and\
                   src_op.reg == dest_ctx_op.reg:
                    if self.instr.id in unsigned_int_instr:
                        return _dynStruct.unsigned_str % (size)

        # For read access we can only detect ptr because a use of the value read
        # Basically member is pointer if the value read is dereferenced
        else:
            if self.instr.id == capstone.x86.X86_INS_CALL:
                return _dynStruct.ptr_func_str

            # For other instruction we need context to perform the analysis
            if not self.ctx_instr:
                return None

            if not self.instr.mnemonic.startswith('mov'):
                return None

            # usually if the value is used later (not just a copy) the value
            # is load into a register
            dest_op = self.instr.operands[0]
            if dest_op.type == capstone.x86.X86_OP_REG:

                # if the register is an xmm register, the value is a floating
                # point
                if dest_op.reg in xmm_regs:
                    if size == 4:
                        return _dynStruct.float_str
                    elif size == 8:
                        return _dynStruct.double_str
                    else:
                        return None

                # if the context instr is a call using the previously right
                # reg, the value is a ptr to func
                if self.ctx_instr.id == capstone.x86.X86_INS_CALL and\
                   self.ctx_instr.operands[0].type == capstone.x86.X86_INS_CALL and\
                   self.ctx_instr.operands[0].reg == dest_op.reg:
                    return _dynStruct.ptr_func_str

                for ctx_src_op in self.ctx_instr.operands:
                    # if it's a mov with just base + disp and base == written register
                    # it's likely to be a ptr sur struct or array
                    if ctx_src_op.type == capstone.x86.X86_OP_MEM and\
                       ctx_src_op.mem.base == dest_op.reg:

                        # if disp != 0 it's certainly a struct ptr
                        if ctx_src_op.mem.segment == 0 and ctx_src_op.mem.disp != 0:
                            return _dynStruct.ptr_struct_str

                        # if disp == 0 and index != 0 it's certainly an array
                        if ctx_src_op.mem.segment == 0 and ctx_src_op.mem.index != 0:
                            return _dynStruct.ptr_array_str

                        # else it's a pointer with no more information
                        return _dynStruct.ptr_str

                # if the context instr have 2 operand and the second one use
                # the written ptr as base, it's ptr
                if (self.ctx_instr.operands) == 2 and\
                   self.ctx_instr.operands[1].type == capstone.x86.X86_OP_MEM and\
                   self.ctx_instr.operands[1].reg == ctx_src_op:
                    return _dynStruct.ptr_str

        return None

    @staticmethod
    def remove_instrs(access_list):
        for access in access_list:
            if hasattr(access, 'instr'):
                del access.instr
            if hasattr(access, 'ctx_instr'):
                del access.ctx_instr
