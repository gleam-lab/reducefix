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

# Note: For RQ4, we need a ChatRepair implementation that can switch between
# original and reduced inputs. This might require:
# 1. A modified ChatRepair script that accepts input type parameter
# 2. Integration with our reducer pipeline
# 3. Comparison framework for both approaches

echo ""
echo "Checking for ChatRepair implementation..."

if [[ -f "chatrepair.py" ]]; then
  echo "  Found chatrepair.py - using integrated implementation"
  CHATREPAIR_SCRIPT="chatrepair.py"
elif [[ -f "evaluate_chatrepair.py" ]]; then
  echo "  Found evaluate_chatrepair.py - using specialized ChatRepair evaluator"
  CHATREPAIR_SCRIPT="evaluate_chatrepair.py"
else
  echo "  ChatRepair implementation not found. Creating placeholder..."
  echo "  Note: For full RQ4 reproduction, implement ChatRepair integration"
  echo "  Using standard repair evaluation as approximation..."
  CHATREPAIR_SCRIPT="evaluate_repair.py"
fi

echo ""

for idx in "${!problems[@]}"; do
  problem="${problems[$idx]}"
  progress=$((idx+1))
  total=${#problems[@]}
  log_file="$LOG_DIR/${problem}_${RESULT_TAG}.log"

  echo "[$progress/$total] Evaluating: $problem"
  echo "--- $(date) ---" > "$log_file"

  if [[ "$CHATREPAIR_SCRIPT" == "chatrepair.py" ]]; then
    # Full ChatRepair implementation with both original and reduced modes
    echo "  Running ChatRepair (Original mode)..."
    echo "python3 chatrepair.py $problem --model $CHATREPAIR_MODEL --mode original --max-retry 1 --length 2 --result-tag ${RESULT_TAG}_original $EXTRA_ARGS" | tee -a "$log_file"
    
    python3 chatrepair.py "$problem" --model "$CHATREPAIR_MODEL" --mode original --max-retry 1 --length 2 --result-tag "${RESULT_TAG}_original" $EXTRA_ARGS >> "$log_file" 2>&1 || echo "    ✗ Original mode failed" | tee -a "$log_file"
    
    echo "  Running ChatRepair + ReduceFix (Reduced mode)..."
    echo "python3 chatrepair.py $problem --model $CHATREPAIR_MODEL --mode reduced --max-retry 1 --length 2 --result-tag ${RESULT_TAG}_reduced $EXTRA_ARGS" | tee -a "$log_file"
    
    python3 chatrepair.py "$problem" --model "$CHATREPAIR_MODEL" --mode reduced --max-retry 1 --length 2 --result-tag "${RESULT_TAG}_reduced" $EXTRA_ARGS >> "$log_file" 2>&1 || echo "    ✗ Reduced mode failed" | tee -a "$log_file"
    
  elif [[ "$CHATREPAIR_SCRIPT" == "evaluate_chatrepair.py" ]]; then
    # Specialized ChatRepair evaluator
    echo "  Running ChatRepair comparison (both modes)..."
    echo "python3 evaluate_chatrepair.py $problem --model-tag $RESULT_TAG --chatrepair-model $CHATREPAIR_MODEL --reducer-model $REDUCER_MODEL --max-threads 5 $EXTRA_ARGS" | tee -a "$log_file"
    
    python3 evaluate_chatrepair.py "$problem" --model-tag "$RESULT_TAG" --chatrepair-model "$CHATREPAIR_MODEL" --reducer-model "$REDUCER_MODEL" --max-threads 5 $EXTRA_ARGS >> "$log_file" 2>&1 || echo "    ✗ ChatRepair evaluation failed" | tee -a "$log_file"
    
  else
    # Fallback: use standard repair evaluation as approximation
    echo "  Running standard repair evaluation (approximation for ChatRepair)..."
    echo "python3 evaluate_repair.py $problem --model-tag $RESULT_TAG --reducer-model $REDUCER_MODEL --repair-model $CHATREPAIR_MODEL --max-threads 5 $EXTRA_ARGS" | tee -a "$log_file"
    
    python3 evaluate_repair.py "$problem" --model-tag "$RESULT_TAG" --reducer-model "$REDUCER_MODEL" --repair-model "$CHATREPAIR_MODEL" --max-threads 5 $EXTRA_ARGS >> "$log_file" 2>&1 || echo "    ✗ Repair evaluation failed" | tee -a "$log_file"
  fi

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

if [[ "$CHATREPAIR_SCRIPT" == "chatrepair.py" ]]; then
  echo "Results files:"
  echo "  - result_${RESULT_TAG}_original.json (ChatRepair original)"
  echo "  - result_${RESULT_TAG}_reduced.json (ChatRepair + ReduceFix)"
elif [[ "$CHATREPAIR_SCRIPT" == "evaluate_chatrepair.py" ]]; then
  echo "Results file:"
  echo "  - result_${RESULT_TAG}.json (contains both ChatRepair modes)"
else
  echo "Results file:"
  echo "  - result_${RESULT_TAG}.json (standard repair evaluation)"
  echo "  Note: This is an approximation. Implement ChatRepair integration for exact RQ4."
fi

echo ""
echo "Expected improvements (ChatRepair + ReduceFix vs. ChatRepair Original):"
echo "  - Overall pass@10: 30.5% → 37.0% (+21.3% relative)"
echo "  - C-difficulty: 41.7% → 45.0% (+7.9% relative)"
echo "  - D-difficulty: 37.5% → 46.2% (+23.2% relative)"
echo "  - E&F-difficulty: 10.0% → 16.7% (+67.0% relative)"
echo ""
echo "Next steps for RQ4 analysis:"
if [[ "$CHATREPAIR_SCRIPT" == "chatrepair.py" ]]; then
  echo "  python3 analyze_rq4.py --original result_${RESULT_TAG}_original.json --reduced result_${RESULT_TAG}_reduced.json"
else
  echo "  python3 analyze_rq4.py --result-file result_${RESULT_TAG}.json --chatrepair-comparison"
fi
echo "  python3 compare_chatrepair_modes.py"
echo "==============================================" 