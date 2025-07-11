from . import Access

class Block:


    def __init__(self, block, modules, l_access_w, l_access_r, id_block, program):
        print("Initializing block")
        self.struct = None
        self.id_block = id_block
        self.program = program
        
        cast_attr = {"free_by_realloc" : bool,
                     "alloc_by_realloc" : bool,
                     "free" : bool}
        json_attrib = ["start", "end", "size", "free", "alloc_by_realloc",
                       "free_by_realloc", "alloc_pc", "alloc_func", "alloc_sym",
                       "alloc_module", "free_pc", "free_func", "free_sym",
                       "free_module"]

        for k in json_attrib:
            setattr(self, k, cast_attr.get(k, block[k].__class__)(block[k]))

        for name, address in modules:
            if address <= self.start:
                result = (name, address)
            else:
                break
        
        print("allocation is at " + hex(self.alloc_pc) + ". This is in module " + result[0] + " which starts at " + hex(result[1]))
        print("Offset is therefore " + hex(self.alloc_pc - result[1]))
        self.moduleStart = result[1]
            
        self.r_access = []
        self.w_access = []

        for access in filter(None, block["read_access"]):
            # This goes through every time that the allocated block is accessed for reading
            for orig in filter(None, access["details"]):
                self.r_access.append(Access(access["offset"], orig, result[1], self.start, self, 'read'))
                l_access_r.append(self.r_access[-1])
            
        for access in filter(None, block["write_access"]):
            # This goes through every time that the allocated block is accessed for writing
                for orig in filter(None, access["details"]):
                    self.w_access.append(Access(access["offset"], orig, result[1], self.start, self, 'write'))
                    l_access_w.append(self.w_access[-1])

        Access.remove_instrs(self.r_access + self.w_access)

    def get_access_by_offset(self, offset):
        ret = []
   #     print(str(len(self.r_access)) + " read accesses and " + str(len(self.w_access)) + " write acceses.")
 #       print(self.w_access[0].instr.toString())
        for access in self.r_access + self.w_access:
            if access.is_offset(offset):
                ret.append(access)

        return ret

    def get_access_by_range(self, start, end):
        r_access = []
        w_access = []

        for access in self.r_access:
            if access.is_in_range(start, end):
                r_access.append(access)
        for access in self.w_access:
            if access.is_in_range(start, end):
                w_access.append(access)

        return (r_access, w_access)
