#!/usr/bin/env python3
"""
Rename and minimize repair result files
1. Backup original files to temp/
2. Create minimized versions with new names
3. Keep only essential fields for analysis
"""

import json
import shutil
import os

# Mapping: old filename -> new filename
FILE_MAPPING = {
    'result_coder7b_qwen2.5-coder-7b-instruct.json': 'result_repair_qwen25-coder7b.json',
    'result_qwenplus-glm4-9b.json': 'result_repair_glm4-9b.json',
    'result_qwenplus-qwenplus.json': 'result_repair_qwenplus.json',
    'result_qwenplus-deepseekv3.json': 'result_repair_deepseekv3.json',
}

# Fields to keep in minimized version
ESSENTIAL_FIELDS = {
    'problem': ['problem_id'],  # At problem level
    'result': ['submission_id'],  # At result level
    'evaluation': ['no_tc', 'orig_tc', 'reduced_tc'],  # At evaluation level
    'strategy': ['versions'],  # At strategy level (no_tc/orig_tc/reduced_tc)
    'version': ['version', 'passed', 'status'],  # At version level
}

def minimize_data(data):
    """Remove unnecessary fields from the data"""
    minimized = {}
    
    for problem_id, problem_data in data.items():
        minimized[problem_id] = {'problem_id': problem_id}
        
        if 'results' in problem_data:
            minimized[problem_id]['results'] = []
            
            for result in problem_data['results']:
                min_result = {
                    'submission_id': result.get('submission_id', '')
                }
                
                if 'evaluation' in result:
                    min_result['evaluation'] = {}
                    eval_data = result['evaluation']
                    
                    for strategy in ['no_tc', 'orig_tc', 'reduced_tc']:
                        if strategy in eval_data:
                            strategy_data = eval_data[strategy]
                            
                            # Keep only versions array
                            if 'versions' in strategy_data:
                                min_result['evaluation'][strategy] = {
                                    'versions': []
                                }
                                
                                for version in strategy_data['versions']:
                                    min_version = {
                                        'version': version.get('version'),
                                        'passed': version.get('passed', False),
                                        'status': version.get('status', '')
                                    }
                                    min_result['evaluation'][strategy]['versions'].append(min_version)
                
                minimized[problem_id]['results'].append(min_result)
    
    return minimized

def process_file(old_name, new_name):
    """Process a single file: backup and minimize"""
    if not os.path.exists(old_name):
        print(f"✗ {old_name} not found, skipping")
        return False
    
    # Create temp directory if not exists
    os.makedirs('temp', exist_ok=True)
    
    # Backup original file
    backup_name = os.path.join('temp', old_name)
    print(f"📦 Backing up {old_name} to {backup_name}")
    shutil.copy2(old_name, backup_name)
    
    # Load data
    print(f"📖 Loading {old_name}...")
    with open(old_name, 'r') as f:
        data = json.load(f)
    
    original_size = os.path.getsize(old_name)
    
    # Minimize data
    print(f"✂️  Minimizing data...")
    minimized = minimize_data(data)
    
    # Save minimized version with new name
    print(f"💾 Saving minimized version as {new_name}")
    with open(new_name, 'w') as f:
        json.dump(minimized, f, indent=2)
    
    new_size = os.path.getsize(new_name)
    reduction = (1 - new_size / original_size) * 100
    
    print(f"✓ Complete: {original_size / 1024 / 1024:.1f}MB → {new_size / 1024 / 1024:.1f}MB (reduced {reduction:.1f}%)")
    print()
    
    return True

def main():
    print("="*80)
    print("Renaming and Minimizing Repair Result Files")
    print("="*80)
    print()
    
    success_count = 0
    total_count = len(FILE_MAPPING)
    
    for old_name, new_name in FILE_MAPPING.items():
        if process_file(old_name, new_name):
            success_count += 1
    
    print("="*80)
    print(f"Summary: {success_count}/{total_count} files processed")
    print("="*80)
    print()
    print("✓ Original files backed up to: temp/")
    print("✓ Minimized files created with new names")
    print()
    print("Next steps:")
    print("  1. Update rq2.sh to use new filenames")
    print("  2. Update analyze_rq2_table.py to use new filenames")
    print()

if __name__ == "__main__":
    main()

