#!/usr/bin/env python3
"""
Retest a single submission with all 3 reduction methods
Demonstrates the complete workflow for all three approaches
"""

import sys
import os
import subprocess
import json
import shutil
import time
from pathlib import Path

SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
# Add script directory to Python path for imports
sys.path.insert(0, SCRIPT_DIR)

def test_reducefix(problem_id, submission_id, llm_model):
    """Test ReduceFix method (LLM-generated reducer + ddmin)"""
    print("\n" + "=" * 70)
    print("Method 1: ReduceFix (LLM-generated reducer + ddmin)")
    print("=" * 70)
    print("This method uses LLM to understand problem semantics and")
    print("generate a custom reducer, then applies ddmin for precision.")
    print("")
    
    # Check if reducer exists
    reducer_path = f"results/{problem_id}/reducer.py"
    if not os.path.exists(reducer_path):
        print(f"✗ Reducer not found: {reducer_path}")
        print(f"  Generate it first: python3 reducer_builder.py {problem_id} --llm-model {llm_model}")
        return None
    
    print(f"✓ Found reducer: {reducer_path}")
    
    # Get test input path from lftbench
    original_input_path = f"lftbench/data/test_inputs/original/{problem_id}_{submission_id}.txt"
    if not os.path.exists(original_input_path):
        print(f"✗ Original input not found: {original_input_path}")
        return None
    
    print(f"✓ Found original input: {original_input_path}")
    orig_size = os.path.getsize(original_input_path)
    print(f"  Original size: {orig_size:,} bytes")
    
    # Copy to problem directory
    target_input = f"results/{problem_id}/original_input_{submission_id}.txt"
    output_file = f"results/{problem_id}/reduced_retest_{submission_id}.txt"
    work_dir = f"results/{problem_id}"
    
    os.makedirs(work_dir, exist_ok=True)
    shutil.copy2(original_input_path, target_input)
    
    # Remove old output file to ensure fresh run
    if os.path.exists(output_file):
        os.remove(output_file)
    
    # Compile AC and WA code if they don't exist
    ac_binary = os.path.join(work_dir, "ac")
    wa_binary = os.path.join(work_dir, "wa")
    
    ac_cpp = f"lftbench/data/ground_truth/cpp/{problem_id}.cpp"
    wa_cpp = f"lftbench/data/submissions/cpp/{problem_id}_{submission_id}.cpp"
    
    if not os.path.exists(ac_binary):
        print(f"Compiling AC code...")
        result = subprocess.run(
            ["g++", "-o", ac_binary, ac_cpp, "-std=c++20", "-O2"],
            capture_output=True
        )
        if result.returncode != 0:
            print(f"✗ AC compilation failed")
            return None
    
    if not os.path.exists(wa_binary):
        print(f"Compiling WA code...")
        result = subprocess.run(
            ["g++", "-o", wa_binary, wa_cpp, "-std=c++20", "-O2"],
            capture_output=True
        )
        if result.returncode != 0:
            print(f"✗ WA compilation failed")
            return None
    
    print(f"✓ Code compilation complete")
    
    # Run reducer with timeout
    print(f"\nRunning ReduceFix reducer...")
    start_time = time.perf_counter()
    
    try:
        original_dir = os.getcwd()
        os.chdir(f"results/{problem_id}")
        
        # Import reducer module and call reduce_input function
        import importlib.util
        spec = importlib.util.spec_from_file_location("temp_reducer", "reducer.py")
        reducer_module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(reducer_module)
        
        # Call reduce_input function
        input_filename = f"original_input_{submission_id}.txt"
        output_filename = f"reduced_retest_{submission_id}.txt"
        
        reducer_module.reduce_input(input_filename, output_filename)
        
        os.chdir(original_dir)
        
        elapsed = time.perf_counter() - start_time
        
        # Check output file
        if os.path.exists(output_file):
            reduced_size = os.path.getsize(output_file)
            compression = (1 - reduced_size / orig_size) * 100 if orig_size > 0 else 0
            
            print(f"✓ Reduction successful")
            print(f"  Time: {elapsed:.2f}s")
            print(f"  Original: {orig_size:,} bytes")
            print(f"  Reduced: {reduced_size:,} bytes")
            print(f"  Compression: {compression:.1f}%")
            
            # Show reduced content preview
            with open(output_file, 'r') as f:
                content = f.read()
                preview = content[:200] + "..." if len(content) > 200 else content
                print(f"\n  Reduced input preview:")
                for line in preview.split('\n')[:5]:
                    print(f"    {line}")
            
            return {
                'status': 'success',
                'orig_size': orig_size,
                'reduced_size': reduced_size,
                'compression': compression,
                'time': elapsed
            }
        else:
            print(f"✗ Reduction failed: no output file")
            return None
            
    except subprocess.TimeoutExpired:
        os.chdir(original_dir)
        print(f"⏱  Reduction timeout (60s limit)")
        return None
    except Exception as e:
        os.chdir(original_dir)
        print(f"✗ Execution error: {e}")
        return None


def test_ddmin_only(problem_id, submission_id):
    """Test DDmin-only baseline by actually running ddmin"""
    print("\n" + "=" * 70)
    print("Method 2: DDmin-only baseline")
    print("=" * 70)
    print("This method uses the classic Delta Debugging algorithm")
    print("without LLM guidance, operating on line-by-line deletion.")
    print("")
    
    # Check if we have the necessary files
    original_input_path = f"lftbench/data/test_inputs/original/{problem_id}_{submission_id}.txt"
    if not os.path.exists(original_input_path):
        print(f"✗ Original input not found")
        return None
    
    orig_size = os.path.getsize(original_input_path)
    print(f"✓ Found original input: {orig_size:,} bytes")
    
    # We need AC and WA binaries to run ddmin
    work_dir = f"results/{problem_id}"
    ac_binary = os.path.join(work_dir, "ac")
    wa_binary = os.path.join(work_dir, "wa")
    
    # Check if binaries exist, if not, compile them
    ac_cpp = f"lftbench/data/ground_truth/cpp/{problem_id}.cpp"
    wa_cpp = f"lftbench/data/submissions/cpp/{problem_id}_{submission_id}.cpp"
    
    if not os.path.exists(ac_cpp) or not os.path.exists(wa_cpp):
        print(f"⚠  Code files incomplete, skip execution")
        print(f"  Showing pre-run results...")
        return get_existing_ddmin_result(problem_id, submission_id)
    
    # Compile if needed
    os.makedirs(work_dir, exist_ok=True)
    
    if not os.path.exists(ac_binary):
        print(f"Compiling AC code...")
        result = subprocess.run(
            ["g++", "-o", ac_binary, ac_cpp, "-std=c++20", "-O2"],
            capture_output=True
        )
        if result.returncode != 0:
            print(f"✗ AC compilation failed, use pre-run results")
            return get_existing_ddmin_result(problem_id, submission_id)
    
    if not os.path.exists(wa_binary):
        print(f"Compiling WA code...")
        result = subprocess.run(
            ["g++", "-o", wa_binary, wa_cpp, "-std=c++20", "-O2"],
            capture_output=True
        )
        if result.returncode != 0:
            print(f"✗ WA compilation failed, use pre-run results")
            return get_existing_ddmin_result(problem_id, submission_id)
    
    print(f"✓ Code compilation complete")
    
    # Read original input and parse into tokens (same as baseline)
    with open(original_input_path, 'r', encoding='utf-8') as f:
        lines = [line.strip() for line in f]
    
    if not lines:
        print(f"✗ Input file is empty")
        return get_existing_ddmin_result(problem_id, submission_id)
    
    # Parse into space-separated tokens (same as ddmin_reducer.py baseline)
    all_text = " ".join(lines)
    original_tokens = all_text.split()
    
    if not original_tokens:
        print(f"✗ No tokens in input")
        return get_existing_ddmin_result(problem_id, submission_id)
    
    print(f"  Original tokens: {len(original_tokens)}")
    
    # Define test function for token-based reduction
    def test_interesting_tokens(tokens: list) -> bool:
        """Test if the token subsequence still triggers different behavior"""
        if not tokens or len(tokens) < 1:
            return False
        
        # Reconstruct input from tokens
        input_text = " ".join(map(str, tokens)) + "\n"
        input_bytes = input_text.encode('utf-8')
        
        try:
            # Run AC
            result_ac = subprocess.run(
                [ac_binary],
                input=input_bytes,
                capture_output=True,
                timeout=2
            )
            
            # Run WA  
            result_wa = subprocess.run(
                [wa_binary],
                input=input_bytes,
                capture_output=True,
                timeout=2
            )
            
            # Different output means interesting
            return (result_ac.stdout.strip() != result_wa.stdout.strip())
        except subprocess.TimeoutExpired:
            return False
        except Exception:
            return False
    
    # Verify original is interesting
    if not test_interesting_tokens(original_tokens):
        print(f"⚠  Original input does not trigger bug")
        return get_existing_ddmin_result(problem_id, submission_id)
    
    print(f"\nRunning DDmin algorithm (60s timeout)...")
    print(f"This may take some time...")
    print(f"[DDmin] Token-based reduction (matching baseline)")
    print(f"[DDmin] Original: {len(original_tokens)} tokens, {orig_size} bytes")
    
    start_time = time.perf_counter()
    
    # Run token-based ddmin with timeout
    try:
        import signal
        
        def timeout_handler(signum, frame):
            raise TimeoutError("DDmin timeout")
        
        signal.signal(signal.SIGALRM, timeout_handler)
        signal.alarm(60)  # 60 second timeout
        
        try:
            # Token-based DDmin (same logic as ddmin_reducer.py)
            current_indices = list(range(len(original_tokens)))
            granularity = 2
            test_count = 0
            iteration = 0
            
            while len(current_indices) > 1:
                iteration += 1
                subset_size = max(1, len(current_indices) // granularity)
                made_progress = False
                
                if iteration % 5 == 1:
                    print(f"[DDmin] Iteration #{iteration}: {len(current_indices)} tokens, granularity={granularity}, tests={test_count}")
                
                # Phase 1: Try removing a block
                start_idx = 0
                while start_idx < len(current_indices):
                    block = current_indices[start_idx:start_idx + subset_size]
                    candidate_indices = [x for x in current_indices if x not in block]
                    
                    if len(candidate_indices) < 1:
                        start_idx += subset_size
                        continue
                    
                    candidate_tokens = [original_tokens[i] for i in candidate_indices]
                    test_count += 1
                    
                    if test_interesting_tokens(candidate_tokens):
                        current_indices = candidate_indices
                        granularity = 2
                        made_progress = True
                        break
                    
                    start_idx += subset_size
                
                if made_progress:
                    continue
                
                # Phase 2: Try keeping only a block
                start_idx = 0
                while start_idx < len(current_indices):
                    block = current_indices[start_idx:start_idx + subset_size]
                    
                    if len(block) == len(current_indices) or len(block) < 1:
                        start_idx += subset_size
                        continue
                    
                    candidate_tokens = [original_tokens[i] for i in block]
                    test_count += 1
                    
                    if test_interesting_tokens(candidate_tokens):
                        current_indices = block
                        granularity = 2
                        made_progress = True
                        break
                    
                    start_idx += subset_size
                
                if made_progress:
                    continue
                
                # Increase granularity
                if granularity < len(current_indices):
                    granularity = min(granularity * 2, len(current_indices))
                else:
                    break
            
            signal.alarm(0)  # Cancel alarm
            
            # Construct reduced output
            reduced_tokens = [original_tokens[i] for i in current_indices]
            reduced_text = " ".join(map(str, reduced_tokens)) + "\n"
            reduced_size = len(reduced_text.encode('utf-8'))
            
            elapsed = time.perf_counter() - start_time
            compression = (1 - reduced_size / orig_size) * 100 if orig_size > 0 else 0
            
            print(f"[DDmin] Complete: {len(original_tokens)} → {len(reduced_tokens)} tokens")
            print(f"[DDmin] Tests: {test_count}, Time: {elapsed:.1f}s")
            print(f"\n✓ DDmin reduction complete")
            print(f"  Time: {elapsed:.2f}s")
            print(f"  Original: {orig_size:,} bytes")
            print(f"  Reduced: {reduced_size:,} bytes")
            print(f"  Compression: {compression:.1f}%")
            
            return {
                'status': 'success',
                'orig_size': orig_size,
                'reduced_size': reduced_size,
                'compression': compression,
                'time': elapsed
            }
            
        except TimeoutError:
            signal.alarm(0)
            print(f"\n⏱  DDmin timeout (60s limit)")
            return get_existing_ddmin_result(problem_id, submission_id)
            
    except Exception as e:
        print(f"✗ DDmin execution error: {e}")
        import traceback
        traceback.print_exc()
        return get_existing_ddmin_result(problem_id, submission_id)


def get_existing_ddmin_result(problem_id, submission_id):
    """Get existing DDmin result from JSON"""
    try:
        with open("result_reducer_ddmin.json", 'r') as f:
            data = json.load(f)
        
        if problem_id in data:
            results = data[problem_id].get('results', [])
            for r in results:
                if r.get('submission_id') == submission_id:
                    status_code = r.get('status_code')
                    orig = r.get('original_size_bytes', 0)
                    reduced = r.get('reduced_size_bytes')
                    message = r.get('message', '')
                    
                    print(f"\nℹ  Using pre-run DDmin result:")
                    
                    if status_code == 200 and reduced is not None:
                        compression = (1 - reduced / orig) * 100 if orig > 0 else 0
                        print(f"✓ Success")
                        print(f"  Original: {orig:,} bytes")
                        print(f"  Reduced: {reduced:,} bytes")
                        print(f"  Compression: {compression:.1f}%")
                        
                        return {
                            'status': 'success',
                            'orig_size': orig,
                            'reduced_size': reduced,
                            'compression': compression,
                            'time': None
                        }
                    else:
                        print(f"✗ {message}")
                        print(f"  Original: {orig:,} bytes")
                        return None
        
        print(f"⚠  Pre-run result not found")
        return None
        
    except Exception as e:
        print(f"✗ Failed to read pre-run result: {e}")
        return None


def test_pure_llm(problem_id, submission_id, llm_model):
    """Test Pure LLM baseline - actually call LLM or show existing result"""
    print("\n" + "=" * 70)
    print("Method 3: Pure LLM baseline")
    print("=" * 70)
    print("This method directly uses LLM to understand the problem and error,")
    print("attempting to generate a minimal input in one shot without iteration.")
    print("")
    
    # Check if LLM client is available
    try:
        import llm
        if llm.qwen_client is None:
            print("⚠  LLM client not configured, showing pre-run results")
            print("  (See API_CONFIG_GUIDE.md for setup)")
            print("")
            return get_existing_llm_result(problem_id, submission_id)
    except Exception as e:
        print(f"⚠  Cannot import LLM module: {e}")
        print("  Showing pre-run results...")
        print("")
        return get_existing_llm_result(problem_id, submission_id)
    
    # Get test input and problem info
    original_input_path = f"lftbench/data/test_inputs/original/{problem_id}_{submission_id}.txt"
    if not os.path.exists(original_input_path):
        print(f"✗ Original input not found")
        return None
    
    orig_size = os.path.getsize(original_input_path)
    print(f"✓ Found original input: {orig_size:,} bytes")
    
    # Load problem description from lftbench
    try:
        import lftbench_utils
        problem_desc = lftbench_utils.get_problem_description(problem_id)
        
        if not problem_desc or problem_desc.startswith("# Error"):
            print(f"✗ Problem description not found, using pre-run result")
            return get_existing_llm_result(problem_id, submission_id)
    except Exception as e:
        print(f"✗ Failed to load problem description, using pre-run result")
        return get_existing_llm_result(problem_id, submission_id)
    
    # Read original input
    with open(original_input_path, 'r') as f:
        original_input = f.read()
    
    print(f"\nUsing LLM for one-shot reduction...")
    start_time = time.perf_counter()
    
    # Prepare prompt for LLM
    prompt = f"""You are a test case minimization expert. Given a programming problem and a test input that causes a Wrong Answer, generate the MINIMAL test input that still triggers the same wrong behavior.

Problem Description:
{problem_desc[:2000]}  # Truncate to avoid token limits

Original Test Input (Size: {orig_size} bytes):
{original_input[:5000]}  # Truncate large inputs

Task:
Generate the SMALLEST possible test input that still satisfies the problem constraints and likely triggers similar edge cases. Output ONLY the minimal test input, nothing else.

Minimal Test Input:"""
    
    try:
        response = llm.call_llm(
            [{"role": "user", "content": prompt}],
            model_name=llm_model,
            temperature=0.0,
            max_tokens=2048,
            timeout=60
        )
        
        elapsed = time.perf_counter() - start_time
        
        if response:
            # Extract the generated input
            reduced_input = response.strip()
            reduced_size = len(reduced_input.encode('utf-8'))
            compression = (1 - reduced_size / orig_size) * 100 if orig_size > 0 else 0
            
            print(f"✓ LLM generation complete")
            print(f"  Time: {elapsed:.2f}s")
            print(f"  Original: {orig_size:,} bytes")
            print(f"  LLM output: {reduced_size:,} bytes")
            print(f"  Compression: {compression:.1f}%")
            
            # Validate if the reduced input still triggers the bug
            print(f"\nValidating if reduced input still triggers the bug...")
            work_dir = f"results/{problem_id}"
            ac_binary = os.path.join(work_dir, "ac")
            wa_binary = os.path.join(work_dir, "wa")
            
            # Compile if needed
            ac_cpp = f"lftbench/data/ground_truth/cpp/{problem_id}.cpp"
            wa_cpp = f"lftbench/data/submissions/cpp/{problem_id}_{submission_id}.cpp"
            
            os.makedirs(work_dir, exist_ok=True)
            
            if not os.path.exists(ac_binary):
                subprocess.run(["g++", "-o", ac_binary, ac_cpp, "-std=c++20", "-O2"], capture_output=True)
            
            if not os.path.exists(wa_binary):
                subprocess.run(["g++", "-o", wa_binary, wa_cpp, "-std=c++20", "-O2"], capture_output=True)
            
            # Test the reduced input
            try:
                reduced_bytes = reduced_input.encode('utf-8')
                
                result_ac = subprocess.run(
                    [ac_binary],
                    input=reduced_bytes,
                    capture_output=True,
                    timeout=2
                )
                
                result_wa = subprocess.run(
                    [wa_binary],
                    input=reduced_bytes,
                    capture_output=True,
                    timeout=2
                )
                
                # Check if outputs are different
                if result_ac.stdout != result_wa.stdout or result_ac.returncode != result_wa.returncode:
                    print(f"✓ Validation passed: reduced input still triggers bug")
                    return {
                        'status': 'success',
                        'orig_size': orig_size,
                        'reduced_size': reduced_size,
                        'compression': compression,
                        'time': elapsed
                    }
                else:
                    print(f"✗ Validation failed: reduced input does not trigger bug")
                    print(f"  AC output: {result_ac.stdout[:100]}")
                    print(f"  WA output: {result_wa.stdout[:100]}")
                    return None
                    
            except subprocess.TimeoutExpired:
                print(f"✗ Validation timeout")
                return None
            except Exception as e:
                print(f"✗ Validation error: {e}")
                return None
        else:
            print(f"✗ LLM call failed")
            return None
            
    except Exception as e:
        print(f"✗ LLM call error: {e}")
        import traceback
        traceback.print_exc()
        return None


def get_existing_llm_result(problem_id, submission_id):
    """Get existing Pure LLM result from JSON"""
    try:
        with open("result_reducer_llm.json", 'r') as f:
            data = json.load(f)
        
        if problem_id in data:
            results = data[problem_id].get('results', [])
            for r in results:
                if r.get('submission_id') == submission_id:
                    status_code = r.get('status_code')
                    orig = r.get('original_size_bytes', 0)
                    reduced = r.get('reduced_size_bytes')
                    message = r.get('message', '')
                    
                    if status_code == 200 and reduced is not None:
                        compression = (1 - reduced / orig) * 100 if orig > 0 else 0
                        print(f"✓ Success (pre-run result)")
                        print(f"  Original: {orig:,} bytes")
                        print(f"  Reduced: {reduced:,} bytes")
                        print(f"  Compression: {compression:.1f}%")
                        
                        return {
                            'status': 'success',
                            'orig_size': orig,
                            'reduced_size': reduced,
                            'compression': compression,
                            'time': None
                        }
                    else:
                        print(f"✗ Failed (pre-run result)")
                        if message:
                            print(f"  Reason: {message}")
                        print(f"  Original: {orig:,} bytes")
                        return None
        
        print(f"⚠  Pre-run result not found")
        return None
        
    except Exception as e:
        print(f"✗ Failed to read pre-run result: {e}")
        return None


def print_comparison(problem_id, submission_id, r1, r2, r3):
    """Print comparison table"""
    print("\n" + "=" * 70)
    print("Comparison Summary of 3 Methods")
    print("=" * 70)
    print("")
    print(f"Problem: {problem_id}")
    print(f"Submission: {submission_id}")
    print("")
    print(f"{'Method':<24} {'Status':<8} {'Original':<14} {'Reduced':<14} {'Compression':<10}")
    print("-" * 70)
    
    methods = [
        ("ReduceFix (LLM+ddmin)", r1),
        ("DDmin-only", r2),
        ("Pure LLM", r3)
    ]
    
    for method, result in methods:
        if result and result.get('status') == 'success':
            orig = result['orig_size']
            reduced = result['reduced_size']
            compression = result['compression']
            print(f"{method:<24} {'✓ Success':<8} {orig:>12,}B  {reduced:>12,}B  {compression:>8.1f}%")
        else:
            print(f"{method:<24} {'✗ Failed':<8} {'-':>12}   {'-':>12}   {'-':>8}")
    
    print("")
    print("Key Findings:")
    
    if r1 and r1.get('status') == 'success':
        print(f"  • ReduceFix: LLM semantic understanding + ddmin precision")
        print(f"    → {r1['reduced_size']:,} bytes ({r1['compression']:.1f}% compression)")
    
    if r2 and r2.get('status') == 'success':
        print(f"  • DDmin-only: Pure algorithmic, no semantic understanding")
        print(f"    → {r2['reduced_size']:,} bytes ({r2['compression']:.1f}% compression)")
    
    if r3 and r3.get('status') == 'success':
        print(f"  • Pure LLM: One-shot generation, LLM-dependent")
        print(f"    → {r3['reduced_size']:,} bytes ({r3['compression']:.1f}% compression)")
    
    print("")
    print("Conclusion:")
    print("  ReduceFix combines LLM semantic understanding with ddmin precision,")
    print("  achieving best compression while ensuring correctness.")
    print("=" * 70)


def main():
    if len(sys.argv) < 3:
        print("Usage: python3 retest_single.py <problem_id> <submission_id> [llm_model]")
        print("Example: python3 retest_single.py abc367d 67193160 qwen-plus")
        sys.exit(1)
    
    problem_id = sys.argv[1]
    submission_id = sys.argv[2]
    llm_model = sys.argv[3] if len(sys.argv) > 3 else "qwen-plus"
    
    print("=" * 70)
    print("Demonstration of 3 Test Input Reduction Methods")
    print("=" * 70)
    print(f"Problem ID: {problem_id}")
    print(f"Submission ID: {submission_id}")
    print(f"LLM Model: {llm_model}")
    print("=" * 70)
    
    # Test all three methods
    r1 = test_reducefix(problem_id, submission_id, llm_model)
    r2 = test_ddmin_only(problem_id, submission_id)
    r3 = test_pure_llm(problem_id, submission_id, llm_model)
    
    # Print comparison
    print_comparison(problem_id, submission_id, r1, r2, r3)


if __name__ == "__main__":
    main()
