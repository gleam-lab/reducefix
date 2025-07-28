#!/usr/bin/env python3
"""analyze_reducer_stats.py

Analyze reducer statistics including:
- Success rate of reduction process
- Number and reasons of failures
- Compression ratio statistics
- Reducer code line count statistics
- Statistics by difficulty level

Usage:
    python3 analyze_reducer_stats.py [result_file.json] [--model model_name]
"""

import argparse
import json
import os
import sys
import re
from collections import defaultdict, Counter
from typing import Dict, List, Tuple, Optional
import statistics

def parse_problem_difficulty(problem_id: str) -> Optional[str]:
    """Determine difficulty level based on problem ID suffix letter"""
    if problem_id and len(problem_id) > 0:
        suffix = problem_id[-1].lower()
        if suffix in ['b', 'c']:
            return 'Easy'
        elif suffix == 'd':
            return 'Medium'
        elif suffix in ['e', 'f']:
            return 'Hard'
    return None

def count_code_lines(code: str) -> int:
    """Count code lines (excluding empty lines and comments)"""
    if not code:
        return 0
    
    lines = code.split('\n')
    code_lines = 0
    
    for line in lines:
        line = line.strip()
        if line and not line.startswith('#'):
            code_lines += 1
    
    return code_lines

def calculate_compression_ratio(original_size: int, reduced_size: int) -> float:
    """Calculate compression ratio"""
    if original_size == 0:
        return 0.0
    return (original_size - reduced_size) / original_size

def get_file_size_from_path(file_path: str) -> Optional[int]:
    """Get file size in bytes from file path"""
    try:
        if os.path.exists(file_path):
            return os.path.getsize(file_path)
        else:
            return None
    except Exception as e:
        print(f"[Warning] Cannot get file size {file_path}: {e}", file=sys.stderr)
        return None

def get_actual_sizes(problem_id: str, submission_id: str, result: Dict) -> Tuple[Optional[int], Optional[int]]:
    """Get actual original and reduced file sizes in bytes"""
    original_size = result.get('original_size_bytes')
    reduced_size = result.get('reduced_size_bytes')
    
    if original_size is None:
        original_file_path = f"{problem_id}/{submission_id}/origin_input.txt"
        original_size = get_file_size_from_path(original_file_path)
        if original_size is None:
            alt_paths = [
                f"{problem_id}/{submission_id}/original_input.txt",
                f"{problem_id}/{submission_id}/input.txt",
                f"{problem_id}/{submission_id}/failing_input.txt"
            ]
            for path in alt_paths:
                original_size = get_file_size_from_path(path)
                if original_size is not None:
                    break
    
    if reduced_size is None:
        reduced_file_path = f"{problem_id}/{submission_id}/reduced_input.txt"
        reduced_size = get_file_size_from_path(reduced_file_path)
        if reduced_size is None:
            alt_paths = [
                f"{problem_id}/{submission_id}/min_input.txt",
                f"{problem_id}/{submission_id}/minimized_input.txt"
            ]
            for path in alt_paths:
                reduced_size = get_file_size_from_path(path)
                if reduced_size is not None:
                    break
    
    return original_size, reduced_size

def analyze_single_file(file_path: str, problem_filter: Optional[set] = None, expected_submissions_per_problem: int = 10) -> Tuple[Dict, Dict]:
    """Analyze a single result file"""
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            data = json.load(f)
    except Exception as e:
        print(f"[Error] Cannot read file {file_path}: {e}")
        return {}
    
    actual_problems = 0
    for problem_id in data.keys():
        if problem_filter is None or problem_id in problem_filter:
            actual_problems += 1
    
    analysis = {
        'total_problems': actual_problems,
        'expected_submissions_per_problem': expected_submissions_per_problem,
        'expected_total_submissions': actual_problems * expected_submissions_per_problem,
        'actual_total_submissions': 0,
        'total_reduction_attempts': 0,
        'successful_reductions': 0,
        'failed_reductions': 0,
        'missing_submissions': 0,
        'no_reduction_submissions': 0,
        'failure_reasons': Counter(),
        'compression_ratios': [],
        'reducer_code_lines': [],
        'execution_times': [],
        'missing_size_info': 0,
        'difficulty_stats': defaultdict(lambda: {
            'problems': 0,
            'expected_submissions': 0,
            'actual_submissions': 0,
            'reduction_attempts': 0,
            'successful': 0,
            'failed': 0,
            'missing_submissions': 0,
            'no_reduction_submissions': 0,
            'failure_reasons': Counter(),
            'compression_ratios': [],
            'execution_times': [],
        })
    }
    
    for problem_id, problem_data in data.items():
        if problem_filter is not None and problem_id not in problem_filter:
            continue
            
        difficulty = parse_problem_difficulty(problem_id)
        
        reducer_code = problem_data.get('reducer_code', '')
        code_lines = count_code_lines(reducer_code)
        if code_lines > 0:
            analysis['reducer_code_lines'].append(code_lines)
        
        if difficulty:
            analysis['difficulty_stats'][difficulty]['problems'] += 1
            analysis['difficulty_stats'][difficulty]['expected_submissions'] += expected_submissions_per_problem
        
        results = problem_data.get('results', [])
        actual_submissions_this_problem = len(results)
        analysis['actual_total_submissions'] += actual_submissions_this_problem
        
        missing_submissions_this_problem = expected_submissions_per_problem - actual_submissions_this_problem
        if missing_submissions_this_problem > 0:
            analysis['missing_submissions'] += missing_submissions_this_problem
            analysis['failed_reductions'] += missing_submissions_this_problem
            analysis['failure_reasons']['Missing submissions (not recorded)'] += missing_submissions_this_problem
            
            if difficulty:
                analysis['difficulty_stats'][difficulty]['missing_submissions'] += missing_submissions_this_problem
                analysis['difficulty_stats'][difficulty]['failed'] += missing_submissions_this_problem
                analysis['difficulty_stats'][difficulty]['failure_reasons']['Missing submissions (not recorded)'] += missing_submissions_this_problem
        
        if difficulty:
            analysis['difficulty_stats'][difficulty]['actual_submissions'] += actual_submissions_this_problem
        
        for result in results:
            submission_id = result.get('submission_id', 'unknown')
            status_code = result.get('status_code', 0)
            message = result.get('message', 'No message')
            
            original_size, reduced_size = get_actual_sizes(problem_id, submission_id, result)
            
            exec_time = result.get('execution_time_seconds')
            if exec_time is None:
                exec_time = 0
            
            analysis['total_reduction_attempts'] += 1
            
            if status_code == 200:
                has_reduction_effect = False
                if original_size is not None and reduced_size is not None and original_size > 0:
                    if reduced_size < original_size:
                        has_reduction_effect = True
                        compression_ratio = calculate_compression_ratio(original_size, reduced_size)
                        analysis['compression_ratios'].append(compression_ratio)
                    elif reduced_size == original_size:
                        has_reduction_effect = False
                else:
                    if original_size is None or reduced_size is None:
                        analysis['missing_size_info'] += 1
                    has_reduction_effect = True
                
                if has_reduction_effect:
                    analysis['successful_reductions'] += 1
                    if exec_time > 0:
                        analysis['execution_times'].append(exec_time)
                else:
                    analysis['failed_reductions'] += 1
                    analysis['no_reduction_submissions'] += 1
                    analysis['failure_reasons']['No reduction effect (same size)'] += 1
            else:
                analysis['failed_reductions'] += 1
                analysis['failure_reasons'][message] += 1
            
            if difficulty:
                diff_stats = analysis['difficulty_stats'][difficulty]
                diff_stats['reduction_attempts'] += 1
                
                if status_code == 200:
                    has_reduction_effect = False
                    if original_size is not None and reduced_size is not None and original_size > 0:
                        if reduced_size < original_size:
                            has_reduction_effect = True
                            compression_ratio = calculate_compression_ratio(original_size, reduced_size)
                            diff_stats['compression_ratios'].append(compression_ratio)
                        elif reduced_size == original_size:
                            has_reduction_effect = False
                    else:
                        has_reduction_effect = True
                    
                    if has_reduction_effect:
                        diff_stats['successful'] += 1
                        if exec_time > 0:
                            diff_stats['execution_times'].append(exec_time)
                    else:
                        diff_stats['failed'] += 1
                        diff_stats['no_reduction_submissions'] += 1
                        diff_stats['failure_reasons']['No reduction effect (same size)'] += 1
                else:
                    diff_stats['failed'] += 1
                    diff_stats['failure_reasons'][message] += 1
    
    analysis['total_reduction_attempts'] = analysis['expected_total_submissions']
    
    for difficulty in analysis['difficulty_stats']:
        diff_stats = analysis['difficulty_stats'][difficulty]
        diff_stats['reduction_attempts'] = diff_stats['expected_submissions']
    
    return analysis, data

def format_percentage(value: float) -> str:
    """Format percentage"""
    return f"{value:.1f}%"

def calculate_quartiles(values: List[float]) -> Dict:
    """Calculate quartile statistics"""
    if not values:
        return {}
    
    values_sorted = sorted(values)
    n = len(values_sorted)
    
    def percentile(data, p):
        """Calculate percentile"""
        if not data:
            return 0
        idx = (len(data) - 1) * p / 100
        lower_idx = int(idx)
        upper_idx = min(lower_idx + 1, len(data) - 1)
        weight = idx - lower_idx
        return data[lower_idx] * (1 - weight) + data[upper_idx] * weight
    
    return {
        'count': n,
        'min': min(values_sorted),
        'q1': percentile(values_sorted, 25),
        'median': statistics.median(values_sorted),
        'q3': percentile(values_sorted, 75),
        'max': max(values_sorted),
        'mean': statistics.mean(values_sorted),
        'std': statistics.stdev(values_sorted) if n > 1 else 0
    }

def print_compression_ratio_distribution(analysis: Dict):
    """Print compression ratio distribution statistics"""
    print(f"\n### Compression Ratio Distribution (Successful Cases)")
    print("Note: Compression ratio = (original_size - reduced_size) / original_size * 100%")
    
    print(f"{'Difficulty':<12} {'Count':<8} {'Min':<8} {'Q1':<8} {'Median':<8} {'Q3':<8} {'Max':<8} {'Mean':<8} {'Std':<8}")
    print("=" * 100)
    
    if analysis['compression_ratios']:
        total_ratios = [r * 100 for r in analysis['compression_ratios']]
        total_stats = calculate_quartiles(total_ratios)
        
        print(f"{'Overall':<12} {total_stats['count']:<8} {total_stats['min']:<8.1f} {total_stats['q1']:<8.1f} {total_stats['median']:<8.1f} {total_stats['q3']:<8.1f} {total_stats['max']:<8.1f} {total_stats['mean']:<8.1f} {total_stats['std']:<8.1f}")
        print("-" * 100)
    
    difficulties = sorted(analysis['difficulty_stats'].keys()) if analysis['difficulty_stats'] else []
    for difficulty in difficulties:
        stats = analysis['difficulty_stats'][difficulty]
        if stats['compression_ratios']:
            ratios = [r * 100 for r in stats['compression_ratios']]
            diff_stats = calculate_quartiles(ratios)
            
            print(f"{difficulty:<12} {diff_stats['count']:<8} {diff_stats['min']:<8.1f} {diff_stats['q1']:<8.1f} {diff_stats['median']:<8.1f} {diff_stats['q3']:<8.1f} {diff_stats['max']:<8.1f} {diff_stats['mean']:<8.1f} {diff_stats['std']:<8.1f}")
        else:
            print(f"{difficulty:<12} {'0':<8} {'N/A':<8} {'N/A':<8} {'N/A':<8} {'N/A':<8} {'N/A':<8} {'N/A':<8} {'N/A':<8}")
    
    print("=" * 100)
    
    print(f"\n### Raw Compression Ratio Data (for Box Plot)")
    
    if analysis['compression_ratios']:
        total_ratios = [r * 100 for r in analysis['compression_ratios']]
        print(f"\nOverall compression ratio data (n={len(total_ratios)}):")
        print("Values:", [round(r, 2) for r in total_ratios])
    
    for difficulty in difficulties:
        stats = analysis['difficulty_stats'][difficulty]
        if stats['compression_ratios']:
            ratios = [r * 100 for r in stats['compression_ratios']]
            print(f"\n{difficulty} difficulty compression ratio data (n={len(ratios)}):")
            print("Values:", [round(r, 2) for r in ratios])

def format_stats(values: List[float], unit: str = "") -> str:
    """Format statistical data"""
    if not values:
        return "N/A"
    
    mean_val = statistics.mean(values)
    median_val = statistics.median(values)
    
    if len(values) > 1:
        std_val = statistics.stdev(values)
        return f"{mean_val:.3f}±{std_val:.3f}{unit} (median: {median_val:.3f}{unit})"
    else:
        return f"{mean_val:.3f}{unit}"

def print_core_performance_table(analysis: Dict):
    """Print core performance table"""
    print(f"\n### Core Reducer Performance Table")
    print("Column descriptions: Total=expected submissions, Timeout=missing submissions, Invalid=executed successfully but no reduction effect, Success=actual reduction effect")
    
    print(f"{'Difficulty':<12} {'Total':<8} {'Timeout':<8} {'Invalid':<8} {'Success':<8} {'Success Rate':<12} {'Avg Reduction':<14} {'Avg Exec Time':<12}")
    print("=" * 100)
    
    total_expected = analysis.get('expected_total_submissions', 0)
    total_missing = analysis.get('missing_submissions', 0)
    total_no_reduction = analysis.get('no_reduction_submissions', 0)
    total_successful = analysis.get('successful_reductions', 0)
    total_success_rate = total_successful / total_expected * 100 if total_expected > 0 else 0
    
    total_avg_compression = ""
    if analysis['compression_ratios']:
        avg_comp = statistics.mean(analysis['compression_ratios']) * 100
        total_avg_compression = f"{avg_comp:.1f}%"
    
    total_avg_exec_time = ""
    if analysis['execution_times']:
        avg_time = statistics.mean(analysis['execution_times'])
        total_avg_exec_time = f"{avg_time:.1f}s"
    
    print(f"{'Overall':<12} {total_expected:<8} {total_missing:<8} {total_no_reduction:<8} {total_successful:<8} {format_percentage(total_success_rate):<12} {total_avg_compression:<14} {total_avg_exec_time:<12}")
    print("-" * 100)
    
    difficulties = sorted(analysis['difficulty_stats'].keys()) if analysis['difficulty_stats'] else []
    for difficulty in difficulties:
        stats = analysis['difficulty_stats'][difficulty]
        expected_subs = stats.get('expected_submissions', 0)
        missing_subs = stats.get('missing_submissions', 0)
        no_reduction_subs = stats.get('no_reduction_submissions', 0)
        successful_subs = stats.get('successful', 0)
        success_rate = successful_subs / expected_subs * 100 if expected_subs > 0 else 0
        
        avg_compression = ""
        if stats['compression_ratios']:
            avg_comp = statistics.mean(stats['compression_ratios']) * 100
            avg_compression = f"{avg_comp:.1f}%"
        
        avg_exec_time = ""
        if stats['execution_times']:
            avg_time = statistics.mean(stats['execution_times'])
            avg_exec_time = f"{avg_time:.1f}s"
        
        print(f"{difficulty:<12} {expected_subs:<8} {missing_subs:<8} {no_reduction_subs:<8} {successful_subs:<8} {format_percentage(success_rate):<12} {avg_compression:<14} {avg_exec_time:<12}")
    
    print("=" * 100)

def print_per_problem_stats(data: Dict, problem_filter: Optional[set] = None, expected_submissions_per_problem: int = 10):
    """Print compression success rate statistics for each problem"""
    print(f"\n### Per-Problem Compression Success Rate Statistics")
    print("Note: Success rate = submissions with actual reduction effect / expected submissions")
    
    print(f"{'Problem ID':<12} {'Difficulty':<10} {'Expected':<10} {'Actual':<8} {'Success':<8} {'Success Rate':<12} {'Avg Compression':<15} {'Max Compression':<15}")
    print("=" * 110)
    
    problem_stats = []
    
    for problem_id, problem_data in data.items():
        if problem_filter is not None and problem_id not in problem_filter:
            continue
        
        difficulty = parse_problem_difficulty(problem_id)
        
        results = problem_data.get('results', [])
        actual_submissions = len(results)
        expected_submissions = expected_submissions_per_problem
        successful_reductions = 0
        compression_ratios = []
        
        for result in results:
            submission_id = result.get('submission_id', 'unknown')
            status_code = result.get('status_code', 0)
            
            if status_code == 200:
                original_size, reduced_size = get_actual_sizes(problem_id, submission_id, result)
                
                has_reduction_effect = False
                if original_size is not None and reduced_size is not None and original_size > 0:
                    if reduced_size < original_size:
                        has_reduction_effect = True
                        compression_ratio = calculate_compression_ratio(original_size, reduced_size)
                        compression_ratios.append(compression_ratio)
                    elif reduced_size == original_size:
                        has_reduction_effect = False
                else:
                    has_reduction_effect = True
                
                if has_reduction_effect:
                    successful_reductions += 1
        
        success_rate = successful_reductions / expected_submissions * 100 if expected_submissions > 0 else 0
        
        avg_compression = ""
        max_compression = ""
        if compression_ratios:
            avg_comp = statistics.mean(compression_ratios) * 100
            max_comp = max(compression_ratios) * 100
            avg_compression = f"{avg_comp:.1f}%"
            max_compression = f"{max_comp:.1f}%"
        
        problem_stats.append({
            'problem_id': problem_id,
            'difficulty': difficulty or 'Unknown',
            'expected': expected_submissions,
            'actual': actual_submissions,
            'successful': successful_reductions,
            'success_rate': success_rate,
            'avg_compression': avg_compression,
            'max_compression': max_compression,
            'compression_ratios': compression_ratios
        })
    
    problem_stats.sort(key=lambda x: x['success_rate'], reverse=True)
    
    for stats in problem_stats:
        print(f"{stats['problem_id']:<12} {stats['difficulty']:<10} {stats['expected']:<10} {stats['actual']:<8} {stats['successful']:<8} {format_percentage(stats['success_rate']):<12} {stats['avg_compression']:<15} {stats['max_compression']:<15}")
    
    print("=" * 110)
    
    print(f"\n### Success Rate Group Statistics")
    success_groups = {
        '90%+': [],
        '70-89%': [],
        '50-69%': [],
        '30-49%': [],
        '10-29%': [],
        '<10%': []
    }
    
    for stats in problem_stats:
        rate = stats['success_rate']
        if rate >= 90:
            success_groups['90%+'].append(stats)
        elif rate >= 70:
            success_groups['70-89%'].append(stats)
        elif rate >= 50:
            success_groups['50-69%'].append(stats)
        elif rate >= 30:
            success_groups['30-49%'].append(stats)
        elif rate >= 10:
            success_groups['10-29%'].append(stats)
        else:
            success_groups['<10%'].append(stats)
    
    print(f"{'Success Rate':<12} {'Count':<8} {'Problem List'}")
    print("=" * 60)
    for group_name, group_problems in success_groups.items():
        if group_problems:
            problem_list = ', '.join([p['problem_id'] for p in group_problems[:10]])
            if len(group_problems) > 10:
                problem_list += f" ... (total {len(group_problems)})"
            print(f"{group_name:<12} {len(group_problems):<8} {problem_list}")
        else:
            print(f"{group_name:<12} {0:<8} None")
    
    print("=" * 60)

def print_failed_submissions_details(data: Dict, problem_filter: Optional[set] = None):
    """Print details of failed submissions"""
    print(f"\n### Failed Submissions Details")
    print("Description: Shows all failed reduction submission_ids and failure reasons")
    
    print(f"{'Problem ID':<12} {'Difficulty':<10} {'Submission ID':<15} {'Failure Reason':<30} {'Original Size':<12} {'Reduced Size':<12} {'Exec Time':<10}")
    print("=" * 120)
    
    failed_cases = []
    
    for problem_id, problem_data in data.items():
        if problem_filter is not None and problem_id not in problem_filter:
            continue
        
        difficulty = parse_problem_difficulty(problem_id) or 'Unknown'
        
        results = problem_data.get('results', [])
        
        for result in results:
            submission_id = result.get('submission_id', 'unknown')
            status_code = result.get('status_code', 0)
            message = result.get('message', 'No message')
            exec_time = result.get('execution_time_seconds', 0)
            
            original_size, reduced_size = get_actual_sizes(problem_id, submission_id, result)
            
            failure_reason = ""
            
            if status_code == 200:
                has_reduction_effect = False
                if original_size is not None and reduced_size is not None and original_size > 0:
                    if reduced_size < original_size:
                        has_reduction_effect = True
                    elif reduced_size == original_size:
                        has_reduction_effect = False
                        failure_reason = "No reduction effect (same size)"
                else:
                    has_reduction_effect = True
                
                if not has_reduction_effect:
                    failed_cases.append({
                        'problem_id': problem_id,
                        'difficulty': difficulty,
                        'submission_id': submission_id,
                        'failure_reason': failure_reason,
                        'original_size': original_size if original_size is not None else 'N/A',
                        'reduced_size': reduced_size if reduced_size is not None else 'N/A',
                        'exec_time': f"{exec_time:.1f}s" if exec_time is not None and exec_time > 0 else 'N/A'
                    })
            else:
                failed_cases.append({
                    'problem_id': problem_id,
                    'difficulty': difficulty,
                    'submission_id': submission_id,
                    'failure_reason': message,
                    'original_size': original_size if original_size is not None else 'N/A',
                    'reduced_size': reduced_size if reduced_size is not None else 'N/A',
                    'exec_time': f"{exec_time:.1f}s" if exec_time is not None and exec_time > 0 else 'N/A'
                })
    
    failed_cases.sort(key=lambda x: (x['problem_id'], x['submission_id']))
    
    if failed_cases:
        for case in failed_cases:
            original_size_str = str(case['original_size']) if isinstance(case['original_size'], int) else case['original_size']
            reduced_size_str = str(case['reduced_size']) if isinstance(case['reduced_size'], int) else case['reduced_size']
            print(f"{case['problem_id']:<12} {case['difficulty']:<10} {case['submission_id']:<15} {case['failure_reason']:<30} {original_size_str:<12} {reduced_size_str:<12} {case['exec_time']:<10}")
    else:
        print("No failed cases")
    
    print("=" * 120)
    
    if failed_cases:
        print(f"\n### Failure Reason Group Details")
        reason_groups = defaultdict(list)
        for case in failed_cases:
            reason_groups[case['failure_reason']].append(case)
        
        for reason, cases in reason_groups.items():
            print(f"\n{reason} (total {len(cases)}):")
            for case in cases:
                print(f"  • {case['problem_id']} - {case['submission_id']} ({case['difficulty']} difficulty)")
        
        print(f"\nTotal failed: {len(failed_cases)}")

def print_analysis_results(analysis: Dict, raw_data: Dict, model_name: str = "", problem_filter: Optional[set] = None, expected_submissions_per_problem: int = 10):
    """Print analysis results"""
    print("\n" + "="*80)
    print(f"REDUCER STATISTICS ANALYSIS RESULTS{(' - ' + model_name) if model_name else ''}")
    print("="*80)
    
    total_problems = analysis['total_problems']
    total_attempts = analysis['total_reduction_attempts']
    successful = analysis['successful_reductions']
    failed = analysis['failed_reductions']
        
    print(f"\n### Key Metrics Summary")
    print(f"{'Metric':<30} {'Value':<20} {'Description'}")
    print("=" * 75)
    print(f"{'Total Problems':<30} {total_problems:<20} problems")
    print(f"{'Total Reduction Attempts':<30} {total_attempts:<20} attempts")
    print(f"{'Successful Reductions':<30} {successful:<20} attempts")
    print(f"{'Failed Reductions':<30} {failed:<20} attempts")
    print(f"{'Missing Submissions':<30} {analysis.get('missing_submissions', 0):<20} attempts")
    print(f"{'No Reduction Submissions':<30} {analysis.get('no_reduction_submissions', 0):<20} attempts")
    print(f"{'Actual Recorded Submissions':<30} {analysis.get('actual_total_submissions', 0):<20} attempts")
    print(f"{'Expected Submissions':<30} {analysis.get('expected_total_submissions', 0):<20} attempts")
    print(f"{'Reduction Success Rate':<30} {format_percentage(successful/total_attempts*100 if total_attempts > 0 else 0):<20} successful/total")
    print(f"{'Avg Attempts per Problem':<30} {total_attempts/total_problems:.1f}{'':<20} attempts/problem")
    
    if analysis['compression_ratios']:
        avg_comp = statistics.mean(analysis['compression_ratios']) * 100
        print(f"{'Average Compression Ratio':<30} {avg_comp:.1f}%{'':<20} compressed/original")
    
    if analysis['execution_times']:
        avg_time = statistics.mean(analysis['execution_times'])
        print(f"{'Average Execution Time':<30} {avg_time:.1f}s{'':<20} per reduction")
    
    print("=" * 75)
    
    print_core_performance_table(analysis)
    
    print(f"\n### Detailed Statistics")
    
    if analysis['compression_ratios']:
        print(f"\nCompression Ratio Statistics:")
        ratios = analysis['compression_ratios']
        print(f"  Average compression ratio: {format_stats([r*100 for r in ratios], '%')}")
        print(f"  Compression ratio range: {min(ratios)*100:.1f}% - {max(ratios)*100:.1f}%")
        print(f"  Valid compression ratio cases: {len(ratios)} / {successful}")
        if analysis['missing_size_info'] > 0:
            print(f"  Cases missing file size info: {analysis['missing_size_info']}")
    else:
        print(f"\nCompression Ratio Statistics: No valid data")
        if analysis['missing_size_info'] > 0:
            print(f"  Cases missing file size info: {analysis['missing_size_info']}")
    
    if analysis['reducer_code_lines']:
        print(f"\nReducer Code Line Statistics:")
        lines = analysis['reducer_code_lines']
        print(f"  Average code lines: {format_stats(lines, ' lines')}")
        print(f"  Code lines range: {min(lines)} - {max(lines)} lines")
    
    if analysis['execution_times']:
        print(f"\nExecution Time Statistics:")
        times = analysis['execution_times']
        print(f"  Average execution time: {format_stats(times, ' seconds')}")
        print(f"  Execution time range: {min(times):.1f} - {max(times):.1f} seconds")
    
    print_compression_ratio_distribution(analysis)
    
    print(f"\n### Reducer Performance Statistics Table")
    print("Difficulty explanation: Easy(b,c problems) / Medium(d problems) / Hard(e,f problems)")
    print("Failure type explanation: Missing=unrecorded submissions due to timeout etc, Invalid=executed successfully but no reduction effect")
    difficulties = sorted(analysis['difficulty_stats'].keys())
    
    print(f"{'Category':<12} {'Problems':<10} {'Expected':<10} {'Actual':<8} {'Success':<8} {'Failed':<8} {'Missing':<8} {'Invalid':<8} {'Success Rate':<12} {'Avg Compression':<15}")
    print("=" * 140)
    
    total_problems_with_data = sum(analysis['difficulty_stats'][d]['problems'] for d in difficulties)
    total_attempts = analysis['total_reduction_attempts']
    total_successful = analysis['successful_reductions']
    overall_success_rate = total_successful / total_attempts * 100 if total_attempts > 0 else 0
    
    overall_avg_compression = ""
    if analysis['compression_ratios']:
        avg_comp = statistics.mean(analysis['compression_ratios']) * 100
        overall_avg_compression = f"{avg_comp:.1f}%"
    
    expected_total = analysis.get('expected_total_submissions', 0)
    actual_total = analysis.get('actual_total_submissions', 0)
    failed_total = analysis.get('failed_reductions', 0)
    missing_total = analysis.get('missing_submissions', 0)
    no_reduction_total = analysis.get('no_reduction_submissions', 0)
    
    print(f"{'Overall':<12} {total_problems_with_data:<10} {expected_total:<10} {actual_total:<8} {total_successful:<8} {failed_total:<8} {missing_total:<8} {no_reduction_total:<8} {format_percentage(overall_success_rate):<12} {overall_avg_compression:<15}")
    print("-" * 140)
    
    if difficulties:
        for difficulty in difficulties:
            stats = analysis['difficulty_stats'][difficulty]
            problems = stats['problems']
            attempts = stats['reduction_attempts']
            successful = stats['successful']
            success_rate = successful / attempts * 100 if attempts > 0 else 0
            
            avg_compression = ""
            if stats['compression_ratios']:
                avg_comp = statistics.mean(stats['compression_ratios']) * 100
                avg_compression = f"{avg_comp:.1f}%"
            
            expected_subs = stats.get('expected_submissions', 0)
            actual_subs = stats.get('actual_submissions', 0)
            failed_subs = stats.get('failed', 0)
            missing_subs = stats.get('missing_submissions', 0)
            no_reduction_subs = stats.get('no_reduction_submissions', 0)
            
            print(f"{difficulty:<12} {problems:<10} {expected_subs:<10} {actual_subs:<8} {successful:<8} {failed_subs:<8} {missing_subs:<8} {no_reduction_subs:<8} {format_percentage(success_rate):<12} {avg_compression:<15}")
    else:
        print("  Cannot identify difficulty information")
        return
    
    print("=" * 140)
    
    print(f"\n### Failure Reason Statistics Table")
    print(f"{'Failure Reason':<50} {'Count':<8} {'% of Failed':<12} {'% of Total':<12}")
    print("=" * 85)
    
    for reason, count in analysis['failure_reasons'].most_common():
        fail_percentage = count / failed * 100 if failed > 0 else 0
        total_percentage = count / total_attempts * 100 if total_attempts > 0 else 0
        reason_short = reason[:47] + "..." if len(reason) > 50 else reason
        print(f"{reason_short:<50} {count:<8} {format_percentage(fail_percentage):<12} {format_percentage(total_percentage):<12}")
    
    print("=" * 85)
    
    print(f"\n### Failure Reasons by Difficulty")
    for difficulty in difficulties:
        stats = analysis['difficulty_stats'][difficulty]
        if stats['failure_reasons']:
            print(f"\n{difficulty} difficulty (total failed: {stats['failed']}):")
            for reason, count in stats['failure_reasons'].most_common():
                percentage = count / stats['failed'] * 100 if stats['failed'] > 0 else 0
                print(f"  • {reason}: {count} times ({format_percentage(percentage)})")
    
    print_per_problem_stats(raw_data, problem_filter, expected_submissions_per_problem)
    print_failed_submissions_details(raw_data, problem_filter)

def main():
    parser = argparse.ArgumentParser(description="Analyze reducer statistics")
    parser.add_argument("result_file", nargs="?", help="Result file path (if not specified, analyze all result_*.json files)")
    parser.add_argument("--model", help="Model name (for identification)")
    parser.add_argument("--filter-by-repair", help="Filter problem set by repair result file (e.g., result_repair.json)")
    parser.add_argument("--expected-per-problem", type=int, default=10, help="Expected submission count per problem (default: 10)")
    args = parser.parse_args()
    
    problem_filter = None
    if args.filter_by_repair:
        if not os.path.exists(args.filter_by_repair):
            print(f"[Error] Filter file not found: {args.filter_by_repair}")
            sys.exit(1)
        
        try:
            with open(args.filter_by_repair, 'r', encoding='utf-8') as f:
                repair_data = json.load(f)
            problem_filter = set(repair_data.keys())
            print(f"[Info] Using repair file filter, analyzing {len(problem_filter)} problems only")
        except Exception as e:
            print(f"[Error] Cannot read filter file: {e}")
            sys.exit(1)

    if args.result_file:
        if not os.path.exists(args.result_file):
            print(f"[Error] File not found: {args.result_file}")
            sys.exit(1)
        
        print(f"Analyzing file: {args.result_file}")
        analysis, raw_data = analyze_single_file(args.result_file, problem_filter, args.expected_per_problem)
        model_name = args.model or os.path.basename(args.result_file).replace('.json', '')
        filter_info = f" (filtered to {len(problem_filter)} problems)" if problem_filter else ""
        print_analysis_results(analysis, raw_data, model_name + filter_info, problem_filter, args.expected_per_problem)
    else:
        import glob
        result_files = glob.glob("result_*.json")
        
        if not result_files:
            print("[Error] No result_*.json files found")
            sys.exit(1)
        
        print(f"Found {len(result_files)} result files")
        
        for file_path in sorted(result_files):
            print(f"\nAnalyzing: {file_path}")
            analysis, raw_data = analyze_single_file(file_path, problem_filter, args.expected_per_problem)
            model_name = os.path.basename(file_path).replace('.json', '').replace('result_', '')
            filter_info = f" (filtered to {len(problem_filter)} problems)" if problem_filter else ""
            print_analysis_results(analysis, raw_data, model_name + filter_info, problem_filter, args.expected_per_problem)

if __name__ == "__main__":
    main() 