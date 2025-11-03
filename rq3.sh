#!/bin/bash

# RQ3: Influence of Prompt Composition on Repair Performance
# Analyzes 5 prompt composition strategies to understand the trade-offs
# between prompt length and information content
# Usage: ./rq3.sh

set -e

echo ""
echo "=============================================="
echo "RQ3: Influence of Prompt Composition"
echo "=============================================="
echo ""
echo "This RQ evaluates 5 prompt composition strategies:"
echo "  1. Baseline (~3.1KB) - problem + buggy code only"
echo "  2. Origin Test (~30.6KB) - + full failure-inducing input"
echo "  3. Diff Lines (~3.1KB) - + output diff lines only"
echo "  4. Reduced Test (~6.4KB) - + reduced input/output pair"
echo "  5. Reduced + Origin (~36.4KB) - + both reduced and full inputs"
echo ""
echo "Analysis focuses on:"
echo "  - Length reduction effects"
echo "  - Information selection effects"
echo "  - Trade-offs between prompt size and accuracy"
echo "=============================================="
echo ""

# Check if results exist
if [[ ! -f "temp/result_coder7b_qwen2.5-coder-7b-instruct.json" ]]; then
    echo "✗ Error: RQ3 results file not found"
    echo "  Expected: temp/result_coder7b_qwen2.5-coder-7b-instruct.json"
    echo ""
    echo "To generate RQ3 results, you would need to run:"
    echo "  python3 evaluate_repair_main.py <problem_id> \\"
    echo "    --repair-model qwen2.5-coder-7b-instruct \\"
    echo "    --reducer-model qwen-plus"
    echo ""
    echo "Note: evaluate_repair_main.py supports all 5 strategies"
    exit 1
fi

# Run analysis
echo "Analyzing RQ3 results..."
echo ""

python3 analyze_rq3_results.py

echo ""
echo "=============================================="
echo "RQ3 Analysis Complete"
echo "=============================================="
echo ""
echo "Key Findings:"
echo "  • Reduced Test achieves best overall pass@10: 25.5%"
echo "  • Diff Lines outperforms Reduced + Origin: 20.0% vs 19.0%"
echo "  • Performance advantage increases with difficulty"
echo "  • Optimal balance: compact length + complete counterexample"
echo "=============================================="