from java.lang import Runtime
from java.io import BufferedReader, InputStreamReader
import json
import os
import _dynStruct
from ghidra.app.util.cparser.C import CParserUtils
from ghidra.app.decompiler import DecompInterface
from ghidra.program.model.pcode import HighFunctionDBUtil
from ghidra.program.model.data import PointerDataType
from ghidra.program.model.pcode import PcodeOp
from ghidra.program.model.symbol import SourceType

def run_command(command):
    try:
        print("Running command:", command)
        process = Runtime.getRuntime().exec(command)
        reader = BufferedReader(InputStreamReader(process.getInputStream()))
        while True:
            line = reader.readLine()
            if line is None:
                break
            print(line)
        process.waitFor()
        return process.exitValue() == 0
    except Exception as e:
        print("Error running command:", e)
        return False

def open_json(path):
    try:
        with open(path, 'r') as f:
            return json.load(f)
    except Exception as e:
        print("Error reading JSON:", e)
        return None
    
def load_json(json_data, modules, l_block, l_access_w, l_access_r):
    id_block = 0

    if json_data["is_64"] == 1:
        _dynStruct.bits = 64
    else:
        _dynStruct.bits = 32
    try:
        monitor.initialize(len(json_data["blocks"]))
        monitor.setMessage("Loading JSON data")
        for block in filter(None, json_data["blocks"]):
            if monitor.isCancelled():
                break
            l_block.append(_dynStruct.Block(
                block, modules, l_access_w, l_access_r, id_block, currentProgram))
            id_block += 1
            monitor.incrementProgress(1)
    except KeyError as e:
        print("Json not from dynamoRIO client, missing : %s" % str(e))
        return False
    return True

# === Main Script ===

currentBinary = currentProgram.getExecutablePath()
dtm = currentProgram.getDataTypeManager()
iface = DecompInterface()
iface.openProgram(currentProgram)
if currentBinary:
    absPath = os.path.dirname(str(getSourceFile().getAbsolutePath()))

    # Prepare the output files for our DynamoRIO run.
    script_path = os.path.join(absPath, "DynamoRIO-Linux-11.90.20236/bin64/drrun")
    output_file = os.path.join(absPath, "dynStruct_out")
    module_file = os.path.join(absPath, "dynStruct_out_modules")
    header_file = os.path.join(absPath, "structs.h")
    dynStruct_path = os.path.join(absPath, "dynStruct")

    if os.path.exists(output_file):
        os.remove(output_file)

    # Run the program under DynamoRIO instrumentation
    success = run_command([script_path, "-c", dynStruct_path, "-o", output_file, "--", currentBinary])

    if success and os.path.exists(output_file):
        # Open the JSON information on our allocated blocks and our module base addresses
        json_data = open_json(output_file)
        jsonModules = open_json(module_file)

        # Load the base addresses of all our modules and sort them.
        modules = [ (name, address) for mod in jsonModules["modules"] for name, address in mod.items()]
        modules.sort(key=lambda x: x[1])
        print(modules)
        if json_data is None:
            print("Failed to load JSON from dynamoRIO")
        else:
            print("Loading JSON")
            # Analyze the JSON output and save off the blocks
            load_json(json_data, modules, _dynStruct.l_block, _dynStruct.l_access_w, _dynStruct.l_access_r)
            print(len(_dynStruct.l_block))
            print("Recovering structures")
            # Generate structures from the blocks
            _dynStruct.Struct.recover_all_struct(_dynStruct.l_block, _dynStruct.l_struct, monitor)
            print("Cleaning structures")
            # Clean up the structures, eliminating arrays from the list.
            _dynStruct.Struct.clean_all_struct(_dynStruct.l_struct)

            # Import the structures into Ghidra.
            # Right now we're creating the structures as a header file and then importing that header file.
            # But it would be more efficient and probably more correct to do this directly with Ghidra instead.
            # Add that to the wish-list.
            print("Importing structures into Ghidra")
            _dynStruct.print_to_file(header_file, _dynStruct.l_struct)
            dataTypeManagers = state.getTool().getService(ghidra.app.services.DataTypeManagerService).getDataTypeManagers()
            results = CParserUtils.parseHeaderFiles(dataTypeManagers, [header_file], [], dtm, monitor)
            if results.successful() is False:
                print("Failed to import structs into Ghidra")
                exit()

            for struct in _dynStruct.l_struct:
                # First, get a list of all the allocations of the struct
                allocs = []
                for block in struct.blocks:
                    offset = block.allocOffset + currentProgram.getMinAddress().getOffset()
                    if offset not in allocs:
                        allocs.append(offset)
                        print(struct.name + ": " + hex(offset))
                        
                # Second, get a pointer to the struct
                structType = dtm.getDataType(dtm.getName() + "/structs.h/" + struct.name)
                if structType is None:
                    print("Could not find struct type " + struct.name)
                    exit()
                structPtr = PointerDataType(structType)

                # Third, find every place the struct is allocated and edit the decompilation there.
                for alloc in allocs:
                    addr = toAddr(alloc)
                    func = getFunctionContaining(addr)
                    # Load the decomp of the alloc-ing function
                    res = iface.decompileFunction(func, 60, monitor)
                    if res.decompileCompleted() == False:
                        print("Failed to decompile alloc-ing function at " + addr.toString())
                        exit()

                    highFunc = res.getHighFunction()
                    if highFunc is None:
                        print("Decompilation did not produce a HighFunction at " + addr.toString())
                        exit()

                    pcodeOps = highFunc.getPcodeOps()
                    varnode = None
                    while pcodeOps.hasNext():
                        op = pcodeOps.next()
                        if op.getOpcode() == PcodeOp.CALL and op.getSeqnum().getTarget() == addr:
                            varnode = op.getOutput()
                            break
                    if varnode is None:
                        print("Could not get varnode for alloc at " + addr.toString())
                        exit()

                    highVar = varnode.getHigh()
                    if highVar is None:
                        print("Could not get HighVariable for alloc at " + addr.toString())
                        exit()

                    highSym = highVar.getSymbol()
                    if highSym is None:
                        print("Could not get HighSymbol for alloc at " + addr.toString())
                        continue

                    # Edit the decompilation to change the variable
                    HighFunctionDBUtil.updateDBVariable(highSym, highVar.getName(), structPtr, SourceType.USER_DEFINED)
                    print("Changed data type at " + addr.toString())
            
            os.remove(header_file)
    else:
        print("Failed to run external script or output file not found.")
