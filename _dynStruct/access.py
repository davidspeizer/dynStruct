import binascii
import _dynStruct
from ghidra.program.model.lang import Register
from ghidra.program.model.scalar import Scalar
from ghidra.program.model.lang import OperandType
from ghidra.program.model.data import (
    ByteDataType,
    UnsignedShortDataType,
    UnsignedInteger3DataType,
    UnsignedIntegerDataType,
    UnsignedInteger5DataType,
    UnsignedInteger6DataType,
    UnsignedInteger7DataType,
    UnsignedLongDataType,
    UnsignedInteger16DataType,
    FloatDataType
)

unsigned_int_mnemonics = ["ADCX", "ADOX", "DIV", "MUL", "MULX"]

class Access:

    def __init__(self, access, orig, module_start, addr_start, block, t):
        self.block = block
        self.offset = access
        self.addr = addr_start + self.offset
        self.size = orig["size_access"]
        self.t = t
        self.listing = block.program.getListing()

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

        print("Module addr: " + hex(module_start))

        self.pc = self.pc - module_start + block.program.getImageBase().getOffset()
        self.ctx_addr = self.ctx_addr - module_start + block.program.getImageBase().getOffset()

        self.disass()

     #   self.instr_display = '<span class="text-success"><strong>%s</strong>\
      #  </span><span class="text-info">%s</span>' % (self.instr.mnemonic,
      #                                               self.instr.op_str)
        self.instr_search = '%s' % (self.instr.toString())
        if self.ctx_opcode:
        #   if self.ctx_addr > self.pc:
        #        self.ctx_instr_display = "Next : "
        #    else:
        #        self.ctx_instr_display = "Prev : "
        #    self.ctx_instr_display += '<span class="text-success"><strong>%s</strong>\
        #    </span><span class="text-info">%s</span>' % (self.ctx_instr.mnemonic,
        #                                                 self.ctx_instr.op_str)
            self.ctx_instr_search = '%s' % (self.ctx_instr.toString())
        else:
            self.ctx_instr_search = 'No context'
         #   self.ctx_instr_display = '<span class="text-danger">No context</span>'

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
       # print("Calling disass with pc=0x{:x}, ctx_addr=0x{:x}".format(self.pc, self.ctx_addr))

        pc_addr = self.block.program.getAddressFactory().getDefaultAddressSpace().getAddress(self.pc)
        ctx_addr = self.block.program.getAddressFactory().getDefaultAddressSpace().getAddress(self.ctx_addr)

        if not hasattr(self, 'instr'):
            self.instr = self.listing.getInstructionAt(pc_addr)
         #   print("Instruction: " + self.instr.toString())
            if self.ctx_opcode:
                self.ctx_instr = self.listing.getInstructionAt(ctx_addr)
             #   print("Context instruction: " + self.ctx_instr.toString())

    def analyze_ctx(self, size):
        if not hasattr(self, 'instr'):
            self.disass()
            
        if self.t == 'write':
            # Detect if the written val is the result from a floating point register
            if self.instr.getMnemonicString().startswith("MOV"):
                src_op = self.instr.getRegister(1)
                if src_op is not None and src_op.getName().startswith("xmm"):
                    if size == 4:
                        return FloatDataType.dataType
                    elif size == 8:
                        return _dynStruct.double_str
                    else:
                        return None
                elif self.ctx_opcode and self.ctx_instr.getMnemonicString().startswith("MOV"):
                    # Check if the context was a MOV instruction that is being read by our current instruction.
                    dest_ctx_reg = self.ctx_instr.getRegister(0)
                    src_ctx_op = self.ctx_instr.getRegister(1)
                    if dest_ctx_reg is not None and self.instr.getRegister(1) == dest_ctx_reg:
                        if src_ctx_op is not None and src_ctx_op.getName().startswith("xmm"):
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
                    # If the pointer is on the same memory pages as RIP/EIP, then it's a function pointer
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
                    # If not, it's just a pointer because we can't have more information.
                    return _dynStruct.ptr_str

            # If the move is an immediate value on the same page as RIP, then it's a function pointer.
            if self.instr.getMnemonicString().startswith("MOV") and \
                self.instr.getOperandType(1) == OperandType.IMMEDIATE and \
                size == _dynStruct.bits / 8:
                op_objs = self.instr.getOpObjects(1)
                imm = None
                for obj in op_objs:
                    if isinstance(obj, Scalar):
                        imm = obj.getValue()
                if imm is None:
                    return                
                if int(self.instr.getAddress() / 4096) == int(imm / 4096):
                    return _dynStruct.ptr_func_str

            # Detect if signed or unsigned
            if self.ctx_instr.getMnemonicString().startswith("MOV") and \
                self.ctx_instr.getNumOperands() == 2:
                destReg = self.ctx_instr.getRegister(0)
                srcReg = self.instr.getRegister(1)
                if destReg is not None and srcReg is not None and destReg == srcReg:
                    if self.instr.getMnemonicString() in unsigned_int_mnemonics:
                        if size == 1:
                            return ByteDataType.dataType
                        elif size == 2:
                            return UnsignedShortDataType.dataType
                        elif size == 3:
                            return UnsignedInteger3DataType.dataType
                        elif size == 4:
                            return UnsignedIntegerDataType.dataType
                        elif size == 5:
                            return UnsignedInteger5DataType.dataType
                        elif size == 6:
                            return UnsignedInteger6DataType.dataType
                        elif size == 7:
                            return UnsignedInteger7DataType.dataType
                        elif size == 8:
                            return UnsignedLongDataType.dataType
                        elif size == 16:
                            return UnsignedInteger16DataType.dataType
                        return None

        # For read access we can only detect ptr because a use of the value read
        # Basically member is pointer if the value read is dereferenced
        else:
            if self.instr.getMnemonicString() == "CALL":
                return _dynStruct.ptr_func_str
            if not self.ctx_instr:
                return None
            if not self.instr.getMnemonicString().startswith("MOV"):
                return None
            # If the value is used later (not just copied), the value is loaded into a register.
            dest_reg = self.instr.getRegister(0)
            if dest_reg is not None:
                # Check if the value is a floating point.
                if dest_reg.getName().startswith("xmm"):
                    if size == 4:
                        return _dynStruct.float_str
                    elif size == 8:
                        return _dynStruct.double_str
                    else:
                        return None
                # If the context instruction is a call that uses the previous register, the value is a function pointer.
                if self.ctx_instr.getMnemonicString() == "CALL":
                    ctx_reg = self.ctx_instr.getRegister(0)
                    if ctx_reg is not None and ctx_reg == dest_reg:
                        return _dynStruct.ptr_func_str

                # If the context instruction is a mov with base+disp and base is the written register,
                # then it's likely a struct pointer or an array.
                for i in range(self.ctx_instr.getNumOperands()):
                    op_objs = self.ctx_instr.getOpObjects(i)
                    memBase = None
                    hasIndexReg = False
                    hasSegmentReg = False
                    memDisp = None
                    for obj in op_objs:
                        # If we have 
                        if isinstance(obj, Register):
                            if len(obj.getName()) == 2 and obj.getName()[1] == 'S':
                                hasSegmentReg = True
                            if memBase is None:
                                memBase = obj
                            else:
                                hasIndexReg = True
                        elif isinstance(obj, Scalar):
                            memDisp = obj
                    if memBase == dest_reg:
                        if not hasSegmentReg and memDisp != 0:
                            return _dynStruct.ptr_struct_str
                        if not hasSegmentReg and hasIndexReg:
                            return _dynStruct.ptr_array_str
                        # Otherwise it's a pointer with no more information
                        return _dynStruct.ptr_str
                
                # if the context instr have 2 operand and the second one use
                # the written ptr as base, it's ptr
                # This will never execute. I'll leave it commented out here for now and come back to it if I determine it to be necessary.
               # if (self.ctx_instr.operands) == 2 and\
               #    self.ctx_instr.operands[1].type == capstone.x86.X86_OP_MEM and\
               #    self.ctx_instr.operands[1].reg == ctx_src_op:
               #     return _dynStruct.ptr_str

        return None

    @staticmethod
    def remove_instrs(access_list):
        for access in access_list:
            if hasattr(access, 'instr'):
                del access.instr
            if hasattr(access, 'ctx_instr'):
                del access.ctx_instr
