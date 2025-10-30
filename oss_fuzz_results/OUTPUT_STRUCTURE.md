# ReduceFix 输出目录结构说明

## 重跑脚本输出结构

当使用 `rerun_all_strategies.py` 重跑实验时，会生成以下目录结构：

```
oss_fuzz/artifacts/{target}/{case_id}/{model_tag}/
├── no_tc_evaluation.json          # 无测试用例策略的评估结果（供统计脚本使用）
├── orig_tc_evaluation.json        # 原始测试用例策略的评估结果（供统计脚本使用）
├── reduced_tc_evaluation.json     # 缩减测试用例策略的评估结果（供统计脚本使用）
├── no_tc/                          # 无测试用例策略详细数据
│   ├── no_tc_v1_prompt.txt        # 版本1的输入 prompt
│   ├── no_tc_v1_response.txt      # 版本1的 LLM 原始输出
│   ├── no_tc_v2_prompt.txt        # 版本2的输入 prompt
│   ├── no_tc_v2_response.txt      # 版本2的 LLM 原始输出
│   ├── ... (共10个版本)
│   ├── evaluation.json            # 评估结果（与上级目录相同）
│   ├── detailed_results.json      # 详细结果（包含所有版本的 patch 内容）
│   └── patches/                   # 所有版本的 patch 文件
│       ├── v1.patch
│       ├── v2.patch
│       └── ... (共10个版本)
├── orig_tc/                        # 原始测试用例策略详细数据
│   ├── orig_tc_v1_prompt.txt
│   ├── orig_tc_v1_response.txt
│   ├── orig_tc_v2_prompt.txt
│   ├── orig_tc_v2_response.txt
│   ├── ... (共10个版本)
│   ├── evaluation.json
│   ├── detailed_results.json
│   └── patches/
│       ├── v1.patch
│       ├── v2.patch
│       └── ... (共10个版本)
└── reduced_tc/                     # 缩减测试用例策略详细数据
    ├── reduced_tc_v1_prompt.txt
    ├── reduced_tc_v1_response.txt
    ├── reduced_tc_v2_prompt.txt
    ├── reduced_tc_v2_response.txt
    ├── ... (共10个版本)
    ├── evaluation.json
    ├── detailed_results.json
    └── patches/
        ├── v1.patch
        ├── v2.patch
        └── ... (共10个版本)
```

## 文件说明

### 1. `{strategy}_evaluation.json`（上级目录）
- **用途**: 供 `compute_experiment_stats.py` 统计脚本使用
- **内容**: 评估结果摘要
- **格式**:
```json
{
  "passed": true,
  "status": "Success",
  "successful_version": 1,
  "versions": [
    {
      "version": 1,
      "passed": true,
      "status": "Success",
      "compiled": true,
      "fixed_crash": true,
      "duration": 5.2
    },
    ...
  ]
}
```

### 2. `{strategy}_v{N}_prompt.txt`
- **用途**: 记录发送给 LLM 的完整 prompt
- **内容**: 
  - Crash 信息
  - 源代码
  - 测试用例（根据策略不同）
  - 修复指令
- **格式**: 纯文本

### 3. `{strategy}_v{N}_response.txt`
- **用途**: 记录 LLM 的原始输出（未经处理）
- **内容**: LLM 生成的完整响应（包含分析和 patch）
- **格式**: 纯文本

### 4. `patches/v{N}.patch`
- **用途**: 从 LLM 输出中提取的标准化 patch
- **内容**: 统一的 unified diff 格式
- **格式**: 标准 git diff 格式

### 5. `detailed_results.json`
- **用途**: 完整的实验结果，包含所有版本的 patch 内容
- **内容**: 评估结果 + 所有 patch 文本
- **格式**:
```json
{
  "strategy": "no_tc",
  "strategy_name": "无测试用例",
  "evaluation": { ... },
  "patches": [
    {
      "version": 1,
      "patch": "--- a/file.c\n+++ b/file.c\n...",
      "passed": true,
      "compiled": true,
      "status": "Success"
    },
    ...
  ]
}
```

## 使用方式

### 重跑所有策略
```bash
# 重跑所有样本的所有策略
python3 oss_fuzz/rerun_all_strategies.py

# 重跑特定样本
python3 oss_fuzz/rerun_all_strategies.py --case-ids arvo-22430 arvo-55076

# 重跑特定项目
python3 oss_fuzz/rerun_all_strategies.py --target poppler
```

### 查看统计结果
```bash
# 重跑后，使用统计脚本查看结果
python3 oss_fuzz/compute_experiment_stats.py --model-tag reducefix_qwen
```

## 数据完整性

每次重跑会保存以下数据：
1. ✅ **输入 Prompt** (10个版本 × 3个策略 = 30个文件/样本)
2. ✅ **LLM 原始输出** (10个版本 × 3个策略 = 30个文件/样本)
3. ✅ **标准化 Patch** (10个版本 × 3个策略 = 30个文件/样本)
4. ✅ **评估结果** (包含编译状态、修复状态、耗时等)
5. ✅ **统计数据** (pass@1, pass@5, pass@10)

总计每个样本约 **90 个数据文件**，确保实验结果完全可追溯和可复现。




