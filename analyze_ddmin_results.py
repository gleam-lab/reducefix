#!/usr/bin/env python3
"""
Analyze DDMin-based ReduceFix repair results
Reuses the same analysis logic as analyze_rq2_table.py
"""

import json
import sys
from collections import defaultdict
from math import comb

# Difficulty mapping: problem_letter -> difficulty label
DIFFICULTY_MAP = {
    'c': 'C',      # Easy
    'd': 'D',      # Medium (D)
    'e': 'E&F',    # Hard (E&F)
    'f': 'E&F'     # Hard (E&F)
}

def calculate_passk_unbiased(versions, k):
    """
    Calculate unbiased pass@k using the formula:
    pass@k = 1 - C(n-c, k) / C(n, k)
    """
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

def analyze_ddmin_results(result_file):
    """Analyze DDMin results using unbiased pass@k"""
    try:
        with open(result_file, 'r') as f:
            data = json.load(f)
    except FileNotFoundError:
        print(f"Error: File not found: {result_file}", file=sys.stderr)
        return None
    
    # Structure: stats[strategy][difficulty] = {'total': count, 'pass@1_sum': sum, ...}
    stats = defaultdict(lambda: defaultdict(lambda: {
        'total': 0, 
        'pass@1_sum': 0.0, 
        'pass@5_sum': 0.0, 
        'pass@10_sum': 0.0
    }))
    
    for problem_id, problem_data in data.items():
        if 'results' not in problem_data:
            continue
        
        # Get difficulty from problem_id (last character)
        problem_letter = problem_id[-1].lower()
        difficulty = DIFFICULTY_MAP.get(problem_letter, 'Unknown')
        
        for result in problem_data['results']:
            evaluation = result.get('evaluation', {})
            
            for strategy in ['no_tc', 'orig_tc', 'reduced_tc']:
                if strategy not in evaluation:
                    continue
                
                versions = evaluation[strategy].get('versions', [])
                if not versions:
                    continue
                
                # Count this submission
                stats[strategy][difficulty]['total'] += 1
                stats[strategy]['Overall']['total'] += 1
                
                # Calculate unbiased pass@k and accumulate
                for k in [1, 5, 10]:
                    prob = calculate_passk_unbiased(versions, k)
                    stats[strategy][difficulty][f'pass@{k}_sum'] += prob
                    stats[strategy]['Overall'][f'pass@{k}_sum'] += prob
    
    # Convert sums to averages and percentages
    final_stats = defaultdict(lambda: defaultdict(dict))
    for strategy in stats:
        for difficulty in stats[strategy]:
            total = stats[strategy][difficulty]['total']
            if total > 0:
                final_stats[strategy][difficulty] = {
                    'total': total,
                    'pass@1': stats[strategy][difficulty]['pass@1_sum'] / total * 100,
                    'pass@5': stats[strategy][difficulty]['pass@5_sum'] / total * 100,
                    'pass@10': stats[strategy][difficulty]['pass@10_sum'] / total * 100,
                }
            else:
                final_stats[strategy][difficulty] = {
                    'total': 0,
                    'pass@1': 0.0,
                    'pass@5': 0.0,
                    'pass@10': 0.0,
                }
    
    return final_stats

def print_ddmin_summary(stats):
    """Print DDMin analysis results"""
    if not stats:
        print("No results to display")
        return
    
    print("-"*100)
    print(f"{'Difficulty':<12} {'Strategy':<15} {'Total':<8} {'pass@1':<15} {'pass@5':<15} {'pass@10':<15}")
    print("-"*100)
    
    for difficulty in ['C', 'D', 'E&F', 'Overall']:
        first_strategy = True
        for strategy_key, strategy_name in [
            ('no_tc', 'Baseline'),
            ('orig_tc', 'Origin Test'),
            ('reduced_tc', 'Reduced Test')
        ]:
            s = stats[strategy_key].get(difficulty)
            if not s or s['total'] == 0:
                continue
            
            # Values are already percentages
            p1 = s['pass@1']
            p5 = s['pass@5']
            p10 = s['pass@10']
            
            diff_str = difficulty if first_strategy else ''
            first_strategy = False
            
            print(f"{diff_str:<12} {strategy_name:<15} {s['total']:<8} "
                  f"{p1:>6.1f}%        {p5:>6.1f}%        {p10:>6.1f}%")
        
        if difficulty != 'Overall':
            print()
    
    print("-"*100)

def main():
    result_file = "result_ddmin_repair_qwen2.5-coder-7b.json"
    
    print(f"Analyzing DDMin results: {result_file}")
    stats = analyze_ddmin_results(result_file)
    
    if stats:
        print_ddmin_summary(stats)
    else:
        sys.exit(1)

if __name__ == "__main__":
    main()

