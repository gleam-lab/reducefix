# 快速开始指南

本指南帮助审稿人快速查看和验证实验数据。

## 🚀 10 分钟快速查看

### 1. 查看数据概览（1分钟）

```bash
# 查看数据清单
cat DATA_MANIFEST.txt

# 查看案例列表
cat cases.json | python3 -m json.tool | head -50
```

### 2. 查看缩减实验结果（3分钟）

```bash
# 查看已生成的统计报告
cat reduce_statistics_report.txt

# 或重新生成统计（显示所有详细信息）
python3 compute_reduce_stats.py
```

**关键结果**：
- **成功率**：ReduceFix vs DDMin vs LLM-Generated
- **平均压缩率**：每个策略的平均缩减效果
- **每个案例的详细数据**：原始大小、缩减后大小、压缩率

### 3. 查看修复实验结果（3分钟）

```bash
# 查看已生成的统计报告
cat repair_statistics_report.txt

# 或重新生成统计（显示详细信息）
python3 compute_repair_stats.py --detailed
```

**关键结果**：
- **三种策略成功率对比**：
  - 无测试用例（基线）
  - 原始测试用例
  - ReduceFix 缩减后的测试用例
- **改进幅度**：ReduceFix 相比基线的提升

### 4. 查看单个案例的完整数据（3分钟）

```bash
# 选择一个案例（例如 arvo-55076）
CASE_ID="arvo-55076"

# 查看案例元信息
cat cases.json | python3 -c "import sys, json; data=json.load(sys.stdin); print(json.dumps(data.get('$CASE_ID'), indent=2))"

# 查看案例目录结构
find cases_data -name "$CASE_ID" -type d -exec ls -lah {} \;

# 查看缩减统计
find cases_data -name "$CASE_ID" -type d -exec cat {}/reducefix_qwen/stats.json \;

# 查看修复结果
find cases_data -name "$CASE_ID" -type d -exec ls -R {}/reducefix_qwen/repair_results/ \;
```

## 📊 深入分析

### 查看实验结果汇总

```bash
# 查看总体实验概览
cat experiment_results/experiment_overview.json | python3 -m json.tool | less

# 查看缩减效果汇总
cat experiment_results/reduce_overview.json | python3 -m json.tool | less

# 查看按项目分类的统计
ls experiment_results/*_reduce_summary.json
```

### 查看各项目的详细数据

```bash
# 以 MuPDF 为例
cd cases_data/mupdf

# 列出所有 MuPDF 的案例
ls -d arvo-*

# 查看某个案例的完整目录结构
tree arvo-55076/  # 或使用 ls -R

# 查看原始测试输入
file arvo-55076/original_test

# 查看缩减后的测试
file arvo-55076/reducefix_qwen/reducefix/reduced_test

# 对比大小
du -h arvo-55076/original_test arvo-55076/reducefix_qwen/*/reduced_test
```

### 验证修复结果

```bash
# 查看某个案例的修复结果
CASE_DIR="cases_data/mupdf/arvo-55076/reducefix_qwen/repair_results"

# 查看三种策略的修复结果
cat $CASE_DIR/no_tc/results.json | python3 -m json.tool | head -50
cat $CASE_DIR/orig_tc/results.json | python3 -m json.tool | head -50
cat $CASE_DIR/reduced_tc/results.json | python3 -m json.tool | head -50
```

## 🔍 验证数据正确性

### 1. 验证案例完整性

```bash
# 检查所有案例是否都有必要的文件
for case_dir in cases_data/*/*/; do
    case_id=$(basename $case_dir)
    if [ ! -f "$case_dir/original_test" ]; then
        echo "缺少原始测试: $case_id"
    fi
    if [ ! -f "$case_dir/reducefix_qwen/stats.json" ]; then
        echo "缺少统计文件: $case_id"
    fi
done
```

### 2. 验证缩减效果

```bash
# 验证 ReduceFix 确实缩减了文件大小
python3 << 'EOF'
import json
from pathlib import Path

cases_data = Path("cases_data")
for stats_file in cases_data.rglob("*/reducefix_qwen/stats.json"):
    with open(stats_file) as f:
        data = json.load(f)
    
    orig = data.get("original_size", 0)
    reduced = data.get("reducefix_size", orig)
    
    if reduced < orig:
        ratio = (orig - reduced) / orig * 100
        print(f"✓ {stats_file.parts[-3]}: {orig}B → {reduced}B ({ratio:.1f}% 压缩)")
    elif reduced == orig:
        print(f"- {stats_file.parts[-3]}: 未缩减")
    else:
        print(f"✗ {stats_file.parts[-3]}: 大小增加！")
EOF
```

### 3. 验证修复成功率

```bash
# 统计每种策略的成功案例数
python3 << 'EOF'
import json
from pathlib import Path
from collections import defaultdict

results = defaultdict(lambda: {"success": 0, "total": 0})

for results_file in Path("cases_data").rglob("*/repair_results/*/results.json"):
    strategy = results_file.parts[-2]  # no_tc, orig_tc, reduced_tc
    
    with open(results_file) as f:
        data = json.load(f)
    
    # 检查对应策略是否成功
    strategy_map = {
        "no_tc": "without_test",
        "orig_tc": "origin_test",
        "reduced_tc": "reduced_test"
    }
    
    strategy_key = strategy_map.get(strategy, strategy)
    if strategy_key in data and data[strategy_key].get("passed", False):
        results[strategy]["success"] += 1
    results[strategy]["total"] += 1

print("\n修复成功率验证:")
for strategy, stats in sorted(results.items()):
    rate = stats["success"] / stats["total"] * 100 if stats["total"] > 0 else 0
    print(f"  {strategy:12s}: {stats['success']}/{stats['total']} = {rate:.1f}%")
EOF
```

## 📈 生成论文用表格

```bash
# 如果有 LaTeX 表格生成脚本
python3 generate_latex_tables.py
```

## 💡 常见问题

### Q: 如何查看 LLM 生成的提示词？

```bash
# 查看某个案例的提示词
ls artifacts/reducefix_qwen/prompts/

# 查看具体的提示内容
cat artifacts/reducefix_qwen/prompts/arvo-55076_reduce_prompt.txt
```

### Q: 如何查看 LLM 的响应？

```bash
# 查看 LLM 响应
cat artifacts/reducefix_qwen/responses/arvo-55076_reduce_response.json | python3 -m json.tool
```

### Q: 数据集中有多少个案例？

```bash
# 统计案例数
find cases_data -name "arvo-*" -type d | wc -l

# 按项目统计
for proj in cases_data/*/; do
    count=$(find $proj -maxdepth 1 -name "arvo-*" -type d | wc -l)
    echo "$(basename $proj): $count"
done
```

### Q: 如何验证实验的可重复性？

所有的中间结果和配置都已包含在数据包中：
- 原始测试输入 → `cases_data/*/arvo-*/original_test`
- 编译和运行脚本 → `cases_data/*/arvo-*/*.sh`
- 缩减后的测试 → `cases_data/*/arvo-*/reducefix_qwen/*/reduced_test`
- 修复补丁 → `cases_data/*/arvo-*/reducefix_qwen/repair_results/*/patch_*.diff`
- 统计数据 → `experiment_results/*.json`

要重新运行实验，需要：
1. Docker 环境（用于 OSS-Fuzz 项目编译）
2. LLM API 访问（用于生成缩减版本和修复补丁）

详见 `README.md` 中的环境配置说明。

## 📧 联系

如有任何疑问，请联系论文作者。


