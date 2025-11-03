import os
import sys
import traceback
import tempfile
import shutil
import re
import importlib # For dynamic imports
from typing import List, Optional, Tuple, Dict, Any, Callable
import subprocess # Needed for compile_program

# --- Import lftbench utilities ---
try:
    import json
    print("[Info] Importing json module for metadata parsing.")
except ImportError as e:
    print(f"[Error] Failed to import json module: {e}", file=sys.stderr)
    sys.exit(1)

# --- Helper: Compile C++ Code (Moved from abc330d/reducer.py) ---
def compile_program(source_path: str, output_path: str, work_dir: str) -> bool:
    """Compiles C++ source file using g++. Returns True on success, False on failure."""
    compile_command = [
        "g++",
        source_path, # Relative path within work_dir
        "-o",
        output_path, # Relative path within work_dir
        "-std=c++20", 
        "-O2",
    ]
    print(f"  [Compile] Running: {' '.join(compile_command)} in {work_dir}")
    try:
        result = subprocess.run(
            compile_command,
            capture_output=True,
            check=True, 
            text=True, 
            cwd=work_dir 
        )
        print(f"  [Compile] Success for {os.path.basename(source_path)}")
        return True
    except subprocess.CalledProcessError as e:
        print(f"  [Error] Compilation failed for {os.path.basename(source_path)} (Exit Code: {e.returncode}):", file=sys.stderr)
        print("--- Compiler Output (stderr) ---", file=sys.stderr)
        print(e.stderr, file=sys.stderr)
        print("---------------------------------", file=sys.stderr)
        return False
    except FileNotFoundError:
        print(f"  [Error] Compiler 'g++' not found. Make sure it's installed and in PATH.", file=sys.stderr)
        return False
    except Exception as e:
        print(f"  [Error] Unexpected error during compilation of {os.path.basename(source_path)}: {e}", file=sys.stderr)
        return False

# --- Helper function to parse problem ID ---
def _parse_problem_id(problem_id_input: str) -> Optional[Tuple[str, str]]:
    """Parses IDs like 'abc330d' or 'abc330_d' into (contest_id, problem_letter)."""
    match = re.match(r"^([a-z]+)(\d+)[_]?([a-z])$", problem_id_input.lower())
    if match:
        contest_id = match.group(1) + match.group(2) # e.g., "abc330"
        problem_letter = match.group(3).upper()      # e.g., "D"
        return contest_id, problem_letter
    else:
        print(f"[Error] Failed to parse problem_id_input: '{problem_id_input}'", file=sys.stderr)
        return None

# --- Helper: Get Failing Case Info (From lftbench metadata) --- 
def _get_failing_case_info(submission_id: str, 
                           problem_id: str
                           ) -> Dict[str, Any]:
    """
    Retrieves AC code, WA code, and original test input path from lftbench metadata.
    Args:
        submission_id: The submission ID to look up
        problem_id: The problem ID (e.g., 'abc361c')
    Returns:
        Dict with keys: ac_code, wa_code, original_input_path
    """
    print(f"[_get_failing_case_info] Loading submission {submission_id} for {problem_id} from lftbench metadata.")
    
    # Get script directory and construct lftbench path
    script_dir = os.path.dirname(os.path.abspath(__file__))
    lftbench_dir = os.path.join(script_dir, "lftbench")
    metadata_file = os.path.join(lftbench_dir, "metadata", "cpp_submissions.jsonl")
    
    # Check if metadata file exists
    if not os.path.exists(metadata_file):
        error_msg = f"Metadata file not found: {metadata_file}"
        print(f"  [Error] {error_msg}", file=sys.stderr)
        return {"status": "error", "message": error_msg, "status_code": 404}
    
    # Search for the submission in metadata
    submission_data = None
    try:
        with open(metadata_file, 'r', encoding='utf-8') as f:
            for line in f:
                data = json.loads(line)
                if data.get('problem_id') == problem_id and data.get('submission_id') == submission_id:
                    submission_data = data
                    break
    except Exception as e:
        error_msg = f"Error reading metadata file: {e}"
        print(f"  [Error] {error_msg}", file=sys.stderr)
        traceback.print_exc()
        return {"status": "error", "message": error_msg, "status_code": 500}
    
    if not submission_data:
        error_msg = f"Submission {submission_id} for problem {problem_id} not found in metadata"
        print(f"  [Error] {error_msg}", file=sys.stderr)
        return {"status": "error", "message": error_msg, "status_code": 404}
    
    print(f"  [Info] Found submission metadata in lftbench.")
    
    # Read AC code
    ac_code_content = None
    ac_code_rel_path = submission_data.get('ac_code_path')
    if ac_code_rel_path:
        ac_code_path = os.path.join(lftbench_dir, ac_code_rel_path)
        try:
            with open(ac_code_path, 'r', encoding='utf-8') as f:
                ac_code_content = f.read()
            print(f"  [Info] Successfully read AC code from {ac_code_rel_path}")
        except Exception as e:
            print(f"  [Warning] Failed to read AC code from {ac_code_path}: {e}", file=sys.stderr)
    
    # Read WA code
    wa_code_content = None
    wa_code_rel_path = submission_data.get('wa_code_path')
    if wa_code_rel_path:
        wa_code_path = os.path.join(lftbench_dir, wa_code_rel_path)
        try:
            with open(wa_code_path, 'r', encoding='utf-8') as f:
                wa_code_content = f.read()
            print(f"  [Info] Successfully read WA code from {wa_code_rel_path}")
        except Exception as e:
            error_msg = f"Failed to read WA code from {wa_code_path}: {e}"
            print(f"  [Error] {error_msg}", file=sys.stderr)
            return {"status": "error", "message": error_msg, "status_code": 500}
    else:
        error_msg = "WA code path not found in metadata"
        print(f"  [Error] {error_msg}", file=sys.stderr)
        return {"status": "error", "message": error_msg, "status_code": 500}
    
    # Get original test input path
    original_input_rel_path = submission_data.get('original_test_input_path')
    if not original_input_rel_path:
        error_msg = "Original test input path not found in metadata"
        print(f"  [Error] {error_msg}", file=sys.stderr)
        return {"status": "error", "message": error_msg, "status_code": 500}
    
    # Construct absolute path
    original_input_path = os.path.join(lftbench_dir, original_input_rel_path)
    if not os.path.exists(original_input_path):
        error_msg = f"Original test input file not found: {original_input_path}"
        print(f"  [Error] {error_msg}", file=sys.stderr)
        return {"status": "error", "message": error_msg, "status_code": 404}
    
    print(f"  [Info] Original test input path: {original_input_rel_path}")
    
    return {
        "ac_code": ac_code_content,
        "wa_code": wa_code_content,
        "original_input_path": original_input_path  # Return absolute path
    }

# _get_original_input_path() removed - now using paths from lftbench metadata

# --- Generic Test Case Reduction Runner (Moved from abc330d/reducer.py and Modified) ---
def reduce_test_case(ac_code_str: str, 
                     wa_code_str: str, 
                     original_input_str: str,
                     work_dir: str, 
                     problem_specific_reduce_input_func: Callable[[str, str], None],
                     reduced_input_filename: str = "reduced_input.txt"
                    ) -> Optional[str]:
    """
    Generic runner for the test case reduction process.
    - Writes AC/WA code and input to work_dir.
    - Compiles AC/WA code in work_dir using compile_program (in this file).
    - Changes CWD to work_dir.
    - Calls the provided problem_specific_reduce_input_func.
    - Changes CWD back.
    - Reads and returns the content of reduced_input.txt from work_dir.
    """
    original_cwd = os.getcwd()
    work_dir = os.path.abspath(work_dir)
    reduced_content = None
    
    try:
        # 1. Create work directory
        os.makedirs(work_dir, exist_ok=True)
        print(f"[Setup] Using working directory: {work_dir}")

        # 2. Define file paths 
        ac_src_path = os.path.join(work_dir, "ac.cpp")
        wa_src_path = os.path.join(work_dir, "wa.cpp")
        input_path = os.path.join(work_dir, "input.txt")
        reduced_output_path = os.path.join(work_dir, reduced_input_filename)
        # Note: compile_program creates ./ac and ./wa relative to work_dir

        # 3. Write source code and input
        try:
            with open(ac_src_path, "w", encoding="utf-8") as f: f.write(ac_code_str)
            with open(wa_src_path, "w", encoding="utf-8") as f: f.write(wa_code_str)
            with open(input_path, "w", encoding="utf-8") as f: f.write(original_input_str)
            print("[Setup] Source codes and input file written.")
        except IOError as e:
            print(f"[Error] Failed to write files to {work_dir}: {e}", file=sys.stderr)
            return None # Indicate failure

        # 4. Compile programs
        print("[Setup] Compiling AC program...")
        if not compile_program("ac.cpp", "ac", work_dir):
            return None
        print("[Setup] Compiling WA program...")
        if not compile_program("wa.cpp", "wa", work_dir):
            return None
        
        # 5. Perform the reduction by changing CWD and calling specific logic
        print(f"[Reduce] Changing working directory to: {work_dir}")
        os.chdir(work_dir)
        
        # Call the PROBLEM-SPECIFIC reduce_input function passed as argument
        # It assumes input is "input.txt" and output is "reduced_input.txt" in CWD
        print(f"[Reduce] Calling problem-specific reduce function: {problem_specific_reduce_input_func.__name__}")
        problem_specific_reduce_input_func(os.path.basename(input_path), os.path.basename(reduced_output_path))
        
        # 6. Read the result file (still in work_dir)
        if os.path.exists(reduced_output_path):
             try:
                 with open(reduced_output_path, "r", encoding="utf-8") as f:
                     reduced_content = f.read()
                 print(f"[Success] Reduction process finished. Read result from {os.path.basename(reduced_output_path)}")
             except IOError as e:
                 print(f"[Error] Failed to read reduced output file {os.path.basename(reduced_output_path)}: {e}", file=sys.stderr)
                 reduced_content = None # Ensure it's None on read error
        else:
             print(f"[Warning] Reduced output file '{os.path.basename(reduced_output_path)}' not found after reduction process.")
             # Attempt fallback to original input ONLY if specific reducer didn't create output
             try:
                  with open(input_path, "r", encoding="utf-8") as f:
                      reduced_content = f.read()
                  print(f"[Info] Returning original input content as fallback.")
             except IOError:
                  print(f"[Error] Could not read original input '{os.path.basename(input_path)}' either.", file=sys.stderr)
                  reduced_content = None

    except Exception as e:
        print(f"[Error] Exception during generic reduction process in {work_dir}: {e}", file=sys.stderr)
        traceback.print_exc() 
        reduced_content = None # Ensure None on error
    finally:
        # 7. IMPORTANT: Change back to the original directory
        if original_cwd != os.getcwd(): # Only change back if we changed it
             print(f"[Cleanup] Changing working directory back to: {original_cwd}")
             os.chdir(original_cwd)
        else:
             print("[Cleanup] Working directory was not changed, skipping chdir back.")

    return reduced_content

# --- Main Orchestration Function (Modified Return Value) ---
def reduce_submission(submission_id: str, problem_id_input: str, artifact_dir: Optional[str] = None) -> Tuple[int, str, Optional[int], Optional[int], Optional[str], Optional[str]]:
    """
    Orchestrates the test case reduction process for a given submission ID.
    Data is loaded from lftbench metadata instead of fetching from AtCoder.
    Args:
        submission_id: The ID of the submission to reduce.
        problem_id_input: The problem ID string (e.g., 'abc361c').
        artifact_dir: Optional path to a directory where original and reduced 
                      input files should be saved.
    Returns:
        A tuple: (status_code, message, original_size, reduced_size, reduced_content_str, failing_case_name)
    """
    original_input_size = None
    reduced_input_size = None
    reduced_content_str = None # Initialize reduced content
    failing_case_name = None # Initialize failing case name
    print(f"[Orchestrate] Received problem_id: '{problem_id_input}', submission_id: {submission_id}")
    parsed_ids = _parse_problem_id(problem_id_input)
    if not parsed_ids:
        return 400, f"Invalid problem ID format: {problem_id_input}", None, None, None, None # Added None for case_name
    contest_id, problem_letter = parsed_ids
    print(f"[Orchestrate] Parsed Problem: Contest={contest_id}, Problem={problem_letter}")

    # 1. Dynamically import the problem-specific reducer
    specific_reducer_module = None
    specific_reduce_input_func = None
    reducer_module_path = ""
    try:
        module_name = f"{contest_id}{problem_letter.lower()}.reducer"
        print(f"[Orchestrate] Attempting to dynamically import: {module_name}")
        specific_reducer_module = importlib.import_module(module_name)
        if not hasattr(specific_reducer_module, 'reduce_input'): raise AttributeError(f"Module '{module_name}' does not have 'reduce_input' function.")
        specific_reduce_input_func = getattr(specific_reducer_module, 'reduce_input')
        # Get the path of the imported module to read its content later
        if hasattr(specific_reducer_module, '__file__') and specific_reducer_module.__file__:
             reducer_module_path = specific_reducer_module.__file__
        print(f"[Orchestrate] Successfully imported reducer module and found reduce_input function for {contest_id}{problem_letter}.")
    except ModuleNotFoundError: return 404, f"Reducer module not found for problem '{contest_id}{problem_letter}'. Looked for '{module_name}.py'.", None, None, None, None # Added None
    except AttributeError as ae: return 500, str(ae), None, None, None, None # Added None
    except Exception as import_err: traceback.print_exc(); return 500, f"Failed to import reducer module '{module_name}': {import_err}", None, None, None, None # Added None

    # Read the reducer code content
    if reducer_module_path and os.path.exists(reducer_module_path):
        try:
            with open(reducer_module_path, 'r', encoding='utf-8') as f:
                reducer_code_content = f.read()
        except Exception as read_err:
            print(f"[Warning] Could not read reducer module source at {reducer_module_path}: {read_err}")
            reducer_code_content = f"# Error reading reducer source: {read_err}"
    else:
         reducer_code_content = "# Reducer source file path not found."

    # 2. Get Failing Case Info from lftbench metadata
    print(f"[Orchestrate] Loading submission info for {submission_id} from lftbench...")
    case_info = _get_failing_case_info(submission_id, problem_id_input)
    
    # Check for errors reported by the helper
    if case_info.get("status") == "error":
         return case_info["status_code"], case_info["message"], None, None, None, None
         
    # Retrieve data
    ac_code_str = case_info.get("ac_code")
    wa_code_str = case_info.get("wa_code")
    original_input_path = case_info.get("original_input_path")
    
    # Simplified check: If helper succeeded, wa_code and input path should exist
    if not wa_code_str or not original_input_path:
         error_msg = f"Internal error: _get_failing_case_info succeeded but returned invalid data for submission {submission_id}."
         print(f"[Error] {error_msg}", file=sys.stderr)
         return 500, error_msg, None, None, None, None
         
    # Check for AC code (optional)
    if ac_code_str is None:
        print(f"[Warning] Failed to read AC code from lftbench. Proceeding without it.")

    print(f"[Orchestrate] Loaded from lftbench: AC Code (len={len(ac_code_str) if ac_code_str else 0}), WA Code (len={len(wa_code_str)}), Input Path={original_input_path}")

    # Extract a simplified case name for logging/artifact purposes
    failing_case_name = os.path.basename(original_input_path).replace('.txt', '')

    # Now, read the content using the validated path
    try:
        original_input_size = os.path.getsize(original_input_path) # Should work now
        with open(original_input_path, 'r', encoding='utf-8') as f_orig:
             original_input_content_str = f_orig.read()
             print(f"[Orchestrate] Original input read. Size: {original_input_size} bytes. Content length: {len(original_input_content_str)}")

        # 3.5 Copy original input to artifact_dir if specified
        if artifact_dir:
            original_artifact_path = os.path.join(artifact_dir, "original_input.txt")
            try:
                shutil.copy2(original_input_path, original_artifact_path)
                print(f"[Orchestrate] Copied original input to {original_artifact_path}")
            except Exception as e_copy:
                 print(f"[Warning] Failed to copy original input to artifact dir {artifact_dir}: {e_copy}", file=sys.stderr)

        # 4. Create Temporary Directory & Run Reduction
        work_dir = tempfile.mkdtemp(prefix=f"reduce_{contest_id}{problem_letter}_")
        print(f"[Orchestrate] Created temporary working directory: {work_dir}")
        try:
            # Call the generic runner, ensuring correct keyword arguments
            reduced_content_str = reduce_test_case(
                work_dir=work_dir,
                ac_code_str=ac_code_str, # Ensure this matches definition
                wa_code_str=wa_code_str, # Ensure this matches definition
                original_input_str=original_input_content_str, # Pass the CONTENT string
                problem_specific_reduce_input_func=specific_reduce_input_func,
                reduced_input_filename="reduced_input.txt"
            )
            
            # Read the reduced input content from the temp dir after run
            reduced_input_path = os.path.join(work_dir, "reduced_input.txt") # Define path for reading
            if os.path.exists(reduced_input_path):
                with open(reduced_input_path, "r", encoding="utf-8") as f_reduced:
                    reduced_content_str = f_reduced.read()
                # Calculate stats for reduced input
                reduced_input_size = len(reduced_content_str.encode('utf-8'))
                print(f"[Orchestrate] Reduced Input Read: {reduced_input_size} bytes")
                
                # 4.5 Copy reduced input to artifact_dir if specified
                if artifact_dir:
                    reduced_artifact_path = os.path.join(artifact_dir, "reduced_input.txt")
                    try:
                        shutil.copy2(reduced_input_path, reduced_artifact_path)
                        print(f"[Orchestrate] Copied reduced input to {reduced_artifact_path}")
                    except Exception as e_copy:
                         print(f"[Warning] Failed to copy reduced input to artifact dir {artifact_dir}: {e_copy}", file=sys.stderr)

                # Return success with all information, including failing_case_name
                return 200, "Reduction completed successfully.", original_input_size, reduced_input_size, reduced_content_str, failing_case_name # Added case_name
            else:
                # Handle case where reduced file wasn't created
                print(f"[Error] Reduction process seemed to complete, but reduced output file '{reduced_input_path}' was not found.", file=sys.stderr)
                # Ensure return tuple matches expected length, even on error
                if os.path.exists(os.path.join(work_dir, "input.txt")):
                     return 500, "Reduction process seemed to complete, but reduced output file was not created.", original_input_size, None, None, failing_case_name # Added case_name
                else:
                     return 500, "Reduction failed. Reduced output file missing and original input potentially lost in temp dir.", original_input_size, None, None, failing_case_name # Added case_name

        except subprocess.CalledProcessError as cpe:
            error_output = cpe.stderr.decode('utf-8', errors='ignore') if cpe.stderr else "(No stderr)"
            error_stdout = cpe.stdout.decode('utf-8', errors='ignore') if cpe.stdout else "(No stdout)"
            error_message = f"Compilation/Runtime Error during reduction: {cpe}. Stdout: {error_stdout}. Stderr: {error_output}"
            print(f"[Error] {error_message}", file=sys.stderr)
            return 500, error_message, original_input_size, None, None, failing_case_name # Added case_name
        except TimeoutError as te:
            error_message = f"Timeout Error during reduction: {te}"
            print(f"[Error] {error_message}", file=sys.stderr)
            return 500, error_message, original_input_size, None, None, failing_case_name # Added case_name
        except Exception as e:
            error_message = f"Unexpected Error during reduction:"
            print(f"[Critical] {error_message}", file=sys.stderr)
            traceback.print_exc()
            return 500, error_message, original_input_size, None, None, failing_case_name # Added case_name
        finally:
            # 6. Cleanup Temporary Directory
            if os.path.exists(work_dir):
                try:
                    shutil.rmtree(work_dir)
                    print(f"[Orchestrate] Cleaned up temporary directory: {work_dir}")
                except Exception as cleanup_err:
                    print(f"[Warning] Failed to clean up temporary directory {work_dir}: {cleanup_err}", file=sys.stderr)

    except IOError as e:
        return 500, f"Error reading original input file {original_input_path}: {e}", original_input_size, None, None, failing_case_name # Added case_name
    except Exception as e: # Catch other potential errors like permission issues after existence check
        return 500, f"Error processing original input file {original_input_path}: {e}", None, None, None, failing_case_name # Added case_name

# --- Example Usage (Optional - if you want to test this root reducer directly) ---
if __name__ == "__main__":
    print("Testing root reduce.py orchestration...")
    # Example call parameters
    test_problem_id = "abc361c" 
    test_submission_id = "67213592" # Example ID
    
    print(f"Running reduction for Problem: {test_problem_id}, Submission: {test_submission_id}")
    print("Note: Data will be loaded from lftbench metadata")
    
    # Call with updated signature (no base_testcase_path)
    result = reduce_submission(test_submission_id, test_problem_id, artifact_dir=None)
    
    print("\n--- Orchestration Result ---")
    if result[0] == 200:
        print(f"Status: Success")
        print(f"Message: {result[1]}")
        print(f"Original Size: {result[2]} bytes")
        print(f"Reduced Size: {result[3]} bytes")
        print(f"Reduced Content:\n{result[4]}") # Print content in test
        print(f"Failing Case: {result[5]}")
    else:
        print(f"Status: Error")
        print(f"Message: {result[1]}")
        print(f"Status Code: {result[0]}")
    print("---------------------------") 