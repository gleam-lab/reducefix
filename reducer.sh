#!/bin/bash

# 用法: ./reducer.sh <result_tag> [--force]
#   <result_tag>   结果文件前缀，如 mytag -> result_mytag.json
#   --force        (可选) 强制重新测试 reducer_test.py 中已存在的记录
# 示例: ./reducer.sh qwenplus-run --force

set -e

# ====== 可根据需要修改的题目列表 ======
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
# ======================================

if [[ $# -lt 1 ]]; then
  echo "Usage: $0 <result_tag> [--force]" >&2
  exit 1
fi

RESULT_TAG="$1"
shift
EXTRA_TEST_ARGS="$@"   # 传递给 reducer_test.py 的其他参数, 如 --force

LLM_MODEL="qwen-plus"
LOG_DIR="reducer_logs"
mkdir -p "$LOG_DIR"

start_time=$(date +%s)

echo "开始批量生成并测试 reducer (模型: $LLM_MODEL)"
echo "结果标签: $RESULT_TAG"
echo "日志目录: $LOG_DIR"
echo "--------------------------------------------------"

for idx in "${!problems[@]}"; do
  problem="${problems[$idx]}"
  progress=$((idx+1))
  total=${#problems[@]}
  log_file="$LOG_DIR/${problem}.log"

  echo "[$progress/$total] 构建 reducer: $problem"
  echo "--- $(date) ---" > "$log_file"

  # 1. 生成 reducer.py
  echo "python3 reducer_builder.py $problem --llm-model $LLM_MODEL --model-tag $RESULT_TAG" | tee -a "$log_file"
  if python3 reducer_builder.py "$problem" --llm-model "$LLM_MODEL" --model-tag "$RESULT_TAG" >> "$log_file" 2>&1; then
    echo "✓ reducer_builder 成功" | tee -a "$log_file"
  else
    echo "✗ reducer_builder 失败, 跳过 reducer_test" | tee -a "$log_file"
    continue
  fi

  # 2. 测试 reducer.py
  echo "python3 reducer_test.py $problem --model-tag $RESULT_TAG --reducer-model $LLM_MODEL $EXTRA_TEST_ARGS" | tee -a "$log_file"
  if python3 reducer_test.py "$problem" --model-tag "$RESULT_TAG" --reducer-model "$LLM_MODEL" $EXTRA_TEST_ARGS >> "$log_file" 2>&1; then
    echo "✓ reducer_test 成功" | tee -a "$log_file"
  else
    echo "✗ reducer_test 失败" | tee -a "$log_file"
  fi

  echo "----------------------------------------------" | tee -a "$log_file"
done

end_time=$(date +%s)
cost=$((end_time - start_time))
echo "全部任务完成, 耗时 ${cost}s, 结果文件: result_${RESULT_TAG}.json" 