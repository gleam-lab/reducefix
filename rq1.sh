#!/bin/bash

# RQ1: How reliable are LLM-generated reducers at shrinking failure-inducing inputs?
# Evaluates reducer generation and input reduction phases through success rate and compression ratio
# Compares LLM-generated reducers (with ddmin) against pure LLM-based input reduction
# Usage: ./rq1.sh <result_tag> [--force]
#   <result_tag>   Results file suffix, e.g., qwen-baseline -> result_qwen-baseline.json
#   --force        (Optional) Force re-testing existing records in reducer_test.py

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
  echo "Usage: $0 <result_tag> [--force]" >&2
  echo "Example: $0 qwen-baseline" >&2
  echo "         $0 qwen-regenerate --force" >&2
  exit 1
fi

RESULT_TAG="$1"
shift
EXTRA_TEST_ARGS="$@"   # Pass additional args to reducer_test.py

LLM_MODEL="qwen-plus"
LOG_DIR="rq1_logs"
mkdir -p "$LOG_DIR"

start_time=$(date +%s)

echo "=============================================="
echo "RQ1: Effectiveness of LLM-generated Reducers"
echo "=============================================="
echo "Model: $LLM_MODEL"
echo "Result tag: $RESULT_TAG"
echo "Log directory: $LOG_DIR"
echo "Problems: ${#problems[@]} total"
echo "------------------------------------------"

for idx in "${!problems[@]}"; do
  problem="${problems[$idx]}"
  progress=$((idx+1))
  total=${#problems[@]}
  log_file="$LOG_DIR/${problem}.log"

  echo "[$progress/$total] Processing: $problem"
  echo "--- $(date) ---" > "$log_file"

  # Step 1: Generate reducer.py
  echo "  Phase 1: Generating reducer..."
  echo "python3 reducer_builder.py $problem --llm-model $LLM_MODEL --model-tag $RESULT_TAG" | tee -a "$log_file"
  if python3 reducer_builder.py "$problem" --llm-model "$LLM_MODEL" --model-tag "$RESULT_TAG" >> "$log_file" 2>&1; then
    echo "    ✓ Reducer generation successful" | tee -a "$log_file"
  else
    echo "    ✗ Reducer generation failed, skipping testing phase" | tee -a "$log_file"
    continue
  fi

  # Step 2: Test reducer and collect data for RQ1 analysis
  echo "  Phase 2: Testing reducer and collecting WA submissions..."
  echo "python3 reducer_test.py $problem --model-tag $RESULT_TAG --reducer-model $LLM_MODEL $EXTRA_TEST_ARGS" | tee -a "$log_file"
  if python3 reducer_test.py "$problem" --model-tag "$RESULT_TAG" --reducer-model "$LLM_MODEL" $EXTRA_TEST_ARGS >> "$log_file" 2>&1; then
    echo "    ✓ Reducer testing successful" | tee -a "$log_file"
  else
    echo "    ✗ Reducer testing failed" | tee -a "$log_file"
  fi

  echo "  ---" | tee -a "$log_file"
done

# Step 3: Consolidate results for analysis
echo ""
echo "Consolidating reducer results..."
python3 consolidate_reducer_results.py --incremental

end_time=$(date +%s)
cost=$((end_time - start_time))
hours=$((cost / 3600))
minutes=$(((cost % 3600) / 60))
seconds=$((cost % 60))

echo ""
echo "=============================================="
echo "RQ1 Batch Processing Complete!"
echo "=============================================="
echo "Total time: ${hours}h ${minutes}m ${seconds}s"
echo "Results files:"
echo "  - reducer_results.json (consolidated reducer test results)"
echo "  - result_${RESULT_TAG}.json (individual problem results)"
echo "  - Logs: $LOG_DIR/"
echo ""
echo "Next steps for RQ1 analysis:"
echo "  python3 analyze_rq1.py --result-file reducer_results.json"
echo "==============================================" 