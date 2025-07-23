#!/bin/bash

# RQ3: How does prompt composition influence repair accuracy?
# Studies 3 different prompt variants: Reduced Test, Diff Lines, and Reduced + Origin Test
# Compares their average lengths and pass@k to distinguish benefits of shorter prompts vs reduced information
# Usage: ./rq3.sh <result_tag> [--regenerate]
#   <result_tag>    Results file suffix
#   --regenerate    (Optional) Force regenerate all repair attempts

set -e

problems=(
    "abc361c"
    "abc362d"
    "abc363e"
    "abc364d"
    "abc365d"
    "abc366c"
    "abc367d"
    "abc368c"
    "abc369d"
    "abc370d"
    "abc371d"
    "abc372e"
    "abc373e"
    "abc374e"
    "abc375c"
    "abc376c"
    "abc376e"
    "abc376d"
    "abc377c"
    "abc377f"
)

if [[ $# -lt 1 ]]; then
  echo "Usage: $0 <result_tag> [--regenerate]" >&2
  echo "Examples:" >&2
  echo "  $0 qwen25-ablation" >&2
  echo "  $0 qwen25-ablation --regenerate" >&2
  exit 1
fi

RESULT_TAG="$1"
shift
EXTRA_ARGS="$@"   # Pass additional args to evaluate_repair.py

# Fixed parameters for RQ3 - using Qwen2.5-Coder-7B as specified in paper
REPAIR_MODEL="qwen2.5-coder-7b-instruct"
REDUCER_MODEL="qwen-plus"
LOG_DIR="rq3_logs"
mkdir -p "$LOG_DIR"

start_time=$(date +%s)

echo "=============================================="
echo "RQ3: Influence of Prompt Composition"
echo "=============================================="
echo "Repair model: $REPAIR_MODEL (fixed for RQ3)"
echo "Reducer model: $REDUCER_MODEL (fixed)"
echo "Result tag: $RESULT_TAG"
echo "Log directory: $LOG_DIR"
echo "Problems: ${#problems[@]} total"
echo ""
echo "This script evaluates 5 prompt composition strategies:"
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
echo "------------------------------------------"

# Note: RQ3 uses a specialized version of evaluate_repair.py that supports
# additional prompt strategies (diff_only, reduced_plus_diff)
# The current evaluate_repair.py supports 3 strategies; for RQ3 we would need
# to extend it or use a specialized version

for idx in "${!problems[@]}"; do
  problem="${problems[$idx]}"
  progress=$((idx+1))
  total=${#problems[@]}
  log_file="$LOG_DIR/${problem}_${RESULT_TAG}.log"

  echo "[$progress/$total] Evaluating: $problem"
  echo "--- $(date) ---" > "$log_file"

  # Run repair evaluation with extended strategies for RQ3
  echo "  Running prompt composition analysis (5 strategies)..."
  
  # Check if evaluate_repair_main.py exists (extended version for RQ3)
  if [[ -f "evaluate_repair_main.py" ]]; then
    evaluation_script="evaluate_repair_main.py"
    echo "  Using extended evaluation script: $evaluation_script"
  else
    evaluation_script="evaluate_repair.py" 
    echo "  Using standard evaluation script: $evaluation_script"
    echo "  Note: This supports 3 strategies. For full RQ3 with 5 strategies,"
    echo "        implement diff_only and reduced_plus_diff strategies."
  fi
  
  echo "python3 $evaluation_script $problem --model-tag $RESULT_TAG --reducer-model $REDUCER_MODEL --repair-model $REPAIR_MODEL --max-threads 10 $EXTRA_ARGS" | tee -a "$log_file"
  
  if python3 "$evaluation_script" "$problem" --model-tag "$RESULT_TAG" --reducer-model "$REDUCER_MODEL" --repair-model "$REPAIR_MODEL" --max-threads 10 $EXTRA_ARGS >> "$log_file" 2>&1; then
    echo "    ✓ Prompt composition evaluation completed successfully" | tee -a "$log_file"
  else
    echo "    ✗ Prompt composition evaluation failed" | tee -a "$log_file"
  fi

  echo "  ---" | tee -a "$log_file"
done

end_time=$(date +%s)
cost=$((end_time - start_time))
hours=$((cost / 3600))
minutes=$(((cost % 3600) / 60))
seconds=$((cost % 60))

echo ""
echo "=============================================="
echo "RQ3 Batch Processing Complete!"
echo "=============================================="
echo "Total time: ${hours}h ${minutes}m ${seconds}s"
echo "Results file: result_${RESULT_TAG}.json"
echo "Logs: $LOG_DIR/"
echo ""
echo "Expected prompt composition strategies in results:"
echo "  - no_tc: Baseline (~3.1KB)"
echo "  - orig_tc: Origin Test (~30.6KB)"  
echo "  - reduced_tc: Reduced Test (~6.4KB)"
if [[ -f "evaluate_repair_main.py" ]]; then
echo "  - diff_only: Diff Lines (~3.1KB)"
echo "  - reduced_plus_diff: Reduced + Origin (~36.4KB)"
fi
echo ""
echo "Next steps for RQ3 analysis:"
echo "  python3 analyze_rq3.py --result-file result_${RESULT_TAG}.json --prompt-analysis"
echo "  python3 summarize_repair_results.py result_${RESULT_TAG}.json"
echo ""
echo "Expected findings:"
echo "  - Reduced Test should achieve best overall performance (~25.5% pass@10)"
echo "  - Diff Lines should be superior to Reduced + Origin"
echo "  - Length vs. information content trade-offs clearly visible"
echo "==============================================" 