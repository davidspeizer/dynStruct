from java.lang import Runtime
from java.io import BufferedReader, InputStreamReader
import json
import os
import _dynStruct

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
if currentBinary:
    absPath = os.path.dirname(str(getSourceFile().getAbsolutePath()))

    script_path = os.path.join(absPath, "DynamoRIO-Linux-11.90.20236/bin64/drrun")
    output_file = os.path.join(absPath, "dynStruct_out")
    module_file = os.path.join(absPath, "dynStruct_out_modules")
    dynStruct_path = os.path.join(absPath, "dynStruct")

    if os.path.exists(output_file):
        os.remove(output_file)

    success = run_command([script_path, "-c", dynStruct_path, "-o", output_file, "--", currentBinary])

    if success and os.path.exists(output_file):
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
            load_json(json_data, modules, _dynStruct.l_block, _dynStruct.l_access_w, _dynStruct.l_access_r)
            print(len(_dynStruct.l_block))
            print("Recovering structures")
            _dynStruct.Struct.recover_all_struct(_dynStruct.l_block, _dynStruct.l_struct, monitor)
            print("Cleaning structures")
            _dynStruct.Struct.clean_all_struct(_dynStruct.l_struct)
            print("Printing structures")
            _dynStruct.print_to_console(_dynStruct.l_struct)
    else:
        print("Failed to run external script or output file not found.")
