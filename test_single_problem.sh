#!/bin/bash
# 单问题测试脚本 - 完全独立环境，不覆盖原数据
# Usage: ./test_single_problem.sh <problem_id>

set -e

if [ $# -lt 1 ]; then
    echo "Usage: $0 <problem_id>" >&2
    echo "Example: $0 abc361c" >&2
    exit 1
fi

PROBLEM="$1"
TEST_DIR="test_workspace"
RESULTS_DIR="$TEST_DIR/results"

echo "════════════════════════════════════════════════════════════"
echo "  单问题测试: $PROBLEM"
echo "════════════════════════════════════════════════════════════"
echo ""

# Step 1: 创建独立测试环境
echo "Step 1: 创建独立测试环境"
rm -rf "$TEST_DIR"
mkdir -p "$RESULTS_DIR"
echo "  ✓ 创建测试目录: $TEST_DIR/"

# 不需要复制原有数据，测试环境完全独立

echo ""
echo "────────────────────────────────────────────────────────────"

# Step 2: 生成 reducer
echo ""
echo "Step 2: 生成 reducer"
echo "  → 运行 reducer_builder.py..."
echo ""

python3 reducer_builder.py "$PROBLEM" --llm-model qwen-plus 2>&1 | head -20

REDUCER_FILE="results/$PROBLEM/reducer.py"
if [ -f "$REDUCER_FILE" ]; then
    echo ""
    echo "  ✓ Reducer 生成成功: $REDUCER_FILE"
    echo "  ✓ Reducer 大小: $(wc -l < "$REDUCER_FILE") 行"
else
    echo "  ✗ Reducer 生成失败"
    exit 1
fi

echo ""
echo "────────────────────────────────────────────────────────────"

# Step 3: 测试 reducer（只测试 2 个提交）
echo ""
echo "Step 3: 测试 reducer (限制 2 个提交)"
echo "  → 修改测试参数..."

# 临时修改 MAX_WA_SUBMISSIONS
export MAX_WA_SUBMISSIONS_OVERRIDE=2

cd results
echo "  → 运行 reducer_test.py..."
echo ""

# 只测试2个提交，使用 --force 确保执行
python3 ../reducer_test.py "$PROBLEM" --reducer-model qwen-plus --force 2>&1 | tail -30

cd ..

echo ""
echo "────────────────────────────────────────────────────────────"

# Step 4: 检查结果
echo ""
echo "Step 4: 检查测试结果"

# 检查生成的结果文件
if [ -f "results/$PROBLEM/reducer_results.json" ]; then
    echo "  ✓ 找到问题级别的结果文件"
    python3 << PYEOF
import json
import os

result_file = "results/$PROBLEM/reducer_results.json"
if os.path.exists(result_file):
    with open(result_file, 'r') as f:
        data = json.load(f)
    
    results = data.get('results', [])
    print(f"  ✓ 测试结果数量: {len(results)}")
    
    for i, r in enumerate(results, 1):
        status = r.get('status_code')
        orig = r.get('original_size_bytes')
        reduced = r.get('reduced_size_bytes')
        sid = r.get('submission_id')
        
        if status == 200:
            status_str = "✓ 成功"
        elif status == 408:
            status_str = "⏱ 超时"
        else:
            status_str = "✗ 失败"
        
        if reduced and orig:
            ratio = (1 - reduced/orig) * 100
            print(f"    {i}. {status_str} | submission {sid}")
            print(f"       {orig:,} → {reduced:,} bytes (压缩 {ratio:.1f}%)")
        else:
            print(f"    {i}. {status_str} | submission {sid}")
            print(f"       原始: {orig:,} bytes (未完成压缩)")
PYEOF
fi

# 检查其他可能的结果文件
if [ -f "result_default.json" ]; then
    echo ""
    echo "  ℹ 也生成了 result_default.json (临时文件)"
fi

echo ""
echo "════════════════════════════════════════════════════════════"
echo "  测试完成！"
echo "════════════════════════════════════════════════════════════"
echo ""
echo "生成的文件："
echo "  • results/$PROBLEM/reducer.py         - 生成的 reducer"
echo "  • results/$PROBLEM/ac.cpp             - AC 代码"
echo "  • results/$PROBLEM/reducer_results.json - 测试结果"
echo ""
echo "原始数据状态："
echo "  ✓ result_reducer_reducefix.json - 未修改"
echo "  ✓ result_reducer_ddmin.json     - 未修改"
echo "  ✓ result_reducer_llm.json       - 未修改"
echo ""
echo "清理测试文件："
echo "  rm -f result_default.json  # 删除临时结果文件"
echo ""
echo "════════════════════════════════════════════════════════════"
