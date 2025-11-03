#!/bin/bash

# RQ1: How reliable are LLM-generated reducers at shrinking failure-inducing inputs?
# Evaluates reducer generation and input reduction phases through success rate and compression ratio
# Compares LLM-generated reducers (with ddmin) against pure LLM-based input reduction
# 
# Usage: 
#   ./rq1.sh [--force]                              # Run all problems, force re-test if --force
#   ./rq1.sh --retest <problem_id> <submission_id>  # Test single submission with all 3 methods
#
# Examples:
#   ./rq1.sh                                # Normal run (skip existing results)
#   ./rq1.sh --force                        # Force re-test all
#   ./rq1.sh --retest abc361c 67213592     # Test single submission with 3 methods

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

# Check for --retest mode
if [ "$1" = "--retest" ]; then
    if [ $# -lt 3 ]; then
        echo "Error: --retest requires problem_id and submission_id" >&2
        echo "Usage: $0 --retest <problem_id> <submission_id>" >&2
        echo "Example: $0 --retest abc361c 67213592" >&2
        exit 1
    fi
    
    RETEST_MODE=true
    RETEST_PROBLEM="$2"
    RETEST_SUBMISSION="$3"
    shift 3
    EXTRA_TEST_ARGS="$@"
else
    RETEST_MODE=false
    EXTRA_TEST_ARGS="$@"
fi

LLM_MODEL="qwen-plus"
LOG_DIR="rq1_logs"
mkdir -p "$LOG_DIR"

start_time=$(date +%s)

# ============================================================================
# RETEST MODE: Test single submission with all 3 methods
# ============================================================================
if [ "$RETEST_MODE" = true ]; then
    python3 retest_single.py "$RETEST_PROBLEM" "$RETEST_SUBMISSION" "$LLM_MODEL"
    exit 0
fi

# ============================================================================
# NORMAL MODE: Run all problems
# ============================================================================
echo "=============================================="
echo "RQ1: Effectiveness of LLM-generated Reducers"
echo "=============================================="
echo "Model: $LLM_MODEL"
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

  # Step 1: Check if reducer already exists, skip generation if present
  reducer_file="results/$problem/reducer.py"
  if [ -f "$reducer_file" ]; then
    echo "  Phase 1: Reducer already exists, skipping generation" | tee -a "$log_file"
    echo "    ✓ Using existing reducer: $reducer_file" | tee -a "$log_file"
  else
    # Generate reducer.py
    echo "  Phase 1: Generating reducer..." | tee -a "$log_file"
    echo "python3 reducer_builder.py $problem --llm-model $LLM_MODEL" | tee -a "$log_file"
    if python3 reducer_builder.py "$problem" --llm-model "$LLM_MODEL" >> "$log_file" 2>&1; then
      echo "    ✓ Reducer generation successful" | tee -a "$log_file"
    else
      echo "    ✗ Reducer generation failed, skipping testing phase" | tee -a "$log_file"
      continue
    fi
  fi

  # Step 2: Check if testing results already exist (unless --force is specified)
  skip_testing=false
  if [ -f "result_reducer_reducefix.json" ] && [[ ! " $EXTRA_TEST_ARGS " =~ " --force " ]]; then
    # Check if problem already has >= 10 results in consolidated file
    existing_count=$(python3 -c "
import json, sys
try:
    with open('result_reducer_reducefix.json', 'r') as f:
        data = json.load(f)
    count = len(data.get('$problem', {}).get('results', []))
    print(count)
except:
    print(0)
" 2>/dev/null)
    
    if [ "$existing_count" -ge 10 ]; then
      echo "  Phase 2: Found $existing_count existing results, skipping testing" | tee -a "$log_file"
      echo "    ✓ Using existing test results (use --force to override)" | tee -a "$log_file"
      skip_testing=true
    fi
  fi
  
  if [ "$skip_testing" = false ]; then
    # Run testing
    echo "  Phase 2: Testing reducer and collecting WA submissions..." | tee -a "$log_file"
    echo "python3 reducer_test.py $problem --reducer-model $LLM_MODEL $EXTRA_TEST_ARGS" | tee -a "$log_file"
    cd results && \
    if python3 ../reducer_test.py "$problem" --reducer-model "$LLM_MODEL" $EXTRA_TEST_ARGS >> "../$log_file" 2>&1; then
      cd ..
      echo "    ✓ Reducer testing successful" | tee -a "$log_file"
    else
      cd ..
      echo "    ✗ Reducer testing failed" | tee -a "$log_file"
    fi
  fi

  echo "  ---" | tee -a "$log_file"
done

# Step 3: Check baseline results availability
echo ""
echo "Step 3: Checking baseline results..."
missing_files=""
[ ! -f "result_reducer_ddmin.json" ] && missing_files="$missing_files result_reducer_ddmin.json"
[ ! -f "result_reducer_llm.json" ] && missing_files="$missing_files result_reducer_llm.json"

if [ -n "$missing_files" ]; then
  echo "  ✗ Warning: Missing baseline files:$missing_files"
  echo "  Note: These files should be included in the repository"
else
  echo "  ✓ All baseline results present"
fi

# Step 4: Generate comparative RQ1 statistical analysis
echo ""
echo "Step 4: Generating RQ1 comparative statistical analysis..."

if [ -f "result_reducer_reducefix.json" ] && [ -f "result_reducer_ddmin.json" ]; then
  python3 compare_rq1_methods.py
else
  echo "Warning: Missing result files for comparison"
  [ ! -f "result_reducer_reducefix.json" ] && echo "  - result_reducer_reducefix.json not found"
  [ ! -f "result_reducer_ddmin.json" ] && echo "  - result_reducer_ddmin.json not found"
fi
