#!/bin/bash

# RQ5: Experiments on OSS-Fuzz
# Evaluates ReduceFix on real OSS-Fuzz crash instances
# Usage: ./rq5.sh

set -e

echo ""
echo "=============================================="
echo "RQ5: OSS-Fuzz Evaluation Results"
echo "=============================================="
echo ""

# Check if experiment results exist
if [[ ! -f "oss_fuzz_results/experiment_results/experiment_overview.json" ]]; then
    echo "✗ Error: experiment_overview.json not found"
    echo "  Please ensure OSS-Fuzz experiments have been run."
    exit 1
fi

# Run the analysis script
echo "Generating RQ5 analysis tables..."
echo ""

python3 << 'PYTHON_SCRIPT'
import json
import sys
from pathlib import Path

# Load experiment results
overview_path = Path("oss_fuzz_results/experiment_results/experiment_overview.json")

with open(overview_path, 'r') as f:
    data = json.load(f)

reduce_results = data.get('reduce', {})
repair_results = data.get('repair', {})

print("="*80)
print("Table 1: Test Case Reduction Comparison")
print("="*80)
print()
print(f"{'Project':<15} {'Samples':>8} | {'ddmin-only':^16} | {'ReduceFix':^16} | {'Pure LLM':^16}")
print(f"{'':15} {'':>8} | {'SR':>7} {'CR':>7} | {'SR':>7} {'CR':>7} | {'SR':>7} {'CR':>7}")
print("-"*80)

# Project ordering as in paper: FFMPEG, IMAGEMAGICK, MUPDF, PHP-SRC, POPPLER
project_order = ['ffmpeg', 'imagemagick', 'mupdf', 'php-src', 'poppler']

# Collect overall statistics
overall_stats = {
    'total_samples': 0,
    'ddmin': {'success': 0, 'total': 0, 'compression_sum': 0.0, 'count': 0},
    'reducefix': {'success': 0, 'total': 0, 'compression_sum': 0.0, 'count': 0},
    'llm': {'success': 0, 'total': 0, 'compression_sum': 0.0, 'count': 0},
}

for project in project_order:
    if project not in reduce_results:
        continue
    
    proj_data = reduce_results[project]
    samples = proj_data.get('samples_eligible', 0)
    
    if samples == 0:
        continue
    
    overall_stats['total_samples'] += samples
    
    # Get data for each strategy
    dd = proj_data.get('ddmin', {})
    rf = proj_data.get('reducefix', {})
    lg = proj_data.get('llm_generated', {})
    
    # Update overall stats
    for strategy_name, strategy_data in [('ddmin', dd), ('reducefix', rf), ('llm', lg)]:
        overall_stats[strategy_name]['success'] += strategy_data.get('success', 0)
        overall_stats[strategy_name]['total'] += strategy_data.get('total', 0)
        
        # Sum compression ratios from case details
        case_details = proj_data.get('case_details', [])
        strategy_key = 'llm_generated' if strategy_name == 'llm' else strategy_name
        for detail in case_details:
            compression_ratio = detail.get(strategy_key, {}).get('compression_ratio', 0.0)
            overall_stats[strategy_name]['compression_sum'] += compression_ratio
            overall_stats[strategy_name]['count'] += 1
    
    dd_sr = dd.get('success_rate', 0.0) * 100
    dd_cr = dd.get('avg_compression_ratio', 0.0) * 100
    rf_sr = rf.get('success_rate', 0.0) * 100
    rf_cr = rf.get('avg_compression_ratio', 0.0) * 100
    lg_sr = lg.get('success_rate', 0.0) * 100
    lg_cr = lg.get('avg_compression_ratio', 0.0) * 100
    
    print(f"{project.upper():<15} {samples:>8} | {dd_sr:>6.1f}% {dd_cr:>6.1f}% | {rf_sr:>6.1f}% {rf_cr:>6.1f}% | {lg_sr:>6.1f}% {lg_cr:>6.1f}%")

# Calculate overall percentages
print("-"*80)

overall_dd_sr = (overall_stats['ddmin']['success'] / overall_stats['ddmin']['total'] * 100) if overall_stats['ddmin']['total'] > 0 else 0.0
overall_dd_cr = (overall_stats['ddmin']['compression_sum'] / overall_stats['ddmin']['count'] * 100) if overall_stats['ddmin']['count'] > 0 else 0.0

overall_rf_sr = (overall_stats['reducefix']['success'] / overall_stats['reducefix']['total'] * 100) if overall_stats['reducefix']['total'] > 0 else 0.0
overall_rf_cr = (overall_stats['reducefix']['compression_sum'] / overall_stats['reducefix']['count'] * 100) if overall_stats['reducefix']['count'] > 0 else 0.0

overall_lg_sr = (overall_stats['llm']['success'] / overall_stats['llm']['total'] * 100) if overall_stats['llm']['total'] > 0 else 0.0
overall_lg_cr = (overall_stats['llm']['compression_sum'] / overall_stats['llm']['count'] * 100) if overall_stats['llm']['count'] > 0 else 0.0

print(f"{'Overall':<15} {overall_stats['total_samples']:>8} | {overall_dd_sr:>6.1f}% {overall_dd_cr:>6.1f}% | {overall_rf_sr:>6.1f}% {overall_rf_cr:>6.1f}% | {overall_lg_sr:>6.1f}% {overall_lg_cr:>6.1f}%")

print()
print("="*80)
print("Table 2: Repair Success Rate (Pass@K)")
print("="*80)
print()
print(f"{'Project':<15} {'Samples':>8} | {'Baseline':^24} | {'Origin Test':^24} | {'Reduced Test':^24}")
print(f"{'':15} {'':>8} | {'@1':>7} {'@5':>7} {'@10':>7} | {'@1':>7} {'@5':>7} {'@10':>7} | {'@1':>7} {'@5':>7} {'@10':>7}")
print("-"*80)

# Helper function to calculate pass@k from unbiased estimator
from math import comb

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

# Collect overall statistics for pass@k
overall_repair_stats = {
    'total_samples': 0,
    'baseline': {1: {'pass_sum': 0.0, 'count': 0}, 5: {'pass_sum': 0.0, 'count': 0}, 10: {'pass_sum': 0.0, 'count': 0}},
    'origin': {1: {'pass_sum': 0.0, 'count': 0}, 5: {'pass_sum': 0.0, 'count': 0}, 10: {'pass_sum': 0.0, 'count': 0}},
    'reduced': {1: {'pass_sum': 0.0, 'count': 0}, 5: {'pass_sum': 0.0, 'count': 0}, 10: {'pass_sum': 0.0, 'count': 0}},
}

for project in project_order:
    if project not in repair_results:
        continue
    
    proj_data = repair_results[project]
    samples = proj_data.get('samples_total', 0)
    
    if samples == 0:
        continue
    
    overall_repair_stats['total_samples'] += samples
    
    # Get case details
    case_details = proj_data.get('case_details', [])
    
    # Calculate pass@k for each strategy from case details
    for detail in case_details:
        for strategy in ['without_test', 'origin_test', 'reduced_test']:
            strategy_key = 'baseline' if strategy == 'without_test' else ('origin' if strategy == 'origin_test' else 'reduced')
            strategy_data = detail.get(strategy, {})
            
            # Use pre-calculated pass@k values
            for k in [1, 5, 10]:
                passk = strategy_data.get(f'pass_at_{k}', 0.0)
                overall_repair_stats[strategy_key][k]['pass_sum'] += passk
                overall_repair_stats[strategy_key][k]['count'] += 1
    
    # Get project-level pass@k
    baseline = proj_data.get('without_test', {})
    origin = proj_data.get('origin_test', {})
    reduced = proj_data.get('reduced_test', {})
    
    bl_p1 = baseline.get('pass_at_1', 0.0) * 100
    bl_p5 = baseline.get('pass_at_5', 0.0) * 100
    bl_p10 = baseline.get('pass_at_10', 0.0) * 100
    
    or_p1 = origin.get('pass_at_1', 0.0) * 100
    or_p5 = origin.get('pass_at_5', 0.0) * 100
    or_p10 = origin.get('pass_at_10', 0.0) * 100
    
    rd_p1 = reduced.get('pass_at_1', 0.0) * 100
    rd_p5 = reduced.get('pass_at_5', 0.0) * 100
    rd_p10 = reduced.get('pass_at_10', 0.0) * 100
    
    print(f"{project.upper():<15} {samples:>8} | {bl_p1:>6.1f}% {bl_p5:>6.1f}% {bl_p10:>6.1f}% | {or_p1:>6.1f}% {or_p5:>6.1f}% {or_p10:>6.1f}% | {rd_p1:>6.1f}% {rd_p5:>6.1f}% {rd_p10:>6.1f}%")

# Calculate overall pass@k percentages
print("-"*80)

overall_bl_p1 = (overall_repair_stats['baseline'][1]['pass_sum'] / overall_repair_stats['baseline'][1]['count'] * 100) if overall_repair_stats['baseline'][1]['count'] > 0 else 0.0
overall_bl_p5 = (overall_repair_stats['baseline'][5]['pass_sum'] / overall_repair_stats['baseline'][5]['count'] * 100) if overall_repair_stats['baseline'][5]['count'] > 0 else 0.0
overall_bl_p10 = (overall_repair_stats['baseline'][10]['pass_sum'] / overall_repair_stats['baseline'][10]['count'] * 100) if overall_repair_stats['baseline'][10]['count'] > 0 else 0.0

overall_or_p1 = (overall_repair_stats['origin'][1]['pass_sum'] / overall_repair_stats['origin'][1]['count'] * 100) if overall_repair_stats['origin'][1]['count'] > 0 else 0.0
overall_or_p5 = (overall_repair_stats['origin'][5]['pass_sum'] / overall_repair_stats['origin'][5]['count'] * 100) if overall_repair_stats['origin'][5]['count'] > 0 else 0.0
overall_or_p10 = (overall_repair_stats['origin'][10]['pass_sum'] / overall_repair_stats['origin'][10]['count'] * 100) if overall_repair_stats['origin'][10]['count'] > 0 else 0.0

overall_rd_p1 = (overall_repair_stats['reduced'][1]['pass_sum'] / overall_repair_stats['reduced'][1]['count'] * 100) if overall_repair_stats['reduced'][1]['count'] > 0 else 0.0
overall_rd_p5 = (overall_repair_stats['reduced'][5]['pass_sum'] / overall_repair_stats['reduced'][5]['count'] * 100) if overall_repair_stats['reduced'][5]['count'] > 0 else 0.0
overall_rd_p10 = (overall_repair_stats['reduced'][10]['pass_sum'] / overall_repair_stats['reduced'][10]['count'] * 100) if overall_repair_stats['reduced'][10]['count'] > 0 else 0.0

print(f"{'Overall':<15} {overall_repair_stats['total_samples']:>8} | {overall_bl_p1:>6.1f}% {overall_bl_p5:>6.1f}% {overall_bl_p10:>6.1f}% | {overall_or_p1:>6.1f}% {overall_or_p5:>6.1f}% {overall_or_p10:>6.1f}% | {overall_rd_p1:>6.1f}% {overall_rd_p5:>6.1f}% {overall_rd_p10:>6.1f}%")

print()
print("="*80)
print("Expected Results (from paper)")
print("="*80)
print()
print("Table 1 - Test Case Reduction:")
print("  FFMPEG:      ddmin=0.0%/0.0%,    ReduceFix=100.0%/35.4%,  LLM=0.0%/0.0%")
print("  IMAGEMAGICK: ddmin=100.0%/4.6%,  ReduceFix=100.0%/5.0%,   LLM=0.0%/0.0%")
print("  MUPDF:       ddmin=100.0%/88.1%, ReduceFix=100.0%/87.4%,  LLM=0.0%/0.0%")
print("  PHP-SRC:     ddmin=100.0%/85.6%, ReduceFix=100.0%/97.7%,  LLM=0.0%/0.0%")
print("  POPPLER:     ddmin=50.0%/22.8%,  ReduceFix=75.0%/25.4%,   LLM=0.0%/0.0%")
print("  Overall:     ddmin=75.0%/51.8%,  ReduceFix=91.7%/56.4%,   LLM=0.0%/0.0%")
print()
print("Table 2 - Repair Success Rate:")
print("  FFMPEG:      Baseline=0.0%/0.0%/0.0%,     Origin=0.0%/0.0%/0.0%,     Reduced=10.0%/50.0%/100.0%")
print("  IMAGEMAGICK: Baseline=0.0%/0.0%/0.0%,     Origin=0.0%/0.0%/0.0%,     Reduced=0.0%/0.0%/0.0%")
print("  MUPDF:       Baseline=10.0%/19.9%/20.0%,  Origin=4.0%/15.6%/20.0%,   Reduced=4.0%/20.0%/40.0%")
print("  PHP-SRC:     Baseline=60.0%/100.0%/100.0%, Origin=0.0%/0.0%/0.0%,    Reduced=100.0%/100.0%/100.0%")
print("  POPPLER:     Baseline=25.0%/25.0%/25.0%,  Origin=22.5%/25.0%/25.0%,  Reduced=25.0%/25.0%/25.0%")
print("  Overall:     Baseline=17.5%/25.0%/25.0%,  Origin=9.2%/14.8%/16.7%,   Reduced=19.2%/29.2%/41.7%")
print("="*80)
print()

PYTHON_SCRIPT

echo "RQ5 analysis complete."
echo ""

