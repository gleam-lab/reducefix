#!/usr/bin/env python3
"""
Consolidate all problem reduction results into a unified reducer_results.json file
Collect reduction results from existing result_*.json files and file system
"""

import os
import json
import glob
from typing import Dict, List, Optional
import sys

# Problem list extracted from run_batch.sh
PROBLEMS = [
    "abc361c", "abc362d", "abc363e", "abc364d", "abc365d", "abc366c", 
    "abc367d", "abc368c", "abc369d", "abc370d", "abc371d", "abc372e", 
    "abc373e", "abc374e", "abc375c", "abc376c", "abc376e", "abc376d", 
    "abc377c", "abc377f"
]

reduced_input_file = "llm_reduced_input.txt"

# Additional problems can be added from command line
if len(sys.argv) > 1:
    additional_problems = sys.argv[1:]
    PROBLEMS.extend(additional_problems)
    print(f"[Info] Added additional problems: {', '.join(additional_problems)}")

OUTPUT_FILE = "llm_reducer_results.json"

def load_json_safe(file_path: str) -> Optional[Dict]:
    """Safely load JSON file"""
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            return json.load(f)
    except Exception as e:
        print(f"[Warning] Cannot load {file_path}: {e}")
        return None

def scan_file_system_for_reductions(problem_id: str) -> List[Dict]:
    """Scan file system for reduction results"""
    results = []
    problem_dir = problem_id
    
    if not os.path.isdir(problem_dir):
        return results
    
    for item in os.listdir(problem_dir):
        item_path = os.path.join(problem_dir, item)
        if os.path.isdir(item_path) and item.isdigit():
            submission_id = item
            
            # Check required files
            reduced_input_path = os.path.join(item_path, reduced_input_file)
            wa_code_path = os.path.join(item_path, f"wa_{submission_id}.cpp")
            
            if os.path.exists(reduced_input_path) and os.path.exists(wa_code_path):
                # Collect more information
                original_input_path = os.path.join(item_path, "original_input.txt")
                
                # Get file sizes
                original_size = None
                reduced_size = None
                try:
                    if os.path.exists(original_input_path):
                        original_size = os.path.getsize(original_input_path)
                    reduced_size = os.path.getsize(reduced_input_path)
                except Exception as e:
                    print(f"[Warning] Cannot get file size for {submission_id}: {e}")
                
                results.append({
                    "submission_id": submission_id,
                    "wa_code_path": wa_code_path,
                    "status_code": 200,
                    "message": "Successful reduction (from file system)",
                    "original_size_bytes": original_size,
                    "reduced_size_bytes": reduced_size,
                    "failing_case_name": None,  # Not available in file system
                    "execution_time_seconds": None  # Not available in file system
                })
    
    return results

def collect_problem_data(problem_id: str) -> Optional[Dict]:
    """Collect complete data for a single problem"""
    print(f"Collecting data for {problem_id}...")
    
    # 1. Scan file system for reduction results
    file_system_results = scan_file_system_for_reductions(problem_id)
    
    # 2. If no results found in file system, return None
    if not file_system_results:
        print(f"  {problem_id} has no reduction results in file system")
        return None
    
    print(f"  Found {len(file_system_results)} reduction results from file system")
    
    # 3. Try to find the most complete data from existing JSON files for metadata
    json_files = glob.glob("result_*.json")
    best_data = None
    best_source = None
    
    for json_file in json_files:
        data = load_json_safe(json_file)
        if data and problem_id in data:
            problem_data = data[problem_id]
            
            # Check data completeness
            has_description = bool(problem_data.get("problem_description"))
            has_reducer_code = bool(problem_data.get("reducer_code"))
            has_results = bool(problem_data.get("results"))
            
            score = sum([has_description, has_reducer_code, has_results])
            
            if best_data is None or score > best_data["score"]:
                best_data = {
                    "data": problem_data,
                    "score": score,
                    "source": json_file
                }
                best_source = json_file
    
    if best_data:
        print(f"  Got best data from {best_source} (completeness: {best_data['score']}/3)")
        problem_data = best_data["data"].copy()
        
        # Keep only results that actually exist in file system, but preserve metadata from existing results
        file_system_ids = {r["submission_id"] for r in file_system_results}
        existing_results = problem_data.get("results", [])
        
        # Merge results: file system as primary, existing data provides additional metadata
        final_results = []
        for fs_result in file_system_results:
            # Find matching item in existing results
            matching_result = None
            for existing_result in existing_results:
                if str(existing_result.get("submission_id")) == fs_result["submission_id"]:
                    matching_result = existing_result.copy()
                    break
            
            if matching_result:
                # Merge: file system data takes priority, but preserve existing additional metadata
                matching_result.update(fs_result)
                final_results.append(matching_result)
            else:
                # Only file system data
                final_results.append(fs_result)
        
        problem_data["results"] = final_results
    else:
        print(f"  No data found for {problem_id} in existing JSON files, creating new entry")
        problem_data = {
            "problem_description": "",
            "reducer_code": "",
            "results": file_system_results
        }
    
    # 4. Try to get missing reducer_code
    if not problem_data.get("reducer_code"):
        reducer_file = os.path.join(problem_id, "reducer.py")
        if os.path.exists(reducer_file):
            try:
                with open(reducer_file, 'r', encoding='utf-8') as f:
                    problem_data["reducer_code"] = f.read()
                print(f"  Read reducer code from {reducer_file}")
            except Exception as e:
                print(f"  [Warning] Cannot read {reducer_file}: {e}")
    
    # 5. Try to get missing problem_description
    if not problem_data.get("problem_description"):
        # Try to get from cache
        cache_path = f".atcoder_cache/problems/{problem_id[:6]}/{problem_id}/description.md"
        if os.path.exists(cache_path):
            try:
                with open(cache_path, 'r', encoding='utf-8') as f:
                    problem_data["problem_description"] = f.read()
                print(f"  Got problem description from cache")
            except Exception as e:
                print(f"  [Warning] Cannot read cached description: {e}")
    
    return problem_data

def main():
    print(f"Starting to consolidate reduction results for {len(PROBLEMS)} problems...")
    print(f"Output file: {OUTPUT_FILE}")
    
    # Load existing consolidated results (if exists)
    consolidated_data = {}
    if os.path.exists(OUTPUT_FILE):
        print(f"Loading existing consolidated results: {OUTPUT_FILE}")
        consolidated_data = load_json_safe(OUTPUT_FILE) or {}
    
    # Collect data for all problems
    for problem_id in PROBLEMS:
        problem_data = collect_problem_data(problem_id)
        if problem_data:
            consolidated_data[problem_id] = problem_data
            result_count = len(problem_data.get("results", []))
            print(f"  ✓ {problem_id}: {result_count} reduction results")
        else:
            print(f"  ✗ {problem_id}: no reduction results found")
    
    # Save consolidated results
    try:
        with open(OUTPUT_FILE, 'w', encoding='utf-8') as f:
            json.dump(consolidated_data, f, indent=2, ensure_ascii=False)
        
        print(f"\nConsolidation completed!")
        print(f"Output file: {OUTPUT_FILE}")
        print(f"Problems included: {len(consolidated_data)}")
        
        # Statistics
        total_results = sum(len(data.get("results", [])) for data in consolidated_data.values())
        print(f"Total reduction results: {total_results}")
        
        # Show result count by problem
        print("\nResult count by problem:")
        for problem_id, data in consolidated_data.items():
            result_count = len(data.get("results", []))
            print(f"  {problem_id}: {result_count} results")
            
    except Exception as e:
        print(f"[Error] Save failed: {e}")
        sys.exit(1)

if __name__ == "__main__":
    main() 
