#!/usr/bin/env python3
"""
Integrate CRef results into RQ4
1. Copy and minimize CRef result file
2. Rename to consistent format
"""

import json
import os
import shutil

def minimize_repair_data(data):
    """Remove unnecessary fields from repair evaluation data"""
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
                    
                    # Keep error field if present
                    if 'error' in eval_data:
                        min_result['evaluation']['error'] = eval_data['error']
                    
                    # Process all strategy keys (auto-detect, not hardcoded)
                    for strategy_key, strategy_data in eval_data.items():
                        if strategy_key == 'error':
                            continue
                        
                        if isinstance(strategy_data, dict) and 'version_results' in strategy_data:
                            min_result['evaluation'][strategy_key] = {
                                'version_results': []
                            }
                            
                            for version in strategy_data['version_results']:
                                min_version = {
                                    'version': version.get('version'),
                                    'passed': version.get('passed', False),
                                    'status': version.get('status', '')
                                }
                                min_result['evaluation'][strategy_key]['version_results'].append(min_version)
                
                minimized[problem_id]['results'].append(min_result)
    
    return minimized

def main():
    print("="*80)
    print("Integrating CRef Results into RQ4")
    print("="*80)
    print()
    
    # Source and destination paths
    source_file = '../reduce/result_cref_cref.json'
    dest_file = 'result_cref.json'
    backup_dir = 'temp'
    
    # Check if source exists
    if not os.path.exists(source_file):
        print(f"✗ Source file not found: {source_file}")
        return
    
    print(f"📖 Loading CRef results from {source_file}...")
    with open(source_file, 'r') as f:
        data = json.load(f)
    
    original_size = os.path.getsize(source_file)
    print(f"   Original size: {original_size / 1024:.1f} KB")
    print(f"   Total problems: {len(data)}")
    
    # Detect strategies
    strategies = set()
    for problem_data in data.values():
        if 'results' in problem_data:
            for result in problem_data['results']:
                if 'evaluation' in result:
                    for key in result['evaluation'].keys():
                        if key != 'error':
                            strategies.add(key)
    
    print(f"   Detected strategies: {', '.join(sorted(strategies))}")
    print()
    
    # Minimize data
    print("✂️  Minimizing data...")
    minimized = minimize_repair_data(data)
    
    # Backup original to temp
    os.makedirs(backup_dir, exist_ok=True)
    backup_file = os.path.join(backup_dir, 'result_cref_cref_full.json')
    print(f"📦 Backing up original to {backup_file}...")
    shutil.copy2(source_file, backup_file)
    
    # Save minimized version
    print(f"💾 Saving minimized version as {dest_file}...")
    with open(dest_file, 'w') as f:
        json.dump(minimized, f, indent=2)
    
    new_size = os.path.getsize(dest_file)
    reduction = (1 - new_size / original_size) * 100
    
    print(f"✓ Complete: {original_size / 1024:.1f}KB → {new_size / 1024:.1f}KB (reduced {reduction:.1f}%)")
    print()
    
    print("="*80)
    print("CRef Results Integration Complete")
    print("="*80)
    print()
    print("Files created:")
    print(f"  • {dest_file} - minimized result file")
    print(f"  • {backup_file} - full backup")
    print()
    print("Next steps:")
    print("  1. Update rq4.sh to include CRef analysis")
    print("  2. Run: python3 summarize_chatrepair_results.py cref")
    print()

if __name__ == "__main__":
    main()

