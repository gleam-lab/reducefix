#!/bin/bash

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

RESULT_TAG="$1"
REDUCER_MODEL="qwen-plus"
REPAIR_MODEL="$2"

# 日志文件
LOG_DIR="batch_logs"
mkdir -p "$LOG_DIR"

echo "开始批量处理 ${#problems[@]} 个问题..."
echo "结果标签: $RESULT_TAG"
echo "Reducer模型: $REDUCER_MODEL (不会重新生成)"
echo "Repair模型: $REPAIR_MODEL"
echo "日志目录: $LOG_DIR"
echo "工作目录: $(pwd)"
echo ""

# 记录开始时间
start_time=$(date +%s)

# 遍历所有问题
for i in "${!problems[@]}"; do
    problem=${problems[$i]}
    progress=$((i + 1))
    total=${#problems[@]}
    
    echo "[$progress/$total] 正在处理: $problem"
    
    # 执行repair评估命令并记录日志
    echo "开始时间: $(date)"
    echo "命令: python3 evaluate_repair_main.py $problem --model-tag $RESULT_TAG --reducer-model $REDUCER_MODEL --repair-model $REPAIR_MODEL"
    
    if python3 evaluate_repair_main.py "$problem" --model-tag "$RESULT_TAG" --reducer-model "$REDUCER_MODEL" --repair-model "$REPAIR_MODEL" --max-threads 10; then
        echo "✓ $problem 完成"
    else
        echo "✗ $problem 失败 (详情见 $log_file)"
    fi
    
    echo "结束时间: $(date)" >> "$log_file"
    echo ""
done

# 计算总耗时
end_time=$(date +%s)
total_time=$((end_time - start_time))
hours=$((total_time / 3600))
minutes=$(((total_time % 3600) / 60))
seconds=$((total_time % 60))

echo "批量处理完成!"
echo "总耗时: ${hours}时${minutes}分${seconds}秒"
echo "日志文件保存在: $LOG_DIR/"
echo "结果文件: result_$RESULT_TAG.json" 
