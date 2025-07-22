import os
import sys
import traceback
import tempfile
import shutil
import re
import importlib # For dynamic imports
from typing import List, Optional, Tuple, Dict, Any, Callable
import subprocess # Needed for compile_program

# --- Import AtCoder tools --- 
try:
    import tools
    from tools import load_session # Import the unified session loader
    print("[Info] Successfully imported tools module and load_session.")
except ImportError:
    print("[Error] Failed to import 'tools' module. Make sure tools.py is in the Python path.", file=sys.stderr)
    tools = None # Set to None to indicate failure
except Exception as e:
    print(f"[Error] Unexpected error importing 'tools' module: {e}", file=sys.stderr)
    traceback.print_exc()
    tools = None

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

# --- Helper: Get Failing Case Info (Using tools.py) --- 
def _get_failing_case_info(submission_id: str, 
                           problem_dir_name: str, 
                           contest_id: str # Needed for URL
                           ) -> Dict[str, Any]: # Return Any to allow status key
    """
    Retrieves AC code from local file, and WA code + failing case name 
    from AtCoder submission page using the tools module.
    Uses a session loaded via tools.load_session() which handles cookie rotation.
    """
    print(f"[_get_failing_case_info] Fetching submission {submission_id} for {contest_id} using rotated cookie session.")
    
    if not tools:
         return {"status": "error", "message": "Tools module failed to import.", "status_code": 500}

    # Get the session using the new unified function
    session = tools.load_session()
    if not session:
         # Error if session loading failed (e.g., no cookies, load error)
         # tools.load_session() already prints specific errors
         error_msg = "Failed to obtain authenticated session via tools.load_session(). Check previous log messages."
         print(f"  [Error] {error_msg}", file=sys.stderr)
         return {"status": "error", "message": error_msg, "status_code": 500} # Use 500 for session issues

    # --- Read AC Code from local file --- 
    ac_code_content = None
    ac_code_path = os.path.join(problem_dir_name, "ac.cpp") 
    try:
        if not os.path.exists(ac_code_path):
            print(f"  [Error] AC code file not found at relative path: {ac_code_path}", file=sys.stderr)
            # Decide if this is fatal or just a warning if AC code isn't strictly needed later
        else:
            with open(ac_code_path, "r", encoding="utf-8") as f:
                ac_code_content = f.read()
            print(f"  [Info] Successfully read local AC code from {ac_code_path}.")
    except Exception as e:
        print(f"  [Error] Failed to read local AC code file {ac_code_path}: {e}", file=sys.stderr)
        ac_code_content = None 
        
    # --- Fetch WA Code and Failing Case from AtCoder --- 
    wa_code_content = None
    failing_case_name = None
    
    try:
        submission_url = f"https://atcoder.jp/contests/{contest_id}/submissions/{submission_id}"
        print(f"  [Info] Fetching details from URL: {submission_url} using loaded session.")
        
        # Call the function from tools.py using the loaded session
        case_name, case_status, wa_source, ac_count = tools.get_first_failed_case_info(submission_url, session)
        
        print(f"  [Info] tools.get_first_failed_case_info result: case='{case_name}', status='{case_status}', ac_count={ac_count}, source_len={len(wa_source) if wa_source else 0}")

        if case_name == "All Passed" or case_status == "AC":
             print(f"  [Error] Submission {submission_id} did not fail or all cases passed.", file=sys.stderr)
             # Return specific error? For now, treat as failure to find necessary info.
             wa_code_content = None
             failing_case_name = None
        elif case_name is None or wa_source is None:
             print(f"  [Error] Failed to retrieve case name or WA source code from {submission_url}. Check tools.py logs.", file=sys.stderr)
             wa_code_content = None
             failing_case_name = None
        else:
             # Success!
             wa_code_content = wa_source
             failing_case_name = case_name
             # Remove potential .txt extension if present (though tools.py likely handles this)
             if failing_case_name.lower().endswith('.txt'):
                  failing_case_name = failing_case_name[:-4]
             print(f"  [Success] Found failing case: '{failing_case_name}' with status '{case_status}'. WA code length: {len(wa_code_content)}")
             
    except Exception as e:
        print(f"  [Error] Exception while fetching/processing submission details: {e}", file=sys.stderr)
        traceback.print_exc()
        # Ensure wa_code and case_name are None on error
        wa_code_content = None
        failing_case_name = None

    return {
        "ac_code": ac_code_content,    # From local file
        "wa_code": wa_code_content,    # Fetched from AtCoder
        "case_name": failing_case_name # Fetched from AtCoder
    }

# --- Helper function to GET test case path --- (Renamed and modified)
def _get_original_input_path(base_testcase_path: str, contest_id: str, problem_letter: str, case_name: str) -> Optional[str]:
    """Constructs the path for a specific test case input file and checks existence."""
    try:
        # Construct path assuming structure like /base/abc330/D/in/test_05
        # Ensure case name doesn't have .txt extension if passed in
        if case_name.lower().endswith('.txt'):
             case_name = case_name[:-4]
             
        input_file_path = os.path.join(base_testcase_path, contest_id, problem_letter.upper(), "in", case_name)
        print(f"[Info] Checking input file path: {input_file_path}")
        if not os.path.exists(input_file_path):
            print(f"[Error] Input file not found at: {input_file_path}", file=sys.stderr)
            return None # Return None if path doesn't exist
        else:
            print(f"[Info] Input file path exists.")
            return input_file_path # Return the VALIDATED path
    except Exception as e:
        print(f"[Error] Failed to construct or check input file path: {e}", file=sys.stderr)
        return None

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
def reduce_submission(submission_id: str, problem_id_input: str, base_testcase_path: str, artifact_dir: Optional[str] = None) -> Tuple[int, str, Optional[int], Optional[int], Optional[str], Optional[str]]:
    """
    Orchestrates the test case reduction process for a given submission ID.
    Args:
        submission_id: The ID of the submission to reduce.
        problem_id_input: The problem ID string (e.g., 'abc330d').
        base_testcase_path: The base directory containing the AtCoder testcases.
        artifact_dir: Optional path to a directory where original and reduced 
                      input files should be saved.
    Returns:
        A tuple: (status_code, message, original_size, reduced_size, reduced_content_str, failing_case_name)
    """
    original_input_size = None
    reduced_input_size = None
    reduced_content_str = None # Initialize reduced content
    failing_case_name = None # Initialize failing case name
    print(f"[Orchestrate] Received problem_id: '{problem_id_input}', submission_id: {submission_id}, base_path: '{base_testcase_path}'")
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

    # 2. Get Failing Case Info (AC/WA Code, Case Name)
    print(f"[Orchestrate] Fetching info for submission {submission_id}...")
    case_info = _get_failing_case_info(submission_id, f"{contest_id}{problem_letter.lower()}", contest_id)
    
    # Check for errors reported by the helper
    if case_info.get("status") == "error":
         return case_info["status_code"], case_info["message"], None, None, None, None # Added None
         
    # Retrieve data (error checked inside helper now)
    ac_code_str = case_info.get("ac_code")
    wa_code_str = case_info.get("wa_code")
    failing_case_name = case_info.get("case_name") # Assign to variable
    
    # Simplified check: If helper succeeded, wa_code and case_name should exist
    if not wa_code_str or not failing_case_name:
         # This case should ideally be caught by the error check above
         error_msg = f"Internal error: _get_failing_case_info succeeded but returned invalid data for submission {submission_id}."
         print(f"[Error] {error_msg}", file=sys.stderr)
         return 500, error_msg, None, None, None, None # Added None
         
    # Check for AC code (optional)
    if ac_code_str is None:
        print(f"[Warning] Failed to read local AC code file: {os.path.join(f'{contest_id}{problem_letter.lower()}', 'ac.cpp')}. Proceeding without it.")

    print(f"[Orchestrate] Using info: Local AC Code (len={len(ac_code_str) if ac_code_str else 0}), Fetched WA Code (len={len(wa_code_str)}), Fetched Case={failing_case_name}")

    # 3. Get the original input file PATH
    original_input_path = _get_original_input_path(base_testcase_path, contest_id, problem_letter, failing_case_name)
    if not original_input_path: # Path finding/validation failed
        err_msg = f"Original input file not found or path invalid for case '{failing_case_name}'."
        return 404, err_msg, None, None, None, failing_case_name # Return case_name even on error

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
    test_problem_id = "abc330d" 
    test_submission_id = "50974933" # Example ID
    test_base_path = "/home/barty/research/atcoder-testcases/test/" # Matches webapp config
    
    print(f"Running reduction for Problem: {test_problem_id}, Submission: {test_submission_id}")
    if not tools:
         print("ERROR: tools module not imported, cannot run test.")
    else:
        # Call without cookie_path (comment outdated)
        # Add artifact_dir=None to the call signature
        result = reduce_submission(test_submission_id, test_problem_id, test_base_path, artifact_dir=None)
        
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