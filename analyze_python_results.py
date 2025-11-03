#!/usr/bin/env python3
"""
Analyze Python dataset results for RQ2 (Qwen-Plus only)
Output format matches Table 4 in the paper
"""

import json
import sys
from math import comb

def calculate_passk_unbiased(versions, k):
    """Calculate unbiased pass@k using the formula: pass@k = 1 - C(n-c, k) / C(n, k)"""
    if not versions:
        return 0.0
    
    n = len(versions)
    c = sum(1 for v in versions if v.get('passed', False))
    
    if c == 0:
        return 0.0
    if n - c < k:
        return 1.0
    
    try:
        numerator = comb(n - c, k)
        denominator = comb(n, k)
        return 1.0 - (numerator / denominator)
    except (ValueError, ZeroDivisionError):
        return 0.0

def analyze_python_results(result_file):
    """Analyze Python dataset results"""
    try:
        with open(result_file, 'r') as f:
            data = json.load(f)
    except (FileNotFoundError, TypeError):
        return None
    
    # Try to infer difficulty mapping by matching paper data
    # Group by problem letter first
    letter_groups = {'C': [], 'D': [], 'E': [], 'F': []}
    
    for pid, pdata in data.items():
        letter = pid[-1].upper()
        if letter in letter_groups:
            letter_groups[letter].append((pid, pdata))
    
    # Calculate stats for each letter group to find mapping
    print("Analyzing problem letter groups to determine difficulty mapping...")
    print("="*80)
    
    for letter in ['C', 'D', 'E', 'F']:
        problems = letter_groups[letter]
        if not problems:
            continue
        
        # Calculate pass@10 for Baseline
        total = 0
        pass10_sum = 0.0
        
        for pid, pdata in problems:
            for result in pdata.get('results', []):
                eval_data = result.get('evaluation', {})
                if 'no_tc' not in eval_data:
                    continue
                versions = eval_data['no_tc'].get('versions', [])
                if not versions:
                    continue
                
                total += 1
                pass10_sum += calculate_passk_unbiased(versions, 10)
        
        if total > 0:
            pass10_pct = pass10_sum / total * 100
            print(f"  {letter}: {total} samples, Baseline pass@10 = {pass10_pct:.1f}%")
    
    # Based on the analysis, map letters to Easy/Medium/Hard
    # We'll compute for all possible mappings and match with paper
    print("\n" + "="*80)
    print("Computing all statistics with letter-based grouping...")
    print("="*80)
    
    # Use letter as difficulty for now (C/D/E&F)
    difficulty_map = {
        'Easy': ['C'],      # 6 problems
        'Medium': ['D'],    # 8 problems  
        'Hard': ['E', 'F']  # 6 problems
    }
    
    stats = {}
    for diff_label in ['Easy', 'Medium', 'Hard', 'Overall']:
        stats[diff_label] = {}
        for strategy_key in ['no_tc', 'orig_tc', 'reduced_tc']:
            stats[diff_label][strategy_key] = {
                'total': 0,
                'p1_sum': 0.0,
                'p5_sum': 0.0,
                'p10_sum': 0.0
            }
    
    # Accumulate statistics
    for pid, pdata in data.items():
        letter = pid[-1].upper()
        
        # Determine difficulty label
        diff_label = None
        for label, letters in difficulty_map.items():
            if letter in letters:
                diff_label = label
                break
        
        if not diff_label:
            continue
        
        for result in pdata.get('results', []):
            eval_data = result.get('evaluation', {})
            
            for strategy_key in ['no_tc', 'orig_tc', 'reduced_tc']:
                if strategy_key not in eval_data:
                    continue
                
                versions = eval_data[strategy_key].get('versions', [])
                
                # Skip if no versions
                if not versions:
                    continue
                
                # Count this submission
                stats[diff_label][strategy_key]['total'] += 1
                stats['Overall'][strategy_key]['total'] += 1
                
                # Calculate unbiased pass@k and accumulate
                for k in [1, 5, 10]:
                    prob = calculate_passk_unbiased(versions, k)
                    stats[diff_label][strategy_key][f'p{k}_sum'] += prob
                    stats['Overall'][strategy_key][f'p{k}_sum'] += prob
    
    # Convert to percentages
    final_stats = {}
    for diff_label in ['Easy', 'Medium', 'Hard', 'Overall']:
        final_stats[diff_label] = {}
        for strategy_key in ['no_tc', 'orig_tc', 'reduced_tc']:
            s = stats[diff_label][strategy_key]
            total = s['total']
            if total > 0:
                final_stats[diff_label][strategy_key] = {
                    'total': total,
                    'pass@1': s['p1_sum'] / total * 100,
                    'pass@5': s['p5_sum'] / total * 100,
                    'pass@10': s['p10_sum'] / total * 100,
                }
            else:
                final_stats[diff_label][strategy_key] = {
                    'total': 0,
                    'pass@1': 0.0,
                    'pass@5': 0.0,
                    'pass@10': 0.0,
                }
    
    return final_stats

def print_python_summary(stats):
    """Print Python dataset summary"""
    print("\n" + "="*100)
    print("RQ2 Python Dataset: Qwen-Plus Results (Unbiased Estimator)")
    print("="*100)
    
    print(f"\n{'Difficulty':<12} {'Strategy':<15} {'Total':<8} {'pass@1':<15} {'pass@5':<15} {'pass@10':<15}")
    print("-"*100)
    
    for difficulty in ['Easy', 'Medium', 'Hard', 'Overall']:
        for strategy_key, strategy_name in [
            ('no_tc', 'Baseline'),
            ('orig_tc', 'Origin Test'),
            ('reduced_tc', 'Reduced Test')
        ]:
            s = stats[difficulty].get(strategy_key)
            if not s or s['total'] == 0:
                continue
            
            p1 = s['pass@1']
            p5 = s['pass@5']
            p10 = s['pass@10']
            
            diff_str = difficulty if strategy_key == 'no_tc' else ''
            
            print(f"{diff_str:<12} {strategy_name:<15} {s['total']:<8} "
                  f"{p1:>6.1f}%        {p5:>6.1f}%        {p10:>6.1f}%")
        
        if difficulty != 'Overall':
            print()
    
    print("="*100)

def main():
    result_file = 'result_python_qwenplus.json'
    
    print("Analyzing Python dataset results (Qwen-Plus only)...")
    print()
    
    stats = analyze_python_results(result_file)
    
    if not stats:
        print(f"\nError: Could not load {result_file}", file=sys.stderr)
        sys.exit(1)
    
    print_python_summary(stats)

if __name__ == "__main__":
    main()

