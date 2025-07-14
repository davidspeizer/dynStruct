# Run the program under DynamoRIO instrumentation to automatically infer structures
# @category Analysis

from java.lang import Runtime, String, System, Runnable
from java.io import BufferedReader, InputStreamReader, File
import jarray
import json
import os
import _dynStruct
from ghidra.app.util.cparser.C import CParserUtils
from ghidra.app.decompiler import DecompInterface
from ghidra.program.model.pcode import HighFunctionDBUtil, PcodeOp
from ghidra.program.model.data import PointerDataType
from ghidra.program.model.symbol import SourceType
from docking.widgets.filechooser import GhidraFileChooser

from java.lang import Thread
from java.io import BufferedReader, InputStreamReader

# Define a class here to help run external programs and manage stdout/stderr prints.
# Doing this mostly with Java syntax rather than python because that seems to work better.
class StreamReader(Runnable):
    def __init__(self, stream, prefix):
        self.stream = stream
        self.prefix = prefix
    
    def run(self):
        reader = BufferedReader(InputStreamReader(self.stream))
        try:
            while True:
                line = reader.readLine()
                if line is None:
                    break
                print(self.prefix, line)
        except:
            pass  # Stream closed
        finally:
            reader.close()

def run_command(command, env_vars=None, working_dir=None):
    try:
        print("Running command:", command)
        if working_dir:
            print("Working directory:", working_dir)
        
        if env_vars:
            # Get current environment and add/override with provided vars
            current_env = System.getenv()
            env_list = []
            
            # Add existing environment variables
            for key in current_env.keySet():
                env_list.append(str(key) + "=" + str(current_env.get(key)))
            
            # Add/override with provided environment variables
            for key, value in env_vars.items():
                env_list.append(str(key) + "=" + str(value))
            
            # Convert to Java array
            env_java_array = jarray.array(env_list, String)
            
            if working_dir:
                process = Runtime.getRuntime().exec(command, env_java_array, File(working_dir))
            else:
                process = Runtime.getRuntime().exec(command, env_java_array)
        else:
            if working_dir:
                process = Runtime.getRuntime().exec(command, None, File(working_dir))
            else:
                process = Runtime.getRuntime().exec(command)
        
        # Rest of the function stays the same...
        stdout_reader = StreamReader(process.getInputStream(), "STDOUT:")
        stderr_reader = StreamReader(process.getErrorStream(), "STDERR:")
        
        stdout_thread = Thread(stdout_reader)
        stderr_thread = Thread(stderr_reader)
        
        stdout_thread.start()
        stderr_thread.start()
        
        exit_code = process.waitFor()
        stdout_thread.join()
        stderr_thread.join()
        
        print("Exit code:", exit_code)
        return exit_code == 0
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

def update_ghidra_decomp(addr, structPtrType):
    func = getFunctionContaining(addr)
    # Load the decomp of the alloc-ing function
    res = iface.decompileFunction(func, 60, monitor)
    if res.decompileCompleted() == False:
        print("Failed to decompile alloc-ing function at " + addr.toString())
        return False

    # Get Ghidra's version of the function.
    highFunc = res.getHighFunction()
    if highFunc is None:
        print("Decompilation did not produce a HighFunction at " + addr.toString())
        return False

    # Get the list of pcode ops that Ghidra has for this function.
    # We step through the ops until we see the CALL that sets our variable.
    # We then keep stepping until we see the COPY or CAST that moves the result into a destination register.
    # It is this destination register that we want to change.
    pcodeOps = highFunc.getPcodeOps()
    callOutput = None
    varnode = None
    while pcodeOps.hasNext():
        op = pcodeOps.next()
        if op.getOpcode() == PcodeOp.CALL and op.getSeqnum().getTarget() == addr:
            callOutput = op.getOutput()
            break
    if callOutput is None:
        print("Could not get callOutput for alloc at " + addr.toString())
        return False

    while pcodeOps.hasNext():
        op = pcodeOps.next()
        if op.getOpcode() == PcodeOp.COPY or op.getOpcode() == PcodeOp.CAST:
            if op.getInput(0).equals(callOutput):
                varnode = op.getOutput()
    if varnode is None:
        print("Could not get varnode for alloc at " + addr.toString())
        return False

    # Now that we have the destination register, we get the HighSymbol for that register.
    # This is Ghidra's internal representation of the register, and this is what we want to change to our struct*.
    highVar = varnode.getHigh()
    highSym = None
    if highVar is not None:
        highSym = highVar.getSymbol()

    # The decompilation might be such that the symbol can't be found from the pcode ops.
    # If that's the case, then check the existing symbol table for the proper address.
    if highSym is None:
        syms = highFunc.getLocalSymbolMap().getSymbols()
        while syms.hasNext():
            sym = syms.next()
            if sym.getPCAddress() == addr:
                highSym = sym
                break

    # We shouldn't ever get here, but sometimes things go wrong.
    if highSym is None:
        print("Could not find HighSymbol for alloc at " + addr.toString())
        return False

    # Edit the decompilation to change the variable
    HighFunctionDBUtil.updateDBVariable(highSym, highSym.getName(), structPtrType, SourceType.USER_DEFINED)
    print("Changed data type at " + addr.toString())
    return True

# === Main Script ===

currentBinary = currentProgram.getExecutablePath()
dtm = currentProgram.getDataTypeManager()
iface = DecompInterface()
iface.openProgram(currentProgram)

if currentBinary is None:
    print("Could not find executable for program under test")
    exit()

programSize = currentProgram.getAddressFactory().getDefaultAddressSpace().getSize()

absPath = os.path.dirname(str(getSourceFile().getAbsolutePath()))

# Prepare the output files for our DynamoRIO run.
output_file = os.path.join(absPath, "dynStruct_out")
module_file = os.path.join(absPath, "dynStruct_out_modules")
header_file = os.path.join(absPath, "dynStructs.h")
dynStruct_path = os.path.join(absPath, "dynStruct")

# Get the DynamoRIO directory from the user
fileChooser = GhidraFileChooser(None)
fileChooser.setTitle("Select the DynamoRIO home folder")
fileChooser.setApproveButtonText("Select")
fileChooser.setFileSelectionMode(GhidraFileChooser.DIRECTORIES_ONLY)
dynamoRioHome = fileChooser.getSelectedFile().getAbsolutePath()
script_path = os.path.join(dynamoRioHome, "bin" + str(programSize), "drrun")

# If dynStruct has not been built yet, do that.
if not os.path.exists(dynStruct_path):
    print("Building dynStruct module in DynamoRIO...")
    build_file = os.path.join(absPath, "build.sh")
    build_args = [build_file]
    if programSize == 32:
        build_args.append("32")
    try:
        result = run_command(build_args, {"DYNAMORIO_HOME": dynamoRioHome}, absPath)
    except Exception as e:
        print("Error building dynStruct:", e)
    if result == False or not os.path.exists(dynStruct_path):
        print("Build failed. Exiting.")
        exit()

if os.path.exists(output_file):
    os.remove(output_file)

programArgs = ""
if askYesNo("Need Args", "Do you want to enter any arguments to run with " + currentBinary + "?"):
    programArgs = askString("Program Args", "Arguments:", "")

command = [script_path, "-c", dynStruct_path, "-o", output_file, "--", currentBinary] + programArgs.split()

# Run the program under DynamoRIO instrumentation
print("Running program under DynamoRIO instrumentation...\n")
success = run_command(command)

if success and os.path.exists(output_file):
    # Open the JSON information on our allocated blocks and our module base addresses
    json_data = open_json(output_file)
    jsonModules = open_json(module_file)

    # Load the base addresses of all our modules and sort them.
    modules = [ (name, address) for mod in jsonModules["modules"] for name, address in mod.items()]
    modules.sort(key=lambda x: x[1])
    if json_data is None:
        print("Failed to load JSON from dynamoRIO")
    else:
        print("\nProgram successfully run. Loading JSON...")
        # Analyze the JSON output and save off the blocks
        load_json(json_data, modules, _dynStruct.l_block, _dynStruct.l_access_w, _dynStruct.l_access_r)
        print("Recovering structures...")

        # Generate structures from the blocks
        _dynStruct.Struct.recover_all_struct(_dynStruct.l_block, _dynStruct.l_struct, monitor)

        ### Uncomment for debugging purposes
        # for s in _dynStruct.l_struct:
        #    print(str(s))
        ###

        print("Found " + str(len(_dynStruct.l_struct)) + " structures. Cleaning structures...")
        # Clean up the structures, eliminating arrays from the list.
        _dynStruct.Struct.clean_all_struct(_dynStruct.l_struct)

        if len(_dynStruct.l_struct) == 0:
            print("No structures found. Exiting.")
            exit()

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
            structType = dtm.getDataType(dtm.getName() + "/dynStructs.h/" + struct.name)
            if structType is None:
                print("Could not find struct type " + struct.name)
                exit()
            structPtr = PointerDataType(structType)

            # Third, find every place the struct is allocated and edit the decompilation there.
            for alloc in allocs:
                addr = toAddr(alloc)
                if update_ghidra_decomp(addr, structPtr) == False:
                    # Stop execution if we encountered an error
                    exit()
                
    os.remove(output_file)
else:
    print("Failed to run external script or output file not found.")

# Cleanup
os.remove(header_file)
os.remove(module_file)