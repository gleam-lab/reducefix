#!/usr/bin/env python3
"""
Verify Python dataset import integrity
Checks that all artifact directories and result data are correctly imported
"""

import os
import json
from pathlib import Path

def main():
    print("="*70)
    print("Verifying Python Dataset Import")
    print("="*70)
    
    # Check result file
    result_file = "result_python_repairs.json"
    if not os.path.exists(result_file):
        print(f"✗ Result file not found: {result_file}")
        print("  Run: python3 import_python_results.py")
        return False
    
    print(f"✓ Found result file: {result_file}")
    
    # Load results
    with open(result_file, 'r') as f:
        data = json.load(f)
    
    total_problems = len(data)
    total_submissions = sum(len(p.get('results', [])) for p in data.values())
    
    print(f"  Problems: {total_problems}")
    print(f"  Submissions: {total_submissions}")
    print("")
    
    # Verify artifact directories
    print("Checking artifact directories...")
    missing_dirs = []
    incomplete_dirs = []
    valid_dirs = 0
    
    for problem_id, problem_data in data.items():
        for result in problem_data.get('results', []):
            submission_id = result.get('submission_id')
            artifact_dir = result.get('artifact_dir', '')
            
            if not artifact_dir:
                missing_dirs.append(f"{problem_id}/{submission_id} (no path)")
                continue
            
            if not os.path.exists(artifact_dir):
                missing_dirs.append(f"{problem_id}/{submission_id} → {artifact_dir}")
                continue
            
            # Check for expected files
            expected_patterns = [
                f"{submission_id}.fixed_code_no_tc_v*.py",
                f"{submission_id}.fixed_code_orig_tc_v*.py",
                f"{submission_id}.fixed_code_reduced_tc_v*.py"
            ]
            
            all_files = os.listdir(artifact_dir)
            python_files = [f for f in all_files if f.endswith('.py')]
            
            if len(python_files) < 10:  # Should have at least 10 repair attempts
                incomplete_dirs.append(f"{artifact_dir} (only {len(python_files)} .py files)")
            else:
                valid_dirs += 1
    
    if missing_dirs:
        print(f"\n✗ Missing directories ({len(missing_dirs)}):")
        for d in missing_dirs[:5]:
            print(f"  - {d}")
        if len(missing_dirs) > 5:
            print(f"  ... and {len(missing_dirs) - 5} more")
    else:
        print(f"✓ All artifact directories present")
    
    if incomplete_dirs:
        print(f"\n⚠ Incomplete directories ({len(incomplete_dirs)}):")
        for d in incomplete_dirs[:5]:
            print(f"  - {d}")
        if len(incomplete_dirs) > 5:
            print(f"  ... and {len(incomplete_dirs) - 5} more")
    
    print(f"\n✓ Valid directories: {valid_dirs}/{total_submissions}")
    print("")
    
    # Check evaluation results
    print("Checking evaluation results...")
    strategies = ['no_tc', 'orig_tc', 'reduced_tc']
    strategy_counts = {s: 0 for s in strategies}
    
    for problem_id, problem_data in data.items():
        for result in problem_data.get('results', []):
            evaluation = result.get('evaluation', {})
            for strategy in strategies:
                if strategy in evaluation:
                    versions = evaluation[strategy].get('versions', [])
                    if versions:
                        strategy_counts[strategy] += 1
    
    for strategy, count in strategy_counts.items():
        print(f"  {strategy:<15} {count}/{total_submissions} submissions")
    
    print("")
    
    # Summary
    all_valid = (len(missing_dirs) == 0 and 
                 len(incomplete_dirs) == 0 and 
                 all(c > 0 for c in strategy_counts.values()))
    
    print("="*70)
    if all_valid:
        print("✓ All checks passed!")
        print("  Python dataset is ready for analysis")
        print("")
        print("Next steps:")
        print("  python3 analyze_rq2_combined.py <cpp_result>.json result_python_repairs.json")
    else:
        print("⚠ Some issues detected")
        print("  Consider re-running: python3 import_python_results.py")
    print("="*70)
    
    return all_valid

if __name__ == "__main__":
    success = main()
    exit(0 if success else 1)

