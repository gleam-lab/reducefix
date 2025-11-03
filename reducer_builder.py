# reducer_builder.py
import os
import sys
import argparse
import re
import json
import traceback
import time
import shutil  # Add shutil import for file copying
from typing import Dict, Any, Optional, Tuple, List

# --- Import new LLM module --- 
import llm 
# --- Import tools for unified description fetching --- 
import tools 

# --- Try importing necessary components ---
try:
    # We need tutor for the Qwen client and potentially problem fetching (for title/samples)
    import tutor
    print("[Info] Successfully imported 'tutor' module.")
    # Attempt to import the problem parsing function from reduce.py if needed,
    # or copy it here to avoid circular dependencies. Let's copy it for simplicity.
except ImportError:
    print("[Error] Failed to import 'tutor' module. Ensure tutor.py is in the Python path.", file=sys.stderr)
    sys.exit(1)
except Exception as e:
    print(f"[Error] Unexpected error during imports: {e}", file=sys.stderr)
    traceback.print_exc()
    sys.exit(1)

# --- Configuration ---
EXAMPLE_PROBLEM_ID_STR = "abc330d" # ID for the example
EXAMPLE_REDUCER_PATH = "results/abc330d/reducer.py" # Path to the one-shot example (under results/)
TARGET_FILENAME = "reducer.py"        # Name of the file to generate
LLM_MAX_TOKENS = 4096                 # Max tokens (passed to llm.py)
LLM_TEMPERATURE = 0.0                 # Temperature=0 for greedy decoding (as per paper)

# --- Helper Functions ---

# Copied from reduce.py to avoid import loops/complexities
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

def read_example_reducer(path: str) -> Optional[str]:
    """Reads the content of the example reducer file."""
    try:
        if os.path.exists(path):
            with open(path, 'r', encoding='utf-8') as f:
                content = f.read()
            print(f"[Info] Successfully read example reducer: {path} ({len(content)} chars)")
            return content
        else:
            # Try to fallback to model-specific versions if standard reducer.py doesn't exist
            dir_name = os.path.dirname(path)
            if dir_name:
                # Look for any reducer_*.py file in the directory
                import glob
                pattern = os.path.join(dir_name, "reducer_*.py")
                fallback_files = glob.glob(pattern)
                if fallback_files:
                    # Sort by modification time (newest first) to get the most recent reducer
                    fallback_files.sort(key=lambda x: os.path.getmtime(x), reverse=True)
                    fallback_path = fallback_files[0]
                    with open(fallback_path, 'r', encoding='utf-8') as f:
                        content = f.read()
                    print(f"[Info] Standard example reducer not found at {path}")
                    print(f"[Info] Using fallback reducer: {fallback_path} ({len(content)} chars)")
                    return content
            
            print(f"[Error] Example reducer file not found at: {path}", file=sys.stderr)
            print(f"[Error] No fallback reducer_*.py files found in {dir_name}", file=sys.stderr)
            return None
    except IOError as e:
        print(f"[Error] Failed to read example reducer file {path}: {e}", file=sys.stderr)
        return None

def build_generation_prompt(target_problem_title: str,
                            target_problem_description_md: str,
                            target_samples_json: str,
                            example_problem_title: str,
                            example_problem_description_md: str,
                            example_reducer_code: str,
                            target_problem_id_input: str
                            ) -> List[Dict[str, str]]:
    """Builds the prompt history for the LLM, putting example first."""

    # --- Slightly Condensed System Prompt --- 
    system_prompt = f"""You are an expert Python programmer creating test case reducers for AtCoder problems.
Generate a complete `reducer.py` script for the target problem based on the provided example and target problem details.
The script will be placed in a directory named like `{target_problem_id_input}/reducer.py` and called by an orchestrator (`reduce.py`) in the parent directory.
The orchestrator compiles `./ac` and `./wa`, then changes the working directory before calling your `reduce_input` function.

**Generated `reducer.py` MUST:**
1. Define `reduce_input(input_file: str, output_file: str)`: Reads `input_file`, parses according to the **target problem**, implements reduction, writes minimized input to `output_file`.
2. Include `test_interesting(...)`: Takes reduced data representation, creates input bytes, runs `./ac` and `./wa` (assume they exist in CWD), returns `True` if outputs differ.
3. Include necessary helpers (`run_program`, parsing utils - adapt from example).
4. Contain only valid Python code with imports. No `if __name__ == '__main__':` block.

**Output Format:** Respond ONLY with the complete Python code for the `reducer.py` file, enclosed in a single ```python ... ``` block. No explanations outside the code block.
"""

    # --- User Prompt with Example First --- 
    user_prompt = f"""First, here is a complete working example for problem {EXAMPLE_PROBLEM_ID_STR}:

# Example Problem Information ({EXAMPLE_PROBLEM_ID_STR})

## Title: {example_problem_title}

## Problem Description (Markdown)
{example_problem_description_md}

## Example `reducer.py` for {EXAMPLE_PROBLEM_ID_STR}
```python
# START --- Example {EXAMPLE_PROBLEM_ID_STR}/reducer.py --- START
{example_reducer_code}
# END --- Example {EXAMPLE_PROBLEM_ID_STR}/reducer.py --- END
```

--- 

Now, using the example above as a reference for structure and helper functions (like `run_program`, `test_interesting`), please generate the `reducer.py` script for the following **target problem**: 

# Target Problem Information ({target_problem_id_input})

## Title: {target_problem_title}

## Problem Description (Markdown)
{target_problem_description_md}

Generate the complete `reducer.py` code for problem **{target_problem_id_input}**. Remember to output only the Python code block.
"""

    return [
        {'role': 'system', 'content': system_prompt},
        {'role': 'user', 'content': user_prompt}
    ]

def save_generated_code(code: str, problem_dir_name: str, filename_override: str = None) -> bool:
    """Saves the generated code to the target file, creating the directory if needed."""
    target_filename = filename_override or TARGET_FILENAME
    target_path = os.path.join(problem_dir_name, target_filename)
    try:
        print(f"[Info] Attempting to save code to: {target_path}")
        os.makedirs(problem_dir_name, exist_ok=True)
        with open(target_path, 'w', encoding='utf-8') as f:
            f.write(code)
        print(f"[Success] Generated reducer saved successfully to {target_path}")
        return True
    except IOError as e:
        print(f"[Error] Failed to write generated code to {target_path}: {e}", file=sys.stderr)
        return False
    except Exception as e:
        print(f"[Error] Unexpected error saving file {target_path}: {e}", file=sys.stderr)
        return False

# --- Main Execution ---
def main():
    parser = argparse.ArgumentParser(description="Generate a problem-specific reducer.py using an LLM.")
    parser.add_argument("problem_id", help="Target AtCoder problem ID (e.g., abc123x, arc177a)")
    parser.add_argument("--llm-model", default="qwen-plus", help="LLM model name for generating reducer (default: qwen-plus)")
    parser.add_argument("--model-tag", default="default", help="Tag for result file naming (optional, default: 'default')")
    args = parser.parse_args()
    target_problem_id_input = args.problem_id.strip().lower()
    llm_model_name = args.llm_model
    model_tag = args.model_tag

    # 1. Check if Qwen client is available
    if not hasattr(tutor, 'qwen_client') or not tutor.qwen_client:
         print("[Error] Qwen client (tutor.qwen_client) is not configured or available in tutor.py. Cannot proceed.", file=sys.stderr)
         sys.exit(1)

    # 2. Parse Problem ID
    parsed_ids = _parse_problem_id(target_problem_id_input)
    if not parsed_ids:
        print(f"[Error] Invalid target problem ID format: '{target_problem_id_input}'", file=sys.stderr)
        sys.exit(1)
    contest_id, problem_letter = parsed_ids
    # 统一放在 results/ 下，例如 results/abc123x
    problem_dir_name = f"results/{contest_id}{problem_letter.lower()}" # e.g., results/abc123x

    # Prevent overwriting the example itself
    if problem_dir_name == os.path.dirname(EXAMPLE_REDUCER_PATH):
         print(f"[Error] Target problem ID resolves to the example problem '{problem_dir_name}'. Aborting.", file=sys.stderr)
         sys.exit(1)

    # Check if reducer.py already exists
    target_reducer_path = os.path.join(problem_dir_name, TARGET_FILENAME)
    
    # NEW: First check if a model-specific reducer exists
    model_specific_reducer_path = os.path.join(problem_dir_name, f"reducer_{llm_model_name}.py")
    
    if os.path.exists(model_specific_reducer_path):
        print(f"[Info] Found existing model-specific reducer: {model_specific_reducer_path}")
        try:
            # Copy the model-specific reducer to the standard reducer.py name
            import shutil as copy_module  # Import locally to avoid any scoping issues
            copy_module.copy2(model_specific_reducer_path, target_reducer_path)
            print(f"[Success] Copied existing reducer {model_specific_reducer_path} to {target_reducer_path}")
            print(f"[Success] Using existing reducer for {target_problem_id_input} with model {llm_model_name}. No generation needed.")
            sys.exit(0)
        except Exception as e:
            print(f"[Warning] Failed to copy existing reducer: {e}. Will generate new one.", file=sys.stderr)
    elif os.path.exists(target_reducer_path):
        print(f"[Info] Reducer file already exists at {target_reducer_path}")
        print(f"[Success] Using existing reducer for {target_problem_id_input}. No generation needed.")
        sys.exit(0)

    # --- Fetch TARGET Problem Details (Title/Samples from Tutor, Description from Tools) --- 
    target_details = None
    target_problem_title = "Unknown Title"
    target_samples_json_str = "[]"
    target_problem_description_md = None

    print(f"Fetching details for target problem {target_problem_id_input}...")
    try:
        tutor_problem_id_target = f"{contest_id}_{problem_letter.lower()}"
        # Get Title/Samples from Tutor
        target_details_dict, status_code = tutor.fetch_problem_details(contest_id, tutor_problem_id_target)
        if status_code != 200:
            print(f"[Warning] Failed to fetch target problem details (title/samples) from Tutor: {status_code} - {target_details_dict.get('error', 'Unknown error')}", file=sys.stderr)
            # Continue anyway, try to get description from tools
        else:
            target_details = target_details_dict
            target_problem_title = target_details.get("title", target_problem_title)
            target_samples_json_str = target_details.get("samples_json", target_samples_json_str)
            try: # Validate target samples JSON
                json.loads(target_samples_json_str)
            except json.JSONDecodeError:
                print("[Warning] Fetched target samples_json is not valid JSON. Using '[]'.", file=sys.stderr)
                target_samples_json_str = "[]"
            print("[Info] Target problem title/samples fetched successfully via Tutor.")

        # Get Description (Markdown) from Tools
        print("Fetching target problem description (Markdown) via Tools...")
        target_problem_url = f"https://atcoder.jp/contests/{contest_id}/tasks/{tutor_problem_id_target}"
        session = tools.load_session() # Need session for tools
        if session:
             target_problem_description_md = tools.get_problem_description(target_problem_url, session)
             if not target_problem_description_md or target_problem_description_md.startswith("# Error"):
                  print(f"[Error] Failed to get target problem description from Tools: {target_problem_description_md or 'None returned'}", file=sys.stderr)
                  # Decide whether to exit or proceed without description
                  sys.exit(1) # Exit if description is critical
             else:
                 print("[Info] Target problem description fetched successfully via Tools.")
        else:
             print("[Error] Failed to get session via tools.load_session(). Cannot fetch description.", file=sys.stderr)
             sys.exit(1)

    except Exception as e:
        print(f"[Error] Error during target problem detail fetching: {e}", file=sys.stderr)
        traceback.print_exc()
        sys.exit(1)
        
    # --- Fetch EXAMPLE Problem Details (Title from Tutor, Description from Tools) --- 
    example_details = None
    example_problem_title = f"Title for {EXAMPLE_PROBLEM_ID_STR}"
    example_problem_description_md = None

    print(f"Fetching details for example problem {EXAMPLE_PROBLEM_ID_STR}...")
    try:
        example_parsed_ids = _parse_problem_id(EXAMPLE_PROBLEM_ID_STR)
        if not example_parsed_ids:
             print(f"[Error] Failed to parse the hardcoded example problem ID: {EXAMPLE_PROBLEM_ID_STR}", file=sys.stderr)
             sys.exit(1)
        example_contest_id, example_problem_letter = example_parsed_ids
        tutor_problem_id_example = f"{example_contest_id}_{example_problem_letter.lower()}"
        
        # Get Title from Tutor
        example_details_dict, status_code = tutor.fetch_problem_details(example_contest_id, tutor_problem_id_example)
        if status_code != 200:
            print(f"[Warning] Failed to fetch example problem details (title) from Tutor: {status_code} - {example_details_dict.get('error', 'Unknown error')}", file=sys.stderr)
        else:
            example_details = example_details_dict
            example_problem_title = example_details.get("title", example_problem_title)
            print("[Info] Example problem title fetched successfully via Tutor.")

        # Get Description (Markdown) from Tools
        print("Fetching example problem description (Markdown) via Tools...")
        example_problem_url = f"https://atcoder.jp/contests/{example_contest_id}/tasks/{tutor_problem_id_example}"
        # Reuse session if already loaded
        if not session: session = tools.load_session()
        if session:
             example_problem_description_md = tools.get_problem_description(example_problem_url, session)
             if not example_problem_description_md or example_problem_description_md.startswith("# Error"):
                  print(f"[Error] Failed to get example problem description from Tools: {example_problem_description_md or 'None returned'}", file=sys.stderr)
                  sys.exit(1) # Example description is critical
             else:
                  print("[Info] Example problem description fetched successfully via Tools.")
        else:
             print("[Error] Failed to get session via tools.load_session(). Cannot fetch example description.", file=sys.stderr)
             sys.exit(1)

    except Exception as e:
        print(f"[Error] Error during example problem detail fetching: {e}", file=sys.stderr)
        traceback.print_exc()
        sys.exit(1)
        
    # 4. Read Example Reducer Code
    print(f"Reading example reducer code from {EXAMPLE_REDUCER_PATH}...")
    example_code = read_example_reducer(EXAMPLE_REDUCER_PATH)
    if not example_code:
        sys.exit(1)

    # 5. Build Prompt (Using fetched descriptions)
    print("Building prompt for LLM...")
    prompt_history = build_generation_prompt(
        target_problem_title=target_problem_title,
        target_problem_description_md=target_problem_description_md, # Now from tools
        target_samples_json=target_samples_json_str,
        example_problem_title=example_problem_title,
        example_problem_description_md=example_problem_description_md, # Now from tools
        example_reducer_code=example_code,
        target_problem_id_input=target_problem_id_input
    )
    
    # --- Debug: Print the prompt --- 
    print("\n" + "="*30 + " PROMPT SENT TO LLM " + "="*30)
    for message in prompt_history:
        print(f"--- ROLE: {message['role']} ---")
        print(message['content'])
        print("-"*70)
    print("="*80 + "\n")
    # --- End Debug Print --- 

    # 5.5 Save the prompt
    prompt_filename = f"llm_prompt_{model_tag}.txt"
    prompt_path = os.path.join(problem_dir_name, prompt_filename)
    print(f"Saving LLM prompt to {prompt_path}...")
    try:
        os.makedirs(problem_dir_name, exist_ok=True) # Ensure dir exists
        full_prompt_text = f"SYSTEM:\n{prompt_history[0]['content']}\n\nUSER:\n{prompt_history[1]['content']}"
        with open(prompt_path, 'w', encoding='utf-8') as f_prompt:
            f_prompt.write(full_prompt_text)
        print(f"[Info] Prompt saved successfully.")
    except Exception as e:
        print(f"[Warning] Failed to save LLM prompt to {prompt_path}: {e}", file=sys.stderr)

    # 6. Generate Code using llm.py
    print(f"Generating reducer code using {llm_model_name} via llm.py...")
    # Override default model name if user specifies
    global LLM_MODEL_NAME
    LLM_MODEL_NAME = llm_model_name
    # Call the centralized function
    raw_llm_response = llm.call_llm(
        prompt_history=prompt_history,
        model_name=LLM_MODEL_NAME,
        temperature=LLM_TEMPERATURE,
        max_tokens=LLM_MAX_TOKENS
    )

    # Check if generation was successful
    if raw_llm_response is None:
        print("[Error] Failed to generate code from LLM (call_llm returned None).", file=sys.stderr)
        sys.exit(1)

    # 6.6 Save the raw final response
    response_filename = f"llm_response_raw_{model_tag}.txt"
    response_path = os.path.join(problem_dir_name, response_filename)
    print(f"Saving raw LLM final response to {response_path}...")
    try:
        with open(response_path, 'w', encoding='utf-8') as f_resp:
            f_resp.write(raw_llm_response)
        print(f"[Info] Raw final response saved successfully.")
    except Exception as e:
        print(f"[Warning] Failed to save LLM raw final response to {response_path}: {e}", file=sys.stderr)

    # 7. Extract Code using llm.py
    print("Extracting pure Python code from LLM final response...")
    # Call the centralized function
    extracted_code = llm.extract_python_code(raw_llm_response)
    if not extracted_code:
        print("[Error] Failed to extract Python code block from the LLM final response:", file=sys.stderr)
        print("--- LLM Final Response --- ")
        print(raw_llm_response)
        print("--------------------------")
        sys.exit(1)
    else:
        print(f"[Info] Extracted code block length: {len(extracted_code)}")

    # 8. Save Code
    print(f"Saving generated code to {os.path.join(problem_dir_name, TARGET_FILENAME)}...")
    # 首先保存为标准的 reducer.py（供 reduce.py 导入使用）
    if save_generated_code(extracted_code, problem_dir_name, filename_override=TARGET_FILENAME):
        print(f"[Success] Reducer code for {target_problem_id_input} generated and saved as {TARGET_FILENAME}!")
        
        # 同时保存一个带模型标签的备份版本（用于区分不同模型生成的版本）
        backup_filename = f"reducer_{model_tag}.py"
        backup_path = os.path.join(problem_dir_name, backup_filename)
        try:
            import shutil
            shutil.copy2(os.path.join(problem_dir_name, TARGET_FILENAME), backup_path)
            print(f"[Info] Also saved backup copy as {backup_filename}")
        except Exception as e:
            print(f"[Warning] Failed to create backup copy {backup_filename}: {e}", file=sys.stderr)
    else:
        print("[Error] Failed to save the generated code.", file=sys.stderr)
        sys.exit(1)

if __name__ == "__main__":
    main()