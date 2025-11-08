#!/bin/bash

# RQ5: Experiments on OSS-Fuzz
# Evaluates ReduceFix on real OSS-Fuzz crash instances
# Usage: ./rq5.sh [--run] [--regenerate] [--timeout <seconds>]

set -e

RUN_EXPERIMENT=false
REGENERATE_FLAG=""
TIMEOUT=600
MODEL="qwen-plus"
REPAIR_MODEL="qwen-plus"

# Parse arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        --run)
            RUN_EXPERIMENT=true
            shift
            ;;
        --regenerate)
            REGENERATE_FLAG="--regenerate"
            shift
            ;;
        --timeout)
            TIMEOUT="$2"
            shift 2
            ;;
        --model)
            MODEL="$2"
            shift 2
            ;;
        --repair-model)
            REPAIR_MODEL="$2"
            shift 2
            ;;
        -h|--help)
            echo "Usage: $0 [options]"
            echo ""
            echo "Options:"
            echo "  --run              Run complete experiment (Build + Reduce + Repair)"
            echo "  --regenerate       Regenerate statistics"
            echo "  --timeout <sec>    Reduction timeout in seconds (default: 600)"
            echo "  --model <name>     Reducer model (default: qwen-plus)"
            echo "  --repair-model <n> Repair model (default: qwen-plus)"
            echo "  -h, --help         Show this help"
            echo ""
            echo "Examples:"
            echo "  $0                       # Display existing results only"
            echo "  $0 --run                 # Run complete experiment (12 cases)"
            echo "  $0 --run --timeout 900   # Run with 15min timeout"
            echo "  $0 --regenerate          # Regenerate statistics"
            exit 0
            ;;
        *)
            echo "Unknown option: $1" >&2
            echo "Use --help for usage information" >&2
            exit 1
            ;;
    esac
done

echo ""
echo "=============================================="
echo "RQ5: OSS-Fuzz Evaluation Results"
echo "=============================================="
echo ""

# Step 1: Run experiment if requested
if [ "$RUN_EXPERIMENT" = true ]; then
    echo "Mode: Running complete experiment"
    echo "=============================================="
    echo "Total cases: 12 (from cases.json)"
    echo "Timeout: ${TIMEOUT} seconds per reduction"
    echo "Reducer model: ${MODEL}"
    echo "Repair model: ${REPAIR_MODEL}"
    echo ""
    
    # Record start time
    START_TIME=$(date +%s)
    
    # Run complete ReduceFix experiment (Build + Reduce + Repair)
    echo "Starting complete ReduceFix experiment..."
    echo "This will:"
    echo "  1. Build Reducers for each project (one-time per project)"
    echo "  2. Reduce test cases with 3 algorithms (DDMin, ReduceFix, LLM-Generated)"
    echo "  3. Repair bugs with 3 strategies (no_tc, orig_tc, reduced_tc)"
    echo ""
    
    ./oss_fuzz_results/run_ossfuzz.sh \
        --all \
        --model "${MODEL}" \
        --repair-model "${REPAIR_MODEL}" \
        --timeout "${TIMEOUT}"
    
    # Calculate elapsed time
    END_TIME=$(date +%s)
    ELAPSED=$((END_TIME - START_TIME))
    HOURS=$((ELAPSED / 3600))
    MINUTES=$(((ELAPSED % 3600) / 60))
    SECONDS=$((ELAPSED % 60))
    
    echo ""
    echo "=============================================="
    echo "Experiment completed!"
    echo "Total time: ${HOURS}h ${MINUTES}m ${SECONDS}s"
    echo "=============================================="
    echo ""
fi

# Step 2: Generate or use existing statistics
OVERVIEW_FILE="oss_fuzz_results/experiment_results/experiment_overview.json"

if [[ -f "$OVERVIEW_FILE" ]] && [[ -z "$REGENERATE_FLAG" ]] && [ "$RUN_EXPERIMENT" = false ]; then
    echo "Mode: Analysis only (using existing experiment_overview.json)"
    echo "=============================================="
    echo ""
else
    if [[ -n "$REGENERATE_FLAG" ]]; then
        echo "Mode: Regenerating statistics"
    elif [ "$RUN_EXPERIMENT" = true ]; then
        echo "Mode: Generating statistics from new experiment results"
    else
        echo "Mode: Generating statistics (experiment_overview.json not found)"
    fi
    echo "=============================================="
    echo ""
    
    # Run experiment statistics generation
    echo "Generating experiment statistics..."
    echo ""
    
    cd oss_fuzz_results
    python3 compute_experiment_stats.py --model-tag reducefix_${MODEL//-/_} --no-details
    cd ..
    
    echo ""
    echo "Statistics generation complete."
    echo ""
fi

# Step 3: Display results (recalculate pass@k from scratch)
echo "=============================================="
echo "Displaying RQ5 Results (Recalculating Pass@K)"
echo "=============================================="
echo ""

cd oss_fuzz_results
python3 compute_experiment_stats.py --model-tag reducefix_${MODEL//-/_} --paper-format --no-details
cd ..

echo ""
echo "RQ5 analysis complete."
echo ""

