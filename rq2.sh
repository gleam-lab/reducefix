#!/bin/bash

# RQ2: Comprehensive Multi-LLM Evaluation
# Tests 3 prompting conditions across 4 LLMs
# Usage: ./rq2.sh [--regenerate] [--model <model_tag>]
#   --regenerate    Force regenerate all repair attempts
#   --model <tag>   Only run specific model (qwen25-coder7b|glm4-9b|qwenplus|deepseekv3)

set -e

# Model configurations: tag -> repair_model_name
declare -A MODELS=(
    ["qwen25-coder7b"]="qwen2.5-coder-7b-instruct"
    ["glm4-9b"]="glm4-9b-chat"
    ["qwenplus"]="qwen-plus"
    ["deepseekv3"]="deepseek-v3"
)

REDUCER_MODEL="qwen-plus"
LOG_DIR="rq2_logs"
REGENERATE_FLAG=""
SINGLE_MODEL=""

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
        --model)
            SINGLE_MODEL="$2"
            shift 2
            ;;
        *)
            echo "Unknown option: $1" >&2
            echo "Usage: $0 [--regenerate] [--model <model_tag>]" >&2
            exit 1
            ;;
    esac
done

mkdir -p "$LOG_DIR"

# Prepare reducer results file (use ReduceFix full results)
if [ ! -f "reducer_results.json" ]; then
    ln -s `pwd`/result_reducer_reducefix.json reducer_results.json
fi

echo "=============================================="
echo "RQ2: Comprehensive Multi-LLM Evaluation"
echo "=============================================="
echo "Reducer model: $REDUCER_MODEL (fixed)"
echo "Problems: ${#problems[@]} total"

if [ -n "$SINGLE_MODEL" ]; then
    if [ -z "${MODELS[$SINGLE_MODEL]}" ]; then
        echo "✗ Error: Unknown model tag '$SINGLE_MODEL'" >&2
        echo "Available: ${!MODELS[@]}" >&2
        exit 1
    fi
    echo "Mode: Single model ($SINGLE_MODEL)"
    MODELS_TO_RUN=("$SINGLE_MODEL")
else
    echo "Mode: All 4 models"
    MODELS_TO_RUN=("${!MODELS[@]}")
fi

if [ -n "$REGENERATE_FLAG" ]; then
    echo "Regenerate: YES (force re-run)"
else
    echo "Regenerate: NO (reuse existing results)"
fi
echo "=============================================="
echo ""

# Check if all results already exist (support multiple naming patterns)
all_exist=true
declare -A RESULT_FILES

for tag in "${MODELS_TO_RUN[@]}"; do
    # Try multiple naming patterns (new convention first)
    result_file=""
    
    # New naming convention: result_repair_{model}.json
    if [ -f "result_repair_${tag}.json" ]; then
        result_file="result_repair_${tag}.json"
    # Fallback to old naming patterns
    elif [ -f "result_${tag}.json" ]; then
        result_file="result_${tag}.json"
    elif [ -f "result_qwenplus-${tag}.json" ]; then
        result_file="result_qwenplus-${tag}.json"
    elif [ "$tag" = "qwen25-coder7b" ] && [ -f "result_coder7b_qwen2.5-coder-7b-instruct.json" ]; then
        result_file="result_coder7b_qwen2.5-coder-7b-instruct.json"
    fi
    
    if [ -n "$result_file" ]; then
        RESULT_FILES[$tag]="$result_file"
    else
        all_exist=false
        break
    fi
done

if [ "$all_exist" = true ] && [ -z "$REGENERATE_FLAG" ]; then
    echo "✓ All result files already exist. Generating summary..."
    echo ""
    
    for tag in "${MODELS_TO_RUN[@]}"; do
        result_file="${RESULT_FILES[$tag]}"
        size=$(du -h "$result_file" | cut -f1)
        echo "  ✓ $result_file ($size)"
    done
    
    echo ""
    echo "=============================================="
    echo "Generating RQ2 Analysis"
    echo "=============================================="
    
    python3 analyze_rq2_table.py
    
    echo ""
    echo "=============================================="
    echo "DDMin-based ReduceFix Results (Qwen2.5-Coder)"
    echo "=============================================="
    
    if [ -f "result_ddmin_repair_qwen2.5-coder-7b.json" ]; then
        python3 analyze_ddmin_results.py
    else
        echo "  ⚠  DDMin results not found: result_ddmin_repair_qwen2.5-coder-7b.json"
        echo "     (Optional) DDMin-based reduction results can be added separately"
    fi
    
    echo ""
    echo "=============================================="
    echo "Analyzing Python Dataset (Qwen-Plus)"
    echo "=============================================="
    
    if [ -f "result_python_qwenplus.json" ]; then
        python3 analyze_python_results.py
    else
        echo "⚠  Python results not found: result_python_qwenplus.json"
        echo "   (Optional) Python dataset results can be added separately"
    fi
    
    exit 0
fi

# Run evaluations
batch_start_time=$(date +%s)

model_idx=0
for tag in "${MODELS_TO_RUN[@]}"; do
    model_idx=$((model_idx + 1))
    repair_model="${MODELS[$tag]}"
    
    echo ""
    echo "=============================================="
    echo "[Model $model_idx/${#MODELS_TO_RUN[@]}] $tag: $repair_model"
    echo "=============================================="
    
    model_start_time=$(date +%s)
    
    for idx in "${!problems[@]}"; do
        problem="${problems[$idx]}"
        progress=$((idx+1))
        total=${#problems[@]}
        log_file="$LOG_DIR/${problem}_${tag}.log"
        
        echo "  [$progress/$total] Evaluating: $problem"
        echo "--- $(date) ---" > "$log_file"
        
        # Run repair evaluation
        cmd="python3 evaluate_repair.py $problem --model-tag $tag --reducer-model $REDUCER_MODEL --repair-model $repair_model --max-threads 10 $REGENERATE_FLAG"
        echo "$cmd" | tee -a "$log_file"
        
        if eval "$cmd >> \"$log_file\" 2>&1"; then
            echo "    ✓ Success" | tee -a "$log_file"
        else
            echo "    ✗ Failed (check log: $log_file)" | tee -a "$log_file"
        fi
    done
    
    model_end_time=$(date +%s)
    model_cost=$((model_end_time - model_start_time))
    model_hours=$((model_cost / 3600))
    model_minutes=$(((model_cost % 3600) / 60))
    model_seconds=$((model_cost % 60))
    
    echo ""
    echo "  Model $tag completed in ${model_hours}h ${model_minutes}m ${model_seconds}s"
    
    # Rename and minimize result file if needed
    if [ -f "result_${tag}.json" ]; then
        echo "  Processing results..."
        # Backup to temp
        mkdir -p temp
        cp "result_${tag}.json" "temp/result_${tag}_full.json"
        # Rename to new convention
        python3 -c "
import json, sys
with open('result_${tag}.json', 'r') as f: data = json.load(f)
minimized = {}
for pid, pdata in data.items():
    minimized[pid] = {'problem_id': pid}
    if 'results' in pdata:
        minimized[pid]['results'] = []
        for r in pdata['results']:
            mr = {'submission_id': r.get('submission_id', '')}
            if 'evaluation' in r:
                mr['evaluation'] = {}
                for s in ['no_tc', 'orig_tc', 'reduced_tc']:
                    if s in r['evaluation'] and 'versions' in r['evaluation'][s]:
                        mr['evaluation'][s] = {'versions': [{'version': v.get('version'), 'passed': v.get('passed', False), 'status': v.get('status', '')} for v in r['evaluation'][s]['versions']]}
            minimized[pid]['results'].append(mr)
with open('result_repair_${tag}.json', 'w') as f: json.dump(minimized, f, indent=2)
"
        rm "result_${tag}.json"
        echo "  Results: result_repair_${tag}.json"
    else
        echo "  Results: (not found)"
    fi
    echo "=============================================="
done

batch_end_time=$(date +%s)
batch_cost=$((batch_end_time - batch_start_time))
batch_hours=$((batch_cost / 3600))
batch_minutes=$(((batch_cost % 3600) / 60))
batch_seconds=$((batch_cost % 60))

echo ""
echo "=============================================="
echo "RQ2 Evaluation Complete!"
echo "=============================================="
echo "Total time: ${batch_hours}h ${batch_minutes}m ${batch_seconds}s"
echo ""
echo "Result files generated:"
for tag in "${MODELS_TO_RUN[@]}"; do
    if [ -f "result_repair_${tag}.json" ]; then
        size=$(du -h "result_repair_${tag}.json" | cut -f1)
        echo "  ✓ result_repair_${tag}.json ($size)"
    elif [ -f "result_${tag}.json" ]; then
        size=$(du -h "result_${tag}.json" | cut -f1)
        echo "  ✓ result_${tag}.json ($size) [old naming]"
    else
        echo "  ✗ result_repair_${tag}.json (not found)"
    fi
done
echo ""
echo "=============================================="
echo "Generating RQ2 Analysis"
echo "=============================================="

python3 analyze_rq2_table.py

echo ""
echo "=============================================="
echo "DDMin-based ReduceFix Results (Qwen2.5-Coder)"
echo "=============================================="

if [ -f "result_ddmin_repair_qwen2.5-coder-7b.json" ]; then
    python3 analyze_ddmin_results.py
else
    echo "  ⚠  DDMin results not found: result_ddmin_repair_qwen2.5-coder-7b.json"
    echo "     (Optional) DDMin-based reduction results can be added separately"
fi

echo ""
echo "=============================================="
echo "Analyzing Python Dataset (Qwen-Plus)"
echo "=============================================="

if [ -f "result_python_qwenplus.json" ]; then
    python3 analyze_python_results.py
else
    echo "⚠  Python results not found: result_python_qwenplus.json"
    echo "   (Optional) Python dataset results can be added separately"
fi

echo ""
echo "=============================================="
echo "RQ2 Batch Analysis Complete"
echo "=============================================="
echo "Logs: $LOG_DIR/"
echo "=============================================="
