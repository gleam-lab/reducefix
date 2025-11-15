#!/usr/bin/env python3
"""
Compare RQ1 results: ReduceFix vs DDmin-only
Generates comparison table for paper
"""

import json
import sys
import os
from collections import defaultdict
import statistics

def parse_problem_difficulty(problem_id):
    """Parse difficulty level from problem ID suffix"""
    if problem_id and len(problem_id) > 0:
        suffix = problem_id[-1].lower()
        if suffix in ['b', 'c']:
            return 'Easy'
        elif suffix == 'd':
            return 'Medium'
        elif suffix in ['e', 'f']:
            return 'Hard'
    return None

def get_input_format_category(problem_id):
    """Map problem ID to input format category"""
    # Based on Table 3 in the paper
    categories = {
        'Sequence': ['abc361c', 'abc367d', 'abc368c', 'abc369d', 
                     'abc370d', 'abc373e', 'abc377c', 'abc377f'],
        'Multiple sequences': ['abc374e', 'abc375c', 'abc376c', 'abc376e'],
        'Sequence with dependencies': ['abc364d', 'abc366c', 'abc372e', 'abc371d'],
        '2-D matrix': ['abc363e'],
        'Graph': ['abc362d', 'abc376d'],
        'String': ['abc365d']
    }
    
    for category, problems in categories.items():
        if problem_id in problems:
            return category
    return None

def calculate_compression_ratio(original_size, reduced_size):
    """Calculate compression ratio as (1 - reduced/original)"""
    if original_size == 0:
        return 0.0
    return (original_size - reduced_size) / original_size

def analyze_results(file_path, method_name):
    """Analyze results for one method"""
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            data = json.load(f)
    except Exception as e:
        print(f"Error loading {file_path}: {e}", file=sys.stderr)
        return None
    
    stats = {
        'method': method_name,
        'total_attempts': 0,
        'successful_reductions': 0,
        'compression_ratios': [],
        'difficulty_stats': defaultdict(lambda: {
            'attempts': 0,
            'successful': 0,
            'compression_ratios': []
        }),
        'format_stats': defaultdict(lambda: {
            'attempts': 0,
            'successful': 0,
            'compression_ratios': []
        })
    }
    
    for problem_id, problem_data in data.items():
        if not isinstance(problem_data, dict):
            continue
        
        difficulty = parse_problem_difficulty(problem_id)
        input_format = get_input_format_category(problem_id)
        results = problem_data.get('results', [])
        
        for result in results:
            stats['total_attempts'] += 1
            if difficulty:
                stats['difficulty_stats'][difficulty]['attempts'] += 1
            if input_format:
                stats['format_stats'][input_format]['attempts'] += 1
            
            status_code = result.get('status_code', 0)
            original_size = result.get('original_size_bytes')
            reduced_size = result.get('reduced_size_bytes')
            
            if status_code == 200 and original_size and reduced_size:
                if reduced_size < original_size:
                    stats['successful_reductions'] += 1
                    if difficulty:
                        stats['difficulty_stats'][difficulty]['successful'] += 1
                    if input_format:
                        stats['format_stats'][input_format]['successful'] += 1
                    
                    compression_ratio = calculate_compression_ratio(original_size, reduced_size)
                    stats['compression_ratios'].append(compression_ratio)
                    if difficulty:
                        stats['difficulty_stats'][difficulty]['compression_ratios'].append(compression_ratio)
                    if input_format:
                        stats['format_stats'][input_format]['compression_ratios'].append(compression_ratio)
    
    return stats

def print_comparison_table_three(reducefix_stats, ddmin_stats, llm_stats):
    """Print comparison table for all three methods"""
    print("\n" + "="*120)
    print("RQ1: Comparison of Three Test Case Reduction Approaches")
    print("="*120)
    print()
    
    # Overall comparison
    print("Overall Performance:")
    print("-" * 120)
    print(f"{'Method':<25} {'Success Rate':<20} {'Compression (avg/med)':<35} {'Total':<20}")
    print("-" * 120)
    
    for stats in [reducefix_stats, llm_stats, ddmin_stats]:
        method = stats['method']
        total = stats['total_attempts']
        successful = stats['successful_reductions']
        success_rate = (successful / total * 100) if total > 0 else 0
        
        ratios = stats['compression_ratios']
        avg_compression = statistics.mean(ratios) if ratios else 0
        median_compression = statistics.median(ratios) if ratios else 0
        compression_text = f"{avg_compression:>6.1%} / {median_compression:>6.1%}"
        
        print(f"{method:<25} {success_rate:>6.1f}% ({successful}/{total}){' '*4}"
              f"{compression_text:<35} {total} attempts")
    
    print("-" * 120)
    print()
    
    # By difficulty
    print("Performance by Difficulty:")
    print("-" * 120)
    
    for difficulty in ['Easy', 'Medium', 'Hard']:
        print(f"\n{difficulty} Problems:")
        print(f"{'Method':<25} {'Success Rate':<20} {'Compression (avg/med)':<35}")
        print("-" * 120)
        
        for stats in [reducefix_stats, llm_stats, ddmin_stats]:
            method = stats['method']
            diff_stats = stats['difficulty_stats'].get(difficulty, {})
            
            total = diff_stats.get('attempts', 0)
            successful = diff_stats.get('successful', 0)
            success_rate = (successful / total * 100) if total > 0 else 0
            
            ratios = diff_stats.get('compression_ratios', [])
            avg_compression = statistics.mean(ratios) if ratios else 0
            median_compression = statistics.median(ratios) if ratios else 0
            compression_text = f"{avg_compression:>6.1%} / {median_compression:>6.1%}"
            
            print(f"{method:<25} {success_rate:>6.1f}% ({successful}/{total}){' '*4}"
                  f"{compression_text:<35}")
    
    print("-" * 120)
    print()
    
    # By input format
    print("Performance by Input Format:")
    print("-" * 120)
    
    # Define order of categories as in the paper
    format_order = [
        'Sequence',
        'Multiple sequences',
        'Sequence with dependencies',
        '2-D matrix',
        'Graph',
        'String'
    ]
    
    for input_format in format_order:
        print(f"\n{input_format}:")
        print(f"{'Method':<25} {'Success Rate':<20} {'Compression (avg/med)':<35}")
        print("-" * 120)
        
        for stats in [reducefix_stats, llm_stats, ddmin_stats]:
            method = stats['method']
            format_stats = stats['format_stats'].get(input_format, {})
            
            total = format_stats.get('attempts', 0)
            successful = format_stats.get('successful', 0)
            success_rate = (successful / total * 100) if total > 0 else 0
            
            ratios = format_stats.get('compression_ratios', [])
            avg_compression = statistics.mean(ratios) if ratios else 0
            median_compression = statistics.median(ratios) if ratios else 0
            compression_text = f"{avg_compression:>6.1%} / {median_compression:>6.1%}"
            
            if total > 0:
                print(f"{method:<25} {success_rate:>6.1f}% ({successful}/{total}){' '*4}"
                      f"{compression_text:<35}")
    
    print("-" * 120)
    print()
    
    # Key insights
    print("Key Insights:")
    print("-" * 120)
    
    reducefix_success = reducefix_stats['successful_reductions'] / reducefix_stats['total_attempts']
    ddmin_success = ddmin_stats['successful_reductions'] / ddmin_stats['total_attempts']
    llm_success = llm_stats['successful_reductions'] / llm_stats['total_attempts']
    
    print(f"✓ ReduceFix achieves {reducefix_success*100:.1f}% success rate")
    print(f"✓ Pure LLM achieves {llm_success*100:.1f}% success rate")
    print(f"✓ DDmin-only achieves {ddmin_success*100:.1f}% success rate")
    print()
    print(f"✓ ReduceFix is {reducefix_success/llm_success:.2f}x more reliable than Pure LLM")
    print(f"✓ ReduceFix is {reducefix_success/ddmin_success:.2f}x more reliable than DDmin-only")
    
    print("-" * 120)
    print()

def print_comparison_table(reducefix_stats, ddmin_stats):
    """Print comparison table for RQ1"""
    print("\n" + "="*100)
    print("RQ1: Comparison of Test Case Reduction Approaches")
    print("="*100)
    print()
    
    # Overall comparison
    print("Overall Performance:")
    print("-" * 100)
    print(f"{'Method':<25} {'Success Rate':<20} {'Compression (avg/med)':<35} {'Total':<20}")
    print("-" * 100)
    
    for stats in [reducefix_stats, ddmin_stats]:
        method = stats['method']
        total = stats['total_attempts']
        successful = stats['successful_reductions']
        success_rate = (successful / total * 100) if total > 0 else 0
        
        ratios = stats['compression_ratios']
        avg_compression = statistics.mean(ratios) if ratios else 0
        median_compression = statistics.median(ratios) if ratios else 0
        compression_text = f"{avg_compression:>6.1%} / {median_compression:>6.1%}"
        
        print(f"{method:<25} {success_rate:>6.1f}% ({successful}/{total}){' '*4}"
              f"{compression_text:<35} {total} attempts")
    
    print("-" * 100)
    print()
    
    # By difficulty
    print("Performance by Difficulty:")
    print("-" * 100)
    
    for difficulty in ['Easy', 'Medium', 'Hard']:
        print(f"\n{difficulty} Problems:")
        print(f"{'Method':<25} {'Success Rate':<20} {'Compression (avg/med)':<35}")
        print("-" * 100)
        
        for stats in [reducefix_stats, ddmin_stats]:
            method = stats['method']
            diff_stats = stats['difficulty_stats'].get(difficulty, {})
            
            total = diff_stats.get('attempts', 0)
            successful = diff_stats.get('successful', 0)
            success_rate = (successful / total * 100) if total > 0 else 0
            
            ratios = diff_stats.get('compression_ratios', [])
            avg_compression = statistics.mean(ratios) if ratios else 0
            median_compression = statistics.median(ratios) if ratios else 0
            compression_text = f"{avg_compression:>6.1%} / {median_compression:>6.1%}"
            
            print(f"{method:<25} {success_rate:>6.1f}% ({successful}/{total}){' '*4}"
                  f"{compression_text:<35}")
    
    print("-" * 100)
    print()
    
    # By input format
    print("Performance by Input Format:")
    print("-" * 100)
    
    # Define order of categories as in the paper
    format_order = [
        'Sequence',
        'Multiple sequences',
        'Sequence with dependencies',
        '2-D matrix',
        'Graph',
        'String'
    ]
    
    for input_format in format_order:
        print(f"\n{input_format}:")
        print(f"{'Method':<25} {'Success Rate':<20} {'Compression (avg/med)':<35}")
        print("-" * 100)
        
        for stats in [reducefix_stats, ddmin_stats]:
            method = stats['method']
            format_stats = stats['format_stats'].get(input_format, {})
            
            total = format_stats.get('attempts', 0)
            successful = format_stats.get('successful', 0)
            success_rate = (successful / total * 100) if total > 0 else 0
            
            ratios = format_stats.get('compression_ratios', [])
            avg_compression = statistics.mean(ratios) if ratios else 0
            median_compression = statistics.median(ratios) if ratios else 0
            compression_text = f"{avg_compression:>6.1%} / {median_compression:>6.1%}"
            
            if total > 0:
                print(f"{method:<25} {success_rate:>6.1f}% ({successful}/{total}){' '*4}"
                      f"{compression_text:<35}")
    
    print("-" * 100)
    print()
    
    # Key insights
    print("Key Insights:")
    print("-" * 100)
    
    reducefix_success = reducefix_stats['successful_reductions'] / reducefix_stats['total_attempts']
    ddmin_success = ddmin_stats['successful_reductions'] / ddmin_stats['total_attempts']
    improvement = (reducefix_success - ddmin_success) / ddmin_success * 100
    
    print(f"✓ ReduceFix achieves {reducefix_success*100:.1f}% success rate vs DDmin-only {ddmin_success*100:.1f}%")
    print(f"✓ Improvement: {improvement:.1f}% higher success rate")
    print(f"✓ ReduceFix is {reducefix_success/ddmin_success:.2f}x more reliable at reducing test inputs")
    print()
    
    # Problem-specific insights
    for difficulty in ['Easy', 'Medium', 'Hard']:
        rf_diff = reducefix_stats['difficulty_stats'].get(difficulty, {})
        dd_diff = ddmin_stats['difficulty_stats'].get(difficulty, {})
        
        rf_rate = rf_diff['successful'] / rf_diff['attempts'] if rf_diff['attempts'] > 0 else 0
        dd_rate = dd_diff['successful'] / dd_diff['attempts'] if dd_diff['attempts'] > 0 else 0
        
        if dd_rate > 0:
            improvement = (rf_rate - dd_rate) / dd_rate * 100
            print(f"✓ {difficulty}: ReduceFix {rf_rate*100:.1f}% vs DDmin {dd_rate*100:.1f}% "
                  f"({improvement:+.1f}% improvement)")
    
    print("-" * 100)
    print()

def main():
    # File paths
    reducefix_path = 'result_reducer_reducefix.json'
    ddmin_path = 'result_reducer_ddmin.json'
    llm_path = 'result_reducer_llm.json'
    
    # Analyze all methods
    print("Analyzing ReduceFix results...")
    reducefix_stats = analyze_results(reducefix_path, "ReduceFix (LLM+ddmin)")
    
    print("Analyzing DDmin-only baseline...")
    ddmin_stats = analyze_results(ddmin_path, "DDmin-only")
    
    # Try to load Pure LLM results
    llm_stats = None
    if os.path.exists(llm_path):
        print("Analyzing Pure LLM baseline...")
        llm_stats = analyze_results(llm_path, "Pure LLM")
    else:
        print("Note: Pure LLM baseline not found (optional)")
    
    if not reducefix_stats or not ddmin_stats:
        print("Error: Could not load one or more result files", file=sys.stderr)
        sys.exit(1)
    
    # Print comparison
    if llm_stats:
        print_comparison_table_three(reducefix_stats, ddmin_stats, llm_stats)
    else:
        print_comparison_table(reducefix_stats, ddmin_stats)

if __name__ == "__main__":
    main()

