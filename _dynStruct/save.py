import pickle
import _dynStruct

def get_header(l_struct):
    if len(l_struct) == 0:
        return "No structure found"
    s = ""
    for struct in l_struct:
        s += str(struct) + "\n"
    return s

def print_to_file(filename, l_struct):
    s = get_header(l_struct)
    with open(filename, "w") as f:
        f.write(s)