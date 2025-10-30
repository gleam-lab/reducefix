# OSS-Fuzz 实验数据包 - 审稿材料

本目录包含了 OSS-Fuzz 测试用例缩减与自动修复实验的完整数据，用于论文审稿和结果复现。

## 📁 目录结构

```
oss_fuzz_results/
├── 00_README_审稿说明.md          # 本文件：数据包说明
├── README.md                       # OSS-Fuzz 实验框架说明
├── README_OSS_FUZZ.md             # 主项目中的 OSS-Fuzz 相关文档
│
├── cases.json                      # 所有测试案例的元信息
├── project_groups.json             # 项目分组配置
├── config.py                       # 实验配置
│
├── cases_data/                     # 原始测试数据和中间结果 [核心数据]
│   ├── ffmpeg/                     # 各项目的案例目录
│   ├── imagemagick/
│   ├── mupdf/
│   ├── open62541/
│   ├── php-src/
│   └── poppler/
│       └── arvo-xxxxx/             # 单个案例目录
│           ├── original_test       # 原始测试输入
│           ├── compile_script.sh   # 编译脚本
│           ├── run_script.sh       # 运行脚本
│           └── reducefix_qwen/     # ReduceFix 方法的结果
│               ├── stats.json      # 统计数据（三种策略）
│               ├── ddmin/          # DDMin 缩减结果
│               ├── reducefix/      # ReduceFix 缩减结果
│               ├── generated/      # LLM 生成的缩减结果
│               └── repair_results/ # 修复实验结果
│                   ├── no_tc/      # 无测试用例修复
│                   ├── orig_tc/    # 原始测试用例修复
│                   └── reduced_tc/ # 缩减测试用例修复
│
├── experiment_results/             # 实验最终结果和统计 [核心结果]
│   ├── reduce_overview.json       # 缩减实验总览
│   ├── summary.json                # 总体统计
│   ├── experiment_overview.json    # 实验全局概览
│   ├── FINAL_REPORT.md            # 最终报告
│   ├── analysis.json               # 详细分析
│   └── [project]_reducefix_qwen_reduce_summary.json  # 各项目统计
│
├── artifacts/                      # 实验运行的中间产物
│   └── reducefix_qwen/             # 模型标签目录
│       ├── prompts/                # LLM 提示词
│       ├── responses/              # LLM 响应
│       └── logs/                   # 执行日志
│
├── compute_reduce_stats.py         # 计算缩减统计的脚本
├── compute_repair_stats.py         # 计算修复统计的脚本
├── compute_experiment_stats.py     # 计算实验总体统计
├── generate_latex_tables.py        # 生成 LaTeX 表格
│
├── ddmin.py                        # DDMin 算法实现
├── reducefix.py                    # ReduceFix 算法实现
├── guided_repair.py                # 引导式修复实现
├── utils.py                        # 工具函数
└── adapters.py                     # 语言适配器
```

## 📊 核心数据说明

### 1. 测试案例元信息 (`cases.json`)

包含所有 50 个测试案例的元信息：
```json
{
  "arvo-xxxxx": {
    "target": "项目名称（如 ffmpeg、php-src）",
    "fuzzer": "模糊测试器名称",
    "size": 原始大小（字节）,
    "type": "crash 或 timeout",
    "url": "OSS-Fuzz issue URL"
  }
}
```

### 2. 案例数据目录 (`cases_data/`)

**关键内容**：
- `original_test`：原始的崩溃触发测试输入
- `stats.json`：记录三种缩减策略的效果
  - `ddmin`：Delta Debugging（基线方法）
  - `reducefix`：我们提出的 ReduceFix 方法
  - `generated`：纯 LLM 生成的缩减版本

**stats.json 格式示例**：
```json
{
  "original_size": 12345,
  "ddmin_size": 8000,
  "ddmin_compression_ratio": 0.35,
  "reducefix_size": 3000,
  "reducefix_compression_ratio": 0.76,
  "generated_size": 5000,
  "generated_compression_ratio": 0.59
}
```

### 3. 修复实验结果 (`cases_data/.../repair_results/`)

每个案例下有三种修复策略的结果：
- **no_tc/** (without_test)：无测试用例的修复（基线）
- **orig_tc/** (origin_test)：使用原始测试用例的修复
- **reduced_tc/** (reduced_test)：使用 ReduceFix 缩减后测试用例的修复

每个策略目录下的 `results.json` 包含：
```json
{
  "without_test": {
    "passed": false,
    "versions": [
      {"version": 1, "passed": false, "error": "..."},
      ...
    ]
  },
  "origin_test": { ... },
  "reduced_test": { ... }
}
```

评估标准：**K-Version 方法（K=10）**
- 每个策略生成 10 个修复版本
- 只要有 1 个版本通过所有测试，即视为成功

### 4. 实验结果汇总 (`experiment_results/`)

- **reduce_overview.json**：所有案例的缩减效果统计
- **summary.json**：修复实验的成功率统计
- **各项目统计文件**：按项目分组的详细统计

## 🔧 如何使用这些数据

### 统计缩减效果

```bash
# 计算所有项目的缩减统计（显示详细信息）
python compute_reduce_stats.py

# 不显示详细信息
python compute_reduce_stats.py --no-details

# 指定其他模型标签
python compute_reduce_stats.py --model-tag reducefix_qwen
```

输出示例：
```
======================================================================
OSS-Fuzz Reduce 效果统计（按 Project）
======================================================================

[ffmpeg]
  样本总数: 10
  三法均完成样本: 10
  ddmin       : 成功率 90.0% | 平均压缩率 45.3%
  reducefix   : 成功率 100.0% | 平均压缩率 78.2%
  llm-generated: 成功率 80.0% | 平均压缩率 62.1%
  
  样本详情:
    arvo-12345 (原始: 50.2KB)
      ddmin:     25.1KB (50.0%) ✓
      reducefix: 5.3KB (89.4%) ✓
      generated: 12.7KB (74.7%) ✓
    ...
```

### 统计修复效果

```bash
# 计算修复成功率
python compute_repair_stats.py

# 显示各项目详细结果
python compute_repair_stats.py --detailed

# 保存为 JSON
python compute_repair_stats.py --output repair_stats.json
```

输出示例：
```
======================================================================
修复实验结果统计 (TOP_K=10, K-Version 方法)
======================================================================

总案例数: 50
评估标准: 每个策略生成10个版本，至少1个版本通过即为成功

┌────────────────────────────────────────────────────────────────────┐
│                      三种修复策略成功率对比                        │
├─────────────────────────┬──────────────┬──────────────┬────────────┤
│ 策略                    │ 成功案例     │ 总案例       │ 成功率     │
├─────────────────────────┼──────────────┼──────────────┼────────────┤
│ 无测试用例 (Baseline)   │           15 │           50 │      30.0% │
│ 原始测试用例            │           28 │           50 │      56.0% │
│ 缩减测试用例 (ReduceFix)│           35 │           50 │      70.0% ★│
└─────────────────────────┴──────────────┴──────────────┴────────────┘

改进幅度分析:
  原始测试用例 vs 无测试用例: +26.0 百分点
  缩减测试用例 vs 无测试用例: +40.0 百分点
  缩减测试用例 vs 原始测试用例: +14.0 百分点
```

### 生成 LaTeX 表格（用于论文）

```bash
# 生成论文用表格
python generate_latex_tables.py
```

### 查看单个案例的详细信息

```bash
# 查看特定案例的所有信息
python show_case_info.py arvo-12345
```

## 📈 核心实验数据

### 数据集规模
- **总案例数**：50 个真实 OSS-Fuzz 崩溃案例
- **覆盖项目**：6 个流行开源项目
  - FFmpeg（10 个案例）
  - PHP（10 个案例）
  - MuPDF（10 个案例）
  - Poppler（10 个案例）
  - Open62541（5 个案例）
  - ImageMagick（5 个案例）

### 缩减实验设置
- **三种策略对比**：
  1. DDMin（基线方法）
  2. ReduceFix（我们的方法）
  3. LLM-Generated（纯 LLM 生成）
  
- **评估指标**：
  - 成功率：是否成功缩减
  - 压缩率：(original_size - reduced_size) / original_size

### 修复实验设置
- **三种测试用例策略对比**：
  1. 无测试用例（基线）
  2. 原始测试用例
  3. ReduceFix 缩减后的测试用例

- **评估方法**：K-Version (K=10)
  - 每个策略生成 10 个修复补丁
  - 至少 1 个通过所有测试即为成功

- **修复模型**：使用当前最先进的代码修复大模型

## 🔍 数据验证

### 验证缩减结果的正确性
每个缩减后的测试用例都经过了：
1. **编译验证**：确保能够编译通过
2. **行为验证**：确保仍能触发相同的崩溃
3. **大小验证**：确保确实缩小了体积

### 验证修复结果的正确性
每个修复补丁都经过了：
1. **编译测试**：确保修复后的代码能编译
2. **原始测试**：使用原始的崩溃测试验证
3. **回归测试**：运行项目自带的测试套件

## 📝 引用和使用

本数据集是论文 "ReduceFix: 基于测试用例缩减的自动程序修复" 的实验数据。

**使用本数据集时请引用**：
```bibtex
@article{reducefix2025,
  title={ReduceFix: 基于测试用例缩减的自动程序修复},
  author={...},
  journal={...},
  year={2025}
}
```

## 🛠 环境要求

查看和统计数据只需要：
- Python 3.8+
- 标准库（json, pathlib, argparse 等）

完整复现实验需要：
- Docker（用于 OSS-Fuzz 环境）
- 大语言模型 API 访问

详见 `README.md` 和 `README_OSS_FUZZ.md`。

## 📧 联系方式

如有任何问题或需要澄清，请联系论文作者。

---

**数据生成时间**：2025年10月
**实验完成时间**：2025年10月
**数据包版本**：v1.0

