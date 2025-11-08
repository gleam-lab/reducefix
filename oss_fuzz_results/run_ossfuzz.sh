#!/bin/bash

# OSS-Fuzz ReduceFix One-Click Execution Script
# RQ5 Experiment - Migrated from ../reduce/oss_fuzz/experiment/run_ossfuzz.sh

set -e  # Exit on error

# Color definitions
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Usage
usage() {
    echo "Usage: $0 [options]"
    echo ""
    echo "Options:"
    echo "  --project <name>     Specify single project (e.g., mupdf, ffmpeg)"
    echo "  --all                Run all projects (default)"
    echo "  --model <name>       Reducer generation model (default: qwen-plus)"
    echo "  --repair-model <nm>  Repair model (default: qwen-plus)"
    echo "  --timeout <seconds>  Reduction timeout in seconds (default: 600=10min)"
    echo "  --skip-build         Skip reducer generation (use existing)"
    echo "  --skip-reduce        Skip reduce step"
    echo "  --skip-repair        Skip repair step"
    echo "  --force              Force rerun completed steps"
    echo "                       (default: automatically skip existing results)"
    echo "  -h, --help           Show this help"
    echo ""
    echo "Examples:"
    echo "  $0                              # Run all projects"
    echo "  $0 --project mupdf              # Run mupdf project only"
    echo "  $0 --project mupdf --model qwen-plus"
    echo "  $0 --all --skip-build           # Use existing reducer, reduce+repair only"
    echo "  $0 --project mupdf --force      # Force rerun (ignore existing results)"
    echo "  $0 --project mupdf --timeout 900  # Set 15min timeout"
    echo ""
    exit 1
}

# Default parameters
PROJECT=""
RUN_ALL=true
MODEL="qwen-plus"
REPAIR_MODEL="qwen-plus"
REDUCE_TIMEOUT=600  # Default 10 minutes (600 seconds)
SKIP_BUILD=false
SKIP_REDUCE=false
SKIP_REPAIR=false
FORCE_RERUN=false

# Parse command line arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        --project)
            PROJECT="$2"
            RUN_ALL=false
            shift 2
            ;;
        --all)
            RUN_ALL=true
            shift
            ;;
        --model)
            MODEL="$2"
            shift 2
            ;;
        --repair-model)
            REPAIR_MODEL="$2"
            shift 2
            ;;
        --timeout)
            REDUCE_TIMEOUT="$2"
            shift 2
            ;;
        --skip-build)
            SKIP_BUILD=true
            shift
            ;;
        --skip-reduce)
            SKIP_REDUCE=true
            shift
            ;;
        --skip-repair)
            SKIP_REPAIR=true
            shift
            ;;
        --force)
            FORCE_RERUN=true
            shift
            ;;
        -h|--help)
            usage
            ;;
        *)
            echo -e "${RED}Error: Unknown option '$1'${NC}"
            usage
            ;;
    esac
done

# Validate parameters
if [ "$RUN_ALL" = false ] && [ -z "$PROJECT" ]; then
    echo -e "${RED}Error: Must specify --project or --all${NC}"
    usage
fi

# Print configuration
echo "========================================"
echo "OSS-Fuzz ReduceFix Complete Workflow (RQ5)"
echo "========================================"
echo ""
echo "Configuration:"
if [ "$RUN_ALL" = true ]; then
    echo "  Run mode: All projects"
else
    echo "  Run mode: Single project ($PROJECT)"
fi
echo "  Reducer model: $MODEL"
echo "  Repair  model: $REPAIR_MODEL"
echo "  Skip Build: $SKIP_BUILD"
echo "  Skip Reduce: $SKIP_REDUCE"
echo "  Skip Repair: $SKIP_REPAIR"
echo "  Force rerun: $FORCE_RERUN"
echo "  Reduce timeout limit: ${REDUCE_TIMEOUT} seconds/method"
echo ""

# Build command
# Use rerun_all_strategies.py as main execution script
CMD="python3 oss_fuzz_results/rerun_all_strategies.py"

# Add parameters
CMD="$CMD --model-tag reducefix_${MODEL//-/_}"
CMD="$CMD --repair-model $REPAIR_MODEL"
CMD="$CMD --timeout $REDUCE_TIMEOUT"

if [ "$RUN_ALL" = true ]; then
    # Don't specify case-ids, script will run all cases automatically
    CMD="$CMD"
elif [ -n "$PROJECT" ]; then
    CMD="$CMD --target $PROJECT"
fi

if [ "$SKIP_BUILD" = true ]; then
    CMD="$CMD --skip-build"
fi

if [ "$SKIP_REDUCE" = true ]; then
    CMD="$CMD --skip-reduce"
fi

if [ "$SKIP_REPAIR" = true ]; then
    CMD="$CMD --skip-repair"
fi

if [ "$FORCE_RERUN" = true ]; then
    CMD="$CMD --force"
fi

# Show command
echo "Starting execution..."
echo "Command: $CMD"
echo ""

# Record start time
START_TIME=$(date +%s)

# Execute command
$CMD

# Calculate elapsed time
END_TIME=$(date +%s)
ELAPSED=$((END_TIME - START_TIME))
MINUTES=$((ELAPSED / 60))
SECONDS=$((ELAPSED % 60))

# Print results
echo ""
echo "========================================"
echo -e "${GREEN}✓ Experiment completed!${NC}"
echo "========================================"
echo "Total time: ${MINUTES}min ${SECONDS}sec"
echo ""

# Calculate and display repair strategy success rate statistics
if [ "$SKIP_REPAIR" = false ]; then
    echo -e "${YELLOW}Generating repair statistics...${NC}"
    python3 oss_fuzz_results/compute_repair_stats.py --base-dir oss_fuzz_results/cases_data --detailed
fi

echo ""
echo "Result locations:"
echo "  - Reduced test cases: oss_fuzz_results/cases_data/<project>/<case_id>/reducefix_*/reduced.reducefix"
echo "  - Repair results: oss_fuzz_results/cases_data/<project>/<case_id>/reducefix_*/*/patches/"
echo "  - Evaluation results: oss_fuzz_results/cases_data/<project>/<case_id>/reducefix_*/*_evaluation.json"
echo ""
echo "Tip: View detailed results with these commands:"
echo "  python3 oss_fuzz_results/compute_repair_stats.py --detailed"
echo "  python3 oss_fuzz_results/compute_experiment_stats.py --model-tag reducefix_${MODEL//-/_}"
echo ""
