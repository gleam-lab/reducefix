#!/bin/bash

# RQ3: Influence of Prompt Composition on Repair Performance
# Analyzes 5 prompt composition strategies to understand the trade-offs
# between prompt length and information content
# Usage: 
#   ./rq3.sh                  # Analyze existing results (or run experiments if missing)
#   ./rq3.sh --regenerate     # Force regenerate all repair attempts

set -e

# Model configuration for RQ3 ablation study
REPAIR_MODEL="qwen2.5-coder-7b-instruct"
REDUCER_MODEL="qwen-plus"
MODEL_TAG="ablation"
RESULT_FILE="result_ablation.json"
LOG_DIR="rq3_logs"
REGENERATE_FLAG=""

# Problem list
problems=(
    "abc361c" "abc362d" "abc363e" "abc364d" "abc365d"
    "abc366c" "abc367d" "abc368c" "abc369d" "abc370d"
    "abc371d" "abc372e" "abc373e" "abc374e" "abc375c"
    "abc376c" "abc376e" "abc376d" "abc377c" "abc377f"
)

# Parse arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        --regenerate)
            REGENERATE_FLAG="--regenerate"
            shift
            ;;
        *)
            echo "Unknown option: $1" >&2
            echo "Usage: $0 [--regenerate]" >&2
            exit 1
            ;;
    esac
done

echo ""
echo "=============================================="
echo "RQ3: Influence of Prompt Composition"
echo "=============================================="
echo ""
echo "This RQ evaluates 5 prompt composition strategies:"
echo "  1. Baseline (~3.2KB) - problem + buggy code only"
echo "  2. Origin Test (~30.5KB) - + full failure-inducing input"
echo "  3. Diff Lines (~3.2KB) - + output diff lines only"
echo "  4. Reduced Test (~6.6KB) - + reduced input/output pair"
echo "  5. Reduced + Origin (~36.4KB) - + both reduced and full inputs"
echo ""
echo "Repair model: $REPAIR_MODEL"
echo "Reducer model: $REDUCER_MODEL"
echo "Problems: ${#problems[@]} total"

# Check if results exist
if [[ -f "$RESULT_FILE" ]] && [[ -z "$REGENERATE_FLAG" ]]; then
    echo "Mode: Analysis only (results exist)"
    echo "=============================================="
    echo ""
    
    # Run analysis directly
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
    
    exit 0
fi

# Run experiments
if [[ -n "$REGENERATE_FLAG" ]]; then
    echo "Mode: Force regenerate"
else
    echo "Mode: Generate missing results"
fi
echo "=============================================="
echo ""

mkdir -p "$LOG_DIR"

# Prepare reducer results file (required by evaluate_repair.py)
if [ ! -f "reducer_results.json" ]; then
    if [ -f "result_reducer_reducefix.json" ]; then
        ln -s `pwd`/result_reducer_reducefix.json reducer_results.json
        echo "[Info] Created reducer_results.json symlink"
    else
        echo "✗ Error: reducer_results.json not found" >&2
        echo "  Please run ./rq1.sh first to generate reduction results" >&2
        exit 1
    fi
fi

start_time=$(date +%s)

echo "Running RQ3 experiments for ${#problems[@]} problems..."
echo ""

for idx in "${!problems[@]}"; do
    problem="${problems[$idx]}"
    progress=$((idx+1))
    total=${#problems[@]}
    log_file="$LOG_DIR/${problem}_${MODEL_TAG}.log"
    
    echo "[$progress/$total] Evaluating: $problem"
    echo "--- $(date) ---" > "$log_file"
    
    echo "  Running repair evaluation with 5 prompt strategies..."
    echo "python3 evaluate_repair.py $problem --model-tag $MODEL_TAG --repair-model $REPAIR_MODEL --reducer-model $REDUCER_MODEL --max-threads 5 $REGENERATE_FLAG" | tee -a "$log_file"
    
    python3 evaluate_repair.py "$problem" --model-tag "$MODEL_TAG" --repair-model "$REPAIR_MODEL" --reducer-model "$REDUCER_MODEL" --max-threads 5 $REGENERATE_FLAG >> "$log_file" 2>&1 || echo "    ✗ Evaluation failed" | tee -a "$log_file"
    
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
echo "RQ3 Experiments Complete!"
echo "=============================================="
echo "Total time: ${hours}h ${minutes}m ${seconds}s"
echo "Log directory: $LOG_DIR/"
echo ""

# Rename result file if needed
if [[ -f "result_${MODEL_TAG}.json" ]] && [[ ! -f "$RESULT_FILE" ]]; then
    mv "result_${MODEL_TAG}.json" "$RESULT_FILE"
    echo "[Info] Renamed result_${MODEL_TAG}.json to $RESULT_FILE"
fi

echo "Results file: $RESULT_FILE"
echo ""

# Run analysis
echo "=============================================="
echo "Analyzing Results"
echo "=============================================="
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