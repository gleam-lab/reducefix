#!/bin/bash

# RQ2: Does supplying the reduced counterexample improve LLM-based repair?
# Tests 3 prompting conditions: Baseline (no test case), Origin Test (full input), Reduced Test (reduced input)
# Uses 4 LLMs and reports pass@k for k ∈ {1,5,10} to quantify repair accuracy gains
# Usage: ./rq2.sh <result_tag> <repair_model> [--regenerate]
#   <result_tag>    Results file suffix and model identifier
#   <repair_model>  LLM model name for repair (e.g., qwen2.5-coder-7b-instruct)
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

if [[ $# -lt 2 ]]; then
  echo "Usage: $0 <result_tag> <repair_model> [--regenerate]" >&2
  echo "Examples:" >&2
  echo "  $0 qwen25-coder7b qwen2.5-coder-7b-instruct" >&2
  echo "  $0 glm4-9b glm4-9b-chat" >&2
  echo "  $0 qwenplus qwen-plus" >&2
  echo "  $0 deepseekv3 deepseek-v3" >&2
  echo "  $0 qwen25-coder7b qwen2.5-coder-7b-instruct --regenerate" >&2
  exit 1
fi

RESULT_TAG="$1"
REPAIR_MODEL="$2"
shift 2
EXTRA_ARGS="$@"   # Pass additional args to evaluate_repair.py

REDUCER_MODEL="qwen-plus"  # Fixed for RQ2
LOG_DIR="rq2_logs"
mkdir -p "$LOG_DIR"

start_time=$(date +%s)

echo "=============================================="
echo "RQ2: Effectiveness of Reduced Test Cases"
echo "=============================================="
echo "Repair model: $REPAIR_MODEL"
echo "Reducer model: $REDUCER_MODEL (fixed)"
echo "Result tag: $RESULT_TAG"
echo "Log directory: $LOG_DIR"
echo "Problems: ${#problems[@]} total"
echo ""
echo "This script evaluates 3 repair strategies:"
echo "  1. Baseline (no test case)"
echo "  2. Origin Test (full failure-inducing input)"
echo "  3. Reduced Test (ReduceFix - reduced input)"
echo "------------------------------------------"

for idx in "${!problems[@]}"; do
  problem="${problems[$idx]}"
  progress=$((idx+1))
  total=${#problems[@]}
  log_file="$LOG_DIR/${problem}_${RESULT_TAG}.log"

  echo "[$progress/$total] Evaluating: $problem"
  echo "--- $(date) ---" > "$log_file"

  # Run repair evaluation with all three strategies
  echo "  Running repair evaluation (3 strategies: baseline, origin, reduced)..."
  echo "python3 evaluate_repair.py $problem --model-tag $RESULT_TAG --reducer-model $REDUCER_MODEL --repair-model $REPAIR_MODEL --max-threads 10 $EXTRA_ARGS" | tee -a "$log_file"
  
  if python3 evaluate_repair.py "$problem" --model-tag "$RESULT_TAG" --reducer-model "$REDUCER_MODEL" --repair-model "$REPAIR_MODEL" --max-threads 10 $EXTRA_ARGS >> "$log_file" 2>&1; then
    echo "    ✓ Repair evaluation completed successfully" | tee -a "$log_file"
  else
    echo "    ✗ Repair evaluation failed" | tee -a "$log_file"
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
echo "RQ2 Batch Processing Complete!"
echo "=============================================="
echo "Total time: ${hours}h ${minutes}m ${seconds}s"
echo "Results file: result_${RESULT_TAG}.json"
echo "Logs: $LOG_DIR/"
echo ""
echo "The results contain pass@k metrics for k ∈ {1,5,10} across:"
echo "  - no_tc: Baseline (no test case)"
echo "  - orig_tc: Origin Test (full input)"
echo "  - reduced_tc: Reduced Test (ReduceFix)"
echo ""
echo "Next steps for RQ2 analysis:"
echo "  python3 summarize_repair_results.py result_${RESULT_TAG}.json"
echo "  python3 analyze_reducer_stats.py result_${RESULT_TAG}.json --model ${RESULT_TAG}"
echo "==============================================" 