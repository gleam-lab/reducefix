#!/usr/bin/env python3
"""analyze_rq1_stats.py

Statistical analysis for RQ1: How reliable are LLM-generated reducers at shrinking failure-inducing inputs?

Outputs Table 1 format data:
- Success rate by difficulty (Easy/Medium/Hard)
- Compression ratio statistics  
- Comparison against pure LLM baseline

Usage:
    python3 analyze_rq1_stats.py [reducer_results.json] [--baseline baseline_results.json]
"""

import argparse
import json
import os
import sys
import statistics
from collections import defaultdict
from typing import Dict, List, Tuple, Optional

def parse_problem_difficulty(problem_id: str) -> Optional[str]:
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

def calculate_compression_ratio(original_size: int, reduced_size: int) -> float:
    """Calculate compression ratio as (1 - reduced/original)"""
    if original_size == 0:
        return 0.0
    return (original_size - reduced_size) / original_size

def analyze_reducer_results(file_path: str) -> Dict:
    """Analyze reducer test results from consolidated JSON"""
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            data = json.load(f)
    except Exception as e:
        print(f"Error reading file {file_path}: {e}", file=sys.stderr)
        return {}
    
    stats = {
        'total_problems': 0,
        'total_attempts': 0,
        'successful_reductions': 0,
        'failed_reductions': 0,
        'compression_ratios': [],
        'difficulty_stats': defaultdict(lambda: {
            'problems': 0,
            'attempts': 0,
            'successful': 0,
            'failed': 0,
            'compression_ratios': []
        })
    }
    
    for problem_id, problem_data in data.items():
        if not isinstance(problem_data, dict):
            continue
            
        stats['total_problems'] += 1
        difficulty = parse_problem_difficulty(problem_id)
        
        if difficulty:
            stats['difficulty_stats'][difficulty]['problems'] += 1
        
        # Analyze reduction results
        results = problem_data.get('results', [])
        
        for result in results:
            stats['total_attempts'] += 1
            if difficulty:
                stats['difficulty_stats'][difficulty]['attempts'] += 1
            
            status_code = result.get('status_code', 0)
            original_size = result.get('original_size_bytes')
            reduced_size = result.get('reduced_size_bytes')
            
            if status_code == 200 and original_size is not None and reduced_size is not None:
                if reduced_size < original_size:  # Actual reduction achieved
                    stats['successful_reductions'] += 1
                    if difficulty:
                        stats['difficulty_stats'][difficulty]['successful'] += 1
                    
                    compression_ratio = calculate_compression_ratio(original_size, reduced_size)
                    stats['compression_ratios'].append(compression_ratio)
                    if difficulty:
                        stats['difficulty_stats'][difficulty]['compression_ratios'].append(compression_ratio)
                else:
                    # No reduction effect
                    stats['failed_reductions'] += 1
                    if difficulty:
                        stats['difficulty_stats'][difficulty]['failed'] += 1
            else:
                # Reduction failed
                stats['failed_reductions'] += 1
                if difficulty:
                    stats['difficulty_stats'][difficulty]['failed'] += 1
    
    return stats

def format_percentage(value: float) -> str:
    """Format percentage with 1 decimal place"""
    return f"{value:.1f}%"

def format_ratio(value: float) -> str:
    """Format compression ratio as percentage"""
    return f"{value * 100:.1f}%"

def print_table1_format(stats: Dict, baseline_stats: Optional[Dict] = None):
    """Print RQ1 results in Table 1 format"""
    print("="*80)
    print("RQ1: Reducer Success Rate and Compression Ratio")
    print("="*80)
    
    # Main results table
    print("\nTable 1: Reducer performance by difficulty")
    print("-"*90)
    print(f"{'Difficulty':<12} {'Problems':<9} {'Attempts':<9} {'Success':<8} {'Success Rate':<12} {'Avg Compression':<15} {'Median Compression':<17}")
    print("-"*90)
    
    # Calculate overall stats
    total_attempts = stats['total_attempts']
    total_success = stats['successful_reductions']
    overall_success_rate = total_success / total_attempts * 100 if total_attempts > 0 else 0
    
    overall_avg_compression = 0
    overall_median_compression = 0
    if stats['compression_ratios']:
        overall_avg_compression = statistics.mean(stats['compression_ratios'])
        overall_median_compression = statistics.median(stats['compression_ratios'])
    
    # Print by difficulty
    difficulties = sorted(['Easy', 'Medium', 'Hard'])
    total_problems = 0
    
    for difficulty in difficulties:
        diff_stats = stats['difficulty_stats'][difficulty]
        problems = diff_stats['problems']
        attempts = diff_stats['attempts']
        successful = diff_stats['successful']
        success_rate = successful / attempts * 100 if attempts > 0 else 0
        
        avg_compression = 0
        median_compression = 0
        if diff_stats['compression_ratios']:
            avg_compression = statistics.mean(diff_stats['compression_ratios'])
            median_compression = statistics.median(diff_stats['compression_ratios'])
        
        total_problems += problems
        
        print(f"{difficulty:<12} {problems:<9} {attempts:<9} {successful:<8} {format_percentage(success_rate):<12} {format_ratio(avg_compression):<15} {format_ratio(median_compression):<17}")
    
    # Print overall
    print("-"*90)
    print(f"{'Overall':<12} {total_problems:<9} {total_attempts:<9} {total_success:<8} {format_percentage(overall_success_rate):<12} {format_ratio(overall_avg_compression):<15} {format_ratio(overall_median_compression):<17}")
    print("-"*90)
    
    # Compression ratio distribution
    print(f"\nCompression Ratio Distribution (successful cases only):")
    if stats['compression_ratios']:
        ratios = sorted([r * 100 for r in stats['compression_ratios']])
        print(f"Count: {len(ratios)}")
        print(f"Min: {ratios[0]:.1f}%")
        print(f"Q1: {ratios[len(ratios)//4]:.1f}%")
        print(f"Median: {statistics.median(ratios):.1f}%")
        print(f"Q3: {ratios[3*len(ratios)//4]:.1f}%")
        print(f"Max: {ratios[-1]:.1f}%")
        print(f"Mean: {statistics.mean(ratios):.1f}%")
        print(f"Std: {statistics.stdev(ratios):.1f}%")
    
    # Baseline comparison if provided
    if baseline_stats:
        print(f"\n" + "="*60)
        print("Comparison: ReduceFix (LLM+ddmin) vs Pure LLM")
        print("="*60)
        
        baseline_attempts = baseline_stats['total_attempts']
        baseline_success = baseline_stats['successful_reductions']
        baseline_success_rate = baseline_success / baseline_attempts * 100 if baseline_attempts > 0 else 0
        
        baseline_avg_compression = 0
        if baseline_stats['compression_ratios']:
            baseline_avg_compression = statistics.mean(baseline_stats['compression_ratios'])
        
        print(f"{'Approach':<20} {'Success Rate':<12} {'Avg Compression':<15} {'Improvement':<12}")
        print("-"*60)
        print(f"{'Pure LLM':<20} {format_percentage(baseline_success_rate):<12} {format_ratio(baseline_avg_compression):<15} {'Baseline':<12}")
        print(f"{'ReduceFix':<20} {format_percentage(overall_success_rate):<12} {format_ratio(overall_avg_compression):<15} {format_percentage(overall_success_rate - baseline_success_rate):<12}")
        print("-"*60)
    
    # Raw data for plotting (violin plot)
    print(f"\n" + "="*40)
    print("Raw Data for Violin Plot")
    print("="*40)
    
    for difficulty in difficulties:
        diff_stats = stats['difficulty_stats'][difficulty]
        if diff_stats['compression_ratios']:
            ratios = [r * 100 for r in diff_stats['compression_ratios']]
            print(f"\n{difficulty} difficulty compression ratios (n={len(ratios)}):")
            print(f"Data: {[round(r, 2) for r in ratios]}")
    
    # Overall data
    if stats['compression_ratios']:
        ratios = [r * 100 for r in stats['compression_ratios']]
        print(f"\nOverall compression ratios (n={len(ratios)}):")
        print(f"Data: {[round(r, 2) for r in ratios]}")

def print_detailed_failure_analysis(stats: Dict):
    """Print detailed failure analysis"""
    print(f"\n" + "="*60)
    print("Detailed Failure Analysis")
    print("="*60)
    
    total_failures = stats['failed_reductions']
    
    if total_failures > 0:
        print(f"Total failed reductions: {total_failures}")
        print(f"Failure rate: {format_percentage(total_failures / stats['total_attempts'] * 100)}")
        
        # By difficulty
        print(f"\nFailures by difficulty:")
        for difficulty in sorted(['Easy', 'Medium', 'Hard']):
            diff_stats = stats['difficulty_stats'][difficulty]
            failed = diff_stats['failed']
            attempts = diff_stats['attempts']
            if attempts > 0:
                failure_rate = failed / attempts * 100
                print(f"  {difficulty}: {failed}/{attempts} ({format_percentage(failure_rate)})")
    else:
        print("No failures recorded")

def main():
    parser = argparse.ArgumentParser(description="Analyze RQ1 reducer statistics")
    parser.add_argument("reducer_results", nargs="?", default="reducer_results.json", 
                       help="Consolidated reducer results file (default: reducer_results.json)")
    parser.add_argument("--baseline", help="Baseline (pure LLM) results file for comparison")
    parser.add_argument("--detailed", action="store_true", help="Include detailed failure analysis")
    args = parser.parse_args()
    
    # Check if main results file exists
    if not os.path.exists(args.reducer_results):
        print(f"Error: Results file not found: {args.reducer_results}", file=sys.stderr)
        sys.exit(1)
    
    print(f"Analyzing reducer results: {args.reducer_results}")
    stats = analyze_reducer_results(args.reducer_results)
    
    baseline_stats = None
    if args.baseline:
        if os.path.exists(args.baseline):
            print(f"Analyzing baseline results: {args.baseline}")
            baseline_stats = analyze_reducer_results(args.baseline)
        else:
            print(f"Warning: Baseline file not found: {args.baseline}", file=sys.stderr)
    
    # Print main results
    print_table1_format(stats, baseline_stats)
    
    # Print detailed analysis if requested
    if args.detailed:
        print_detailed_failure_analysis(stats)
    
    print(f"\nAnalysis complete. Total problems analyzed: {stats['total_problems']}")

if __name__ == "__main__":
    main() 