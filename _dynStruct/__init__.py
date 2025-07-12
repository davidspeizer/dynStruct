from .access import Access
from .block import Block
from .struct import Struct
from .save import print_to_file
from .save import get_header
from .processing import paging
from .processing import filter_block
from .processing import filter_access
from .processing import sorting_block
from .processing import sorting_access

bits = 0

l_struct = []
l_block = []
l_access_w = []
l_access_r = []
serialized_file = ""

ptr_func_str = 'void(*%s)()'
ptr_struct_str = 'void * // pointer to structure'
ptr_array_str = 'void * // pointer to array'
ptr_str = 'void *'
double_str = 'double'
float_str = 'float'
unsigned_str = 'uint%d_t'
