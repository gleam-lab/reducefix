#!/usr/bin/env python3
"""
Analyze RQ2 results combining C++ and Python datasets
Compares three repair strategies: no_tc, orig_tc, reduced_tc
Reports pass@k metrics for k ∈ {1, 5, 10}
"""

import json
import sys
from collections import defaultdict

def calculate_passk(versions, k):
    """Calculate pass@k: whether ANY of the first k versions passed"""
    if not versions:
        return False
    
    first_k = versions[:k]
    return any(v.get('passed', False) for v in first_k)

def analyze_results(result_file, language):
    """Analyze a single result file (C++ or Python)"""
    try:
        with open(result_file, 'r') as f:
            data = json.load(f)
    except FileNotFoundError:
        print(f"Warning: {result_file} not found", file=sys.stderr)
        return None
    
    stats = {
        'language': language,
        'total_problems': 0,
        'total_submissions': 0,
        'strategies': {
            'no_tc': {'pass@1': 0, 'pass@5': 0, 'pass@10': 0, 'total': 0},
            'orig_tc': {'pass@1': 0, 'pass@5': 0, 'pass@10': 0, 'total': 0},
            'reduced_tc': {'pass@1': 0, 'pass@5': 0, 'pass@10': 0, 'total': 0}
        },
        'by_difficulty': defaultdict(lambda: {
            'no_tc': {'pass@1': 0, 'pass@5': 0, 'pass@10': 0, 'total': 0},
            'orig_tc': {'pass@1': 0, 'pass@5': 0, 'pass@10': 0, 'total': 0},
            'reduced_tc': {'pass@1': 0, 'pass@5': 0, 'pass@10': 0, 'total': 0}
        })
    }
    
    for problem_id, problem_data in data.items():
        if 'results' not in problem_data:
            continue
        
        stats['total_problems'] += 1
        
        # Determine difficulty from problem_id
        # abc3XXc/d/e/f pattern: c=Easy, d/e=Medium, f=Hard
        problem_letter = problem_id[-1]
        if problem_letter == 'c':
            difficulty = 'Easy'
        elif problem_letter in ['d', 'e']:
            difficulty = 'Medium'
        else:
            difficulty = 'Hard'
        
        for result in problem_data['results']:
            stats['total_submissions'] += 1
            
            evaluation = result.get('evaluation', {})
            
            for strategy in ['no_tc', 'orig_tc', 'reduced_tc']:
                if strategy not in evaluation:
                    continue
                
                versions = evaluation[strategy].get('versions', [])
                if not versions:
                    continue
                
                # Count for overall stats
                stats['strategies'][strategy]['total'] += 1
                stats['by_difficulty'][difficulty][strategy]['total'] += 1
                
                # Calculate pass@k
                for k in [1, 5, 10]:
                    if calculate_passk(versions, k):
                        stats['strategies'][strategy][f'pass@{k}'] += 1
                        stats['by_difficulty'][difficulty][strategy][f'pass@{k}'] += 1
    
    return stats

def print_comparison_table(cpp_stats, py_stats):
    """Print comparison table for C++ and Python results"""
    print("\n" + "="*100)
    print("RQ2: Impact of Reduced Test Cases on Repair Success (Combined C++ & Python)")
    print("="*100)
    
    # Overall statistics
    print("\nOverall Statistics:")
    print("-"*100)
    print(f"{'Language':<12} {'Problems':<12} {'Submissions':<15} {'Repair Attempts':<20}")
    print("-"*100)
    
    if cpp_stats:
        total_repairs = sum(cpp_stats['strategies'][s]['total'] for s in ['no_tc', 'orig_tc', 'reduced_tc'])
        print(f"{'C++':<12} {cpp_stats['total_problems']:<12} {cpp_stats['total_submissions']:<15} {total_repairs:<20}")
    
    if py_stats:
        total_repairs = sum(py_stats['strategies'][s]['total'] for s in ['no_tc', 'orig_tc', 'reduced_tc'])
        print(f"{'Python':<12} {py_stats['total_problems']:<12} {py_stats['total_submissions']:<15} {total_repairs:<20}")
    
    print("-"*100)
    
    # Pass@k results for each language and strategy
    for stats, lang in [(cpp_stats, 'C++'), (py_stats, 'Python')]:
        if not stats:
            continue
        
        print(f"\n{lang} Results:")
        print("-"*100)
        print(f"{'Strategy':<20} {'Total':<10} {'pass@1':<15} {'pass@5':<15} {'pass@10':<15}")
        print("-"*100)
        
        for strategy_name, display_name in [
            ('no_tc', 'Baseline (no TC)'),
            ('orig_tc', 'Original Test'),
            ('reduced_tc', 'Reduced Test')
        ]:
            s = stats['strategies'][strategy_name]
            if s['total'] == 0:
                continue
            
            pass1_rate = (s['pass@1'] / s['total'] * 100) if s['total'] > 0 else 0
            pass5_rate = (s['pass@5'] / s['total'] * 100) if s['total'] > 0 else 0
            pass10_rate = (s['pass@10'] / s['total'] * 100) if s['total'] > 0 else 0
            
            print(f"{display_name:<20} {s['total']:<10} "
                  f"{s['pass@1']}/{s['total']} ({pass1_rate:>5.1f}%)  "
                  f"{s['pass@5']}/{s['total']} ({pass5_rate:>5.1f}%)  "
                  f"{s['pass@10']}/{s['total']} ({pass10_rate:>5.1f}%)")
        
        print("-"*100)
        
        # By difficulty
        print(f"\n{lang} Results by Difficulty:")
        print("-"*100)
        
        for difficulty in ['Easy', 'Medium', 'Hard']:
            if difficulty not in stats['by_difficulty']:
                continue
            
            diff_data = stats['by_difficulty'][difficulty]
            
            # Check if this difficulty has any data
            if all(diff_data[s]['total'] == 0 for s in ['no_tc', 'orig_tc', 'reduced_tc']):
                continue
            
            print(f"\n{difficulty} Problems:")
            print(f"{'  Strategy':<20} {'Total':<10} {'pass@1':<15} {'pass@5':<15} {'pass@10':<15}")
            
            for strategy_name, display_name in [
                ('no_tc', '  Baseline'),
                ('orig_tc', '  Original Test'),
                ('reduced_tc', '  Reduced Test')
            ]:
                s = diff_data[strategy_name]
                if s['total'] == 0:
                    continue
                
                pass1_rate = (s['pass@1'] / s['total'] * 100) if s['total'] > 0 else 0
                pass5_rate = (s['pass@5'] / s['total'] * 100) if s['total'] > 0 else 0
                pass10_rate = (s['pass@10'] / s['total'] * 100) if s['total'] > 0 else 0
                
                print(f"{display_name:<20} {s['total']:<10} "
                      f"{s['pass@1']}/{s['total']} ({pass1_rate:>5.1f}%)  "
                      f"{s['pass@5']}/{s['total']} ({pass5_rate:>5.1f}%)  "
                      f"{s['pass@10']}/{s['total']} ({pass10_rate:>5.1f}%)")
    
    print("\n" + "="*100)
    print("Key Findings:")
    print("="*100)
    
    # Calculate improvements
    if cpp_stats:
        no_tc = cpp_stats['strategies']['no_tc']
        reduced = cpp_stats['strategies']['reduced_tc']
        
        if no_tc['total'] > 0 and reduced['total'] > 0:
            baseline_pass1 = no_tc['pass@1'] / no_tc['total']
            reduced_pass1 = reduced['pass@1'] / reduced['total']
            improvement = ((reduced_pass1 - baseline_pass1) / baseline_pass1 * 100) if baseline_pass1 > 0 else 0
            
            print(f"✓ C++ Reduced Test improves pass@1 by {improvement:+.1f}% over Baseline")
    
    if py_stats:
        no_tc = py_stats['strategies']['no_tc']
        reduced = py_stats['strategies']['reduced_tc']
        
        if no_tc['total'] > 0 and reduced['total'] > 0:
            baseline_pass1 = no_tc['pass@1'] / no_tc['total']
            reduced_pass1 = reduced['pass@1'] / reduced['total']
            improvement = ((reduced_pass1 - baseline_pass1) / baseline_pass1 * 100) if baseline_pass1 > 0 else 0
            
            print(f"✓ Python Reduced Test improves pass@1 by {improvement:+.1f}% over Baseline")
    
    print("="*100)

def main():
    # Default file paths
    cpp_result_file = "result_qwen25-coder7b.json"  # Adjust based on your actual file
    py_result_file = "result_python_repairs.json"
    
    # Allow command line override
    if len(sys.argv) > 1:
        cpp_result_file = sys.argv[1]
    if len(sys.argv) > 2:
        py_result_file = sys.argv[2]
    
    print("Analyzing RQ2 Results...")
    print(f"C++ results: {cpp_result_file}")
    print(f"Python results: {py_result_file}")
    
    cpp_stats = analyze_results(cpp_result_file, 'C++')
    py_stats = analyze_results(py_result_file, 'Python')
    
    if not cpp_stats and not py_stats:
        print("Error: No result files found", file=sys.stderr)
        sys.exit(1)
    
    print_comparison_table(cpp_stats, py_stats)

if __name__ == "__main__":
    main()

