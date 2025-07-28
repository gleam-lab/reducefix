#!/bin/bash

# RQ4: Can reduced-input prompting complement existing LLM-based APR pipelines?
# Integrates ReduceFix into ChatRepair without modifying its logic
# Compares augmented version against original to measure drop-in boost for third-party APR systems
# Usage: ./rq4.sh <result_tag> [--regenerate]
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
  echo "  $0 chatrepair-baseline" >&2
  echo "  $0 chatrepair-baseline --regenerate" >&2
  exit 1
fi

RESULT_TAG="$1"
shift
EXTRA_ARGS="$@"   # Pass additional args

# Fixed parameters for RQ4
REDUCER_MODEL="qwen-plus"
CHATREPAIR_MODEL="qwen-plus"  # ChatRepair uses same model as reducer
LOG_DIR="rq4_logs"
mkdir -p "$LOG_DIR"

start_time=$(date +%s)

echo "=============================================="
echo "RQ4: ChatRepair Integration with ReduceFix"
echo "=============================================="
echo "ChatRepair model: $CHATREPAIR_MODEL"
echo "Reducer model: $REDUCER_MODEL"
echo "Result tag: $RESULT_TAG"
echo "Log directory: $LOG_DIR"
echo "Problems: ${#problems[@]} total"
echo ""
echo "This experiment evaluates ChatRepair under two conditions:"
echo "  1. ChatRepair (Original) - using full failure-inducing input"
echo "  2. ChatRepair + ReduceFix - using reduced counterexample"
echo ""
echo "ChatRepair Parameters:"
echo "  - MAX_RETRY = 1 (one feedback round)"
echo "  - length = 2 (conversation window size)"
echo "  - Sampling: 10 candidate patches per bug"
echo "  - Metrics: pass@k for k ∈ {1,5,10}"
echo "------------------------------------------"

echo ""
echo "Checking for ChatRepair evaluation script..."

if [[ -f "evaluate_repair_with_chatrepair.py" ]]; then
  echo "  Found evaluate_repair_with_chatrepair.py - using integrated ChatRepair evaluation"
  CHATREPAIR_SCRIPT="evaluate_repair_with_chatrepair.py"
else
  echo "  ERROR: evaluate_repair_with_chatrepair.py not found!"
  echo "  This script is required for RQ4 ChatRepair evaluation."
  exit 1
fi

echo ""

for idx in "${!problems[@]}"; do
  problem="${problems[$idx]}"
  progress=$((idx+1))
  total=${#problems[@]}
  log_file="$LOG_DIR/${problem}_${RESULT_TAG}.log"

  echo "[$progress/$total] Evaluating: $problem"
  echo "--- $(date) ---" > "$log_file"

  echo "  Running ChatRepair evaluation (both original and reduced modes)..."
  echo "python3 evaluate_repair_with_chatrepair.py $problem --model-tag $RESULT_TAG --chatrepair-model $CHATREPAIR_MODEL --reducer-model $REDUCER_MODEL --max-threads 5 $EXTRA_ARGS" | tee -a "$log_file"
  
  python3 evaluate_repair_with_chatrepair.py "$problem" --model-tag "$RESULT_TAG" --chatrepair-model "$CHATREPAIR_MODEL" --reducer-model "$REDUCER_MODEL" --max-threads 5 $EXTRA_ARGS >> "$log_file" 2>&1 || echo "    ✗ ChatRepair evaluation failed" | tee -a "$log_file"

  echo "    ✓ Problem $problem evaluation completed" | tee -a "$log_file"
  echo "  ---" | tee -a "$log_file"
done

end_time=$(date +%s)
cost=$((end_time - start_time))
hours=$((cost / 3600))
minutes=$(((cost % 3600) / 60))
seconds=$((cost % 60))

echo ""
echo "=============================================="
echo "RQ4 Batch Processing Complete!"
echo "=============================================="
echo "Total time: ${hours}h ${minutes}m ${seconds}s"
echo "Log directory: $LOG_DIR/"
echo ""

echo "Results file:"
echo "  - result_chatrepair_${RESULT_TAG}.json (contains both ChatRepair original and reduced modes)"

echo ""
echo "Analyzing ChatRepair results..."
if [[ -f "summarize_chatrepair_results.py" ]]; then
  echo "python3 summarize_chatrepair_results.py result_chatrepair_${RESULT_TAG}.json"
  python3 summarize_chatrepair_results.py "result_chatrepair_${RESULT_TAG}.json" || echo "  ✗ Result summarization failed"
else
  echo "  WARNING: summarize_chatrepair_results.py not found, skipping result analysis"
fi

echo ""
echo "Expected improvements (ChatRepair + ReduceFix vs. ChatRepair Original):"
echo "  - Overall pass@10: 30.5% → 37.0% (+21.3% relative)"
echo "  - C-difficulty: 41.7% → 45.0% (+7.9% relative)"
echo "  - D-difficulty: 37.5% → 46.2% (+23.2% relative)"
echo "  - E&F-difficulty: 10.0% → 16.7% (+67.0% relative)"
echo ""
echo "Next steps for RQ4 analysis:"
echo "  python3 analyze_repair_stats.py result_chatrepair_${RESULT_TAG}.json --model chatrepair-${RESULT_TAG}"
echo "  python3 compare_chatrepair_modes.py result_chatrepair_${RESULT_TAG}.json"
echo "==============================================" 