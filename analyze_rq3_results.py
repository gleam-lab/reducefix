#!/usr/bin/env python3
"""
Analyze RQ3 prompt composition results
"""
import json
import os
import glob
import statistics
from math import comb
from collections import defaultdict

# Difficulty mapping (b and c are both Easy)
DIFFICULTY_MAP = {
    'b': 'C',  # Easy (includes both b and c)
    'c': 'C',
    'd': 'D',
    'e': 'E&F',
    'f': 'E&F'
}

def calculate_passk_unbiased(versions, k):
    """Calculate unbiased pass@k"""
    if not versions:
        return 0.0
    
    n = len(versions)
    c = sum(1 for v in versions if v.get('passed', False))
    
    if c == 0:
        return 0.0
    if n - c < k:
        return 1.0
    
    try:
        return 1.0 - (comb(n - c, k) / comb(n, k))
    except (ValueError, ZeroDivisionError):
        return 0.0

def get_difficulty(problem_id):
    """Extract difficulty from problem ID"""
    letter = problem_id[-1]
    return DIFFICULTY_MAP.get(letter, 'Unknown')

def measure_prompt_stats(strategy_key, sample_size=None):
    """
    Measure actual prompt file statistics using mean (unified rule).
    """
    pattern = f"results/*/*/*.prompt_{strategy_key}_*coder7b*.txt"
    all_files = glob.glob(pattern)
    
    # Use all files if sample_size is None, otherwise sample
    files = all_files if sample_size is None else all_files[:sample_size]
    
    if not files:
        return 0.0, 0.0
    
    all_lines = []
    all_sizes = []
    
    for fpath in files:
        try:
            with open(fpath, 'r', encoding='utf-8') as f:
                content = f.read()
                lines = content.split('\n')
                # Use total lines (including empty lines)
                all_lines.append(len(lines))
            
            # Get file size
            all_sizes.append(os.path.getsize(fpath))
        except Exception:
            continue
    
    if len(all_lines) == 0:
        return 0.0, 0.0
    
    # Use mean for all strategies (unified rule)
    mean_lines = statistics.mean(all_lines)
    mean_kb = statistics.mean(all_sizes) / 1024
    
    return mean_lines, mean_kb

def analyze_strategy_results(data, strategy_key):
    """Analyze results for a single strategy"""
    by_difficulty = defaultdict(lambda: {'pass1_sum': 0.0, 'pass5_sum': 0.0, 'pass10_sum': 0.0, 'count': 0})
    prompt_lengths = []
    
    for problem_id, problem_data in data.items():
        difficulty = get_difficulty(problem_id)
        
        if 'results' not in problem_data:
            continue
        
        for result in problem_data['results']:
            if 'evaluation' not in result:
                continue
            
            if strategy_key not in result['evaluation']:
                continue
            
            strategy_data = result['evaluation'][strategy_key]
            
            # Get versions
            versions = strategy_data.get('versions', [])
            if not versions:
                continue
            
            # Calculate pass@k
            pass1 = calculate_passk_unbiased(versions, 1)
            pass5 = calculate_passk_unbiased(versions, 5)
            pass10 = calculate_passk_unbiased(versions, 10)
            
            by_difficulty[difficulty]['pass1_sum'] += pass1
            by_difficulty[difficulty]['pass5_sum'] += pass5
            by_difficulty[difficulty]['pass10_sum'] += pass10
            by_difficulty[difficulty]['count'] += 1
            
            # Get prompt length if available
            if 'prompt_length' in strategy_data:
                prompt_lengths.append(strategy_data['prompt_length'])
    
    # Calculate averages
    results = {}
    for diff, stats in by_difficulty.items():
        if stats['count'] > 0:
            results[diff] = {
                'pass@1': (stats['pass1_sum'] / stats['count']) * 100,
                'pass@5': (stats['pass5_sum'] / stats['count']) * 100,
                'pass@10': (stats['pass10_sum'] / stats['count']) * 100,
                'count': stats['count']
            }
    
    # Calculate overall
    total_pass1 = sum(d['pass1_sum'] for d in by_difficulty.values())
    total_pass5 = sum(d['pass5_sum'] for d in by_difficulty.values())
    total_pass10 = sum(d['pass10_sum'] for d in by_difficulty.values())
    total_count = sum(d['count'] for d in by_difficulty.values())
    
    if total_count > 0:
        results['Overall'] = {
            'pass@1': (total_pass1 / total_count) * 100,
            'pass@5': (total_pass5 / total_count) * 100,
            'pass@10': (total_pass10 / total_count) * 100,
            'count': total_count
        }
    
    # Average prompt length
    avg_length = sum(prompt_lengths) / len(prompt_lengths) if prompt_lengths else 0
    
    return results, avg_length

def main():
    print("="*80)
    print("RQ3: Influence of Prompt Composition on Repair Performance")
    print("="*80)
    print()
    
    # Load data (RQ3 uses its own ablation study dataset)
    # Note: This file contains all 5 strategies but only 5 C-difficulty problems
    # (abc361c, abc366c, abc368c, abc376c, abc377c - does NOT include abc375c)
    # This is the correct dataset for RQ3 ablation study as used in the paper
    with open('result_ablation.json', 'r') as f:
        data = json.load(f)
    
    # Strategy mappings
    strategies = {
        'no_tc': 'Baseline',
        'orig_tc': 'Origin Test',
        'diff_only': 'Diff Lines',
        'reduced_tc': 'Reduced Test',
        'reduced_plus_diff': 'Reduced + Origin'
    }
    
    # Analyze each strategy
    all_results = {}
    all_lengths = {}
    
    for strategy_key, strategy_name in strategies.items():
        results, avg_length = analyze_strategy_results(data, strategy_key)
        all_results[strategy_name] = results
        all_lengths[strategy_name] = avg_length
    
    # Measure prompt lengths from actual files
    print("Table 1: Prompt Length Statistics")
    print("Note: Statistics calculated from all actual prompt files using mean.")
    print("-"*80)
    print(f"{'Strategy':<25} {'Mean Lines':>16} {'Mean (KB)':>12}")
    print("-"*80)
    
    prompt_stats = {}
    strategy_keys = {
        'Baseline': 'no_tc',
        'Origin Test': 'orig_tc',
        'Diff Lines': 'diff_only',
        'Reduced Test': 'reduced_tc',
        'Reduced + Origin': 'reduced_plus_diff'
    }
    
    for strategy_name in ['Baseline', 'Origin Test', 'Diff Lines', 'Reduced Test', 'Reduced + Origin']:
        strategy_key = strategy_keys[strategy_name]
        avg_lines, avg_kb = measure_prompt_stats(strategy_key)
        prompt_stats[strategy_name] = {'lines': avg_lines, 'kb': avg_kb}
        print(f"{strategy_name:<25} {avg_lines:>16.1f} {avg_kb:>11.1f}")
    print()
    
    # Print pass@k results
    print("="*80)
    print("Table 2: Pass@k (%) by Difficulty")
    print("="*80)
    print()
    
    # Focus on the three main strategies from the paper
    main_strategies = ['Reduced Test', 'Diff Lines', 'Reduced + Origin']
    difficulties = ['C', 'D', 'E&F', 'Overall']
    
    # Print header
    print(f"{'Difficulty':<12}", end='')
    for strategy in main_strategies:
        print(f" | {strategy:^24}", end='')
    print()
    
    print(f"{'':12}", end='')
    for _ in main_strategies:
        print(f" | {'@1':>7} {'@5':>7} {'@10':>7}", end='')
    print()
    print("-"*80)
    
    # Print data
    for diff in difficulties:
        print(f"{diff:<12}", end='')
        for strategy in main_strategies:
            if strategy in all_results and diff in all_results[strategy]:
                stats = all_results[strategy][diff]
                p1 = stats['pass@1']
                p5 = stats['pass@5']
                p10 = stats['pass@10']
                print(f" | {p1:>6.1f}% {p5:>6.1f}% {p10:>6.1f}%", end='')
            else:
                print(f" | {'N/A':>7} {'N/A':>7} {'N/A':>7}", end='')
        print()
    
    print()
    print("="*80)
    print("Summary Statistics")
    print("="*80)
    print()
    print("Table 1 - Prompt Lengths (mean of all actual prompt files):")
    for strategy_name in ['Baseline', 'Origin Test', 'Diff Lines', 'Reduced Test', 'Reduced + Origin']:
        stats = prompt_stats.get(strategy_name, {'lines': 0.0, 'kb': 0.0})
        print(f"  {strategy_name:<20} {stats['lines']:>5.1f} lines, {stats['kb']:>5.1f} KB")
    print()
    print("Table 2 - Pass@k by Difficulty:")
    for strategy in main_strategies:
        if strategy in all_results:
            print(f"  {strategy}:")
            for diff in difficulties:
                if diff in all_results[strategy]:
                    stats = all_results[strategy][diff]
                    print(f"    {diff:<8} {stats['pass@1']:>5.1f}% / {stats['pass@5']:>5.1f}% / {stats['pass@10']:>5.1f}%")
            print()
    print("="*80)

if __name__ == '__main__':
    main()
