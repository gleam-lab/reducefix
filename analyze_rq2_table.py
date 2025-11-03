#!/usr/bin/env python3
"""
Generate RQ2 table for paper (Table 3 format)
Analyzes all 4 LLMs across 3 repair strategies and reports pass@k by difficulty
"""

import json
import sys
from collections import defaultdict
from math import comb

# Model configurations
MODELS = {
    'qwen25-coder7b': 'Qwen2.5-Coder-7B-instruct',
    'glm4-9b': 'GLM-4-9B-chat',
    'qwenplus': 'Qwen-Plus',
    'deepseekv3': 'DeepSeek-V3'
}

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
    
    where:
    - n = total number of versions (should be 10)
    - c = number of versions that passed
    - k = number of samples to evaluate
    
    This represents the probability that at least one of k randomly 
    sampled versions will pass.
    
    Returns a probability value (0.0 to 1.0) for a single submission.
    """
    if not versions:
        return 0.0
    
    n = len(versions)
    c = sum(1 for v in versions if v.get('passed', False))
    
    # If all samples failed, pass@k = 0
    if c == 0:
        return 0.0
    
    # If not enough failing samples to draw k without including a pass
    if n - c < k:
        return 1.0
    
    # Calculate using the formula
    try:
        numerator = comb(n - c, k)  # Ways to choose k from non-passing samples
        denominator = comb(n, k)     # Total ways to choose k samples
        return 1.0 - (numerator / denominator)
    except (ValueError, ZeroDivisionError):
        return 0.0

def find_result_file(model_tag):
    """Find result file with new naming convention"""
    import os
    
    # New naming convention: result_repair_{model}.json
    new_format = f"result_repair_{model_tag}.json"
    if os.path.exists(new_format):
        return new_format
    
    # Fallback to old naming patterns for backward compatibility
    patterns = []
    
    if model_tag == "qwen25-coder7b":
        patterns.append("result_coder7b_qwen2.5-coder-7b-instruct.json")
    elif model_tag == "qwenplus":
        patterns.append("result_qwenplus-qwenplus.json")
        patterns.append("result_qwenplus.json")
    else:
        patterns.append(f"result_qwenplus-{model_tag}.json")
        patterns.append(f"result_{model_tag}.json")
    
    for pattern in patterns:
        if os.path.exists(pattern):
            return pattern
    
    return None

def analyze_model_results(result_file):
    """Analyze a single model's results using unbiased pass@k"""
    try:
        with open(result_file, 'r') as f:
            data = json.load(f)
    except (FileNotFoundError, TypeError):
        return None
    
    # Structure: stats[strategy][difficulty] = {'total': count, 'pass@1_sum': sum, ...}
    # We accumulate probability sums and counts, then compute averages
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

def print_text_summary(all_model_stats):
    """Print text summary for quick review"""
    print("\n" + "="*100)
    print("RQ2 Summary: Pass@k Across 4 LLMs and 3 Strategies (Unbiased Estimator)")
    print("="*100)
    
    for model_tag, model_name in MODELS.items():
        stats = all_model_stats.get(model_tag)
        if not stats:
            continue
        
        print(f"\n{model_name}:")
        print("-"*100)
        print(f"{'Difficulty':<12} {'Strategy':<15} {'Total':<8} {'pass@1':<15} {'pass@5':<15} {'pass@10':<15}")
        print("-"*100)
        
        for difficulty in ['C', 'D', 'E&F', 'Overall']:
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
                
                diff_str = difficulty if strategy_key == 'no_tc' else ''
                
                print(f"{diff_str:<12} {strategy_name:<15} {s['total']:<8} "
                      f"{p1:>6.1f}%        {p5:>6.1f}%        {p10:>6.1f}%")
            
            if difficulty != 'Overall':
                print()
    
    print("="*100)

def main():
    print("Analyzing RQ2 results for all 4 LLMs...")
    print()
    
    all_model_stats = {}
    
    for model_tag, model_name in MODELS.items():
        result_file = find_result_file(model_tag)
        
        if result_file:
            print(f"Loading {model_name}: {result_file}")
            stats = analyze_model_results(result_file)
            if stats:
                all_model_stats[model_tag] = stats
                print(f"  ✓ Loaded")
            else:
                print(f"  ✗ Failed to parse")
        else:
            print(f"Loading {model_name}: NOT FOUND")
            print(f"  ✗ No result file for {model_tag}")
    
    if not all_model_stats:
        print("\nError: No result files found", file=sys.stderr)
        print("Run: ./rq2_batch.sh first", file=sys.stderr)
        sys.exit(1)
    
    print(f"\nSuccessfully loaded {len(all_model_stats)}/{len(MODELS)} models")
    
    # Print text summary
    print_text_summary(all_model_stats)

if __name__ == "__main__":
    main()

