#!/bin/bash

# RQ4: Can reduced-input prompting complement existing LLM-based APR pipelines?
# Integrates ReduceFix into ChatRepair and CREF without modifying their logic
# Compares augmented version against original to measure drop-in boost for third-party APR systems
# Usage: 
#   ./rq4.sh                    Display analysis results only (default)
#   ./rq4.sh <result_tag> [--regenerate]  Run experiments

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

# If no arguments, just show analysis
if [[ $# -eq 0 ]]; then
  echo ""
  echo "=============================================="
  echo "RQ4: APR Pipeline Integration with ReduceFix"
  echo "=============================================="
  echo ""
  
  # ChatRepair results
  echo "ChatRepair Results:"
  echo "-------------------------------------------"
  if [[ -f "result_chatrepair.json" ]]; then
    python3 summarize_chatrepair_results.py "chatrepair" --strategies chatrepair_from_orig chatrepair_from_reduced || echo "  ✗ ChatRepair result summarization failed"
  else
    echo "  WARNING: result_chatrepair.json not found"
  fi

  echo ""
  echo "-------------------------------------------"
  echo ""

  # CRef results
  echo "CRef Results:"
  echo "-------------------------------------------"
  if [[ -f "result_cref.json" ]]; then
    python3 summarize_chatrepair_results.py "cref" --strategies cref_from_orig cref_from_reduced || echo "  ✗ CRef result summarization failed"
  else
    echo "  WARNING: result_cref.json not found"
  fi

  echo ""
  echo "=============================================="
  echo "RQ4 Analysis Complete"
  echo "=============================================="
  echo ""
  
  exit 0
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
echo "RQ4: APR Pipeline Integration with ReduceFix"
echo "=============================================="
echo "ChatRepair model: $CHATREPAIR_MODEL"
echo "Reducer model: $REDUCER_MODEL"
echo "Result tag: $RESULT_TAG"
echo "Log directory: $LOG_DIR"
echo "Problems: ${#problems[@]} total"
echo ""
echo "This experiment evaluates APR systems under two conditions:"
echo "  1. Original - using full failure-inducing input"
echo "  2. + ReduceFix - using reduced counterexample"
echo ""
echo "APR Systems evaluated:"
echo "  • ChatRepair - conversational repair with feedback"
echo "  • CRef - context-aware reference-based repair"
echo ""
echo "Parameters:"
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
echo "=============================================="
echo "Analyzing Results"
echo "=============================================="
echo ""

# ChatRepair results
echo "ChatRepair Results:"
echo "-------------------------------------------"
if [[ -f "result_chatrepair.json" ]]; then
  echo "python3 summarize_chatrepair_results.py chatrepair"
  python3 summarize_chatrepair_results.py "chatrepair" || echo "  ✗ ChatRepair result summarization failed"
else
  echo "  WARNING: result_chatrepair.json not found"
fi

echo ""
echo "-------------------------------------------"
echo ""

# CRef results
echo "CRef Results:"
echo "-------------------------------------------"
if [[ -f "result_cref.json" ]]; then
  echo "python3 summarize_chatrepair_results.py cref"
  python3 summarize_chatrepair_results.py "cref" || echo "  ✗ CRef result summarization failed"
else
  echo "  WARNING: result_cref.json not found"
fi

echo ""
echo "=============================================="
echo "RQ4 Experiment and Analysis Complete"
echo "==============================================" 