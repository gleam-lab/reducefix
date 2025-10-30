# OSS-Fuzz ReduceFix 项目结构

**重组日期**: 2025-10-24  
**项目目标**: 验证 ReduceFix 对 APR 的帮助效果

---

## 📁 目录结构

```
oss_fuzz/
├── validate/           # 数据验证模块
│   ├── README.md
│   └── validate_dataset.sh
│
├── prepare/            # 数据准备模块
│   ├── README.md
│   ├── select_cases.py
│   ├── download_data.py
│   ├── cleanup_data.py
│   └── prepare_all.sh
│
├── experiment/         # 实验执行模块
│   ├── README.md
│   ├── config.sh
│   └── run_ossfuzz.sh     # 主实验脚本
│
├── cases_data/         # 数据目录
│   ├── ffmpeg/
│   ├── harfbuzz/
│   ├── imagemagick/
│   ├── libxml2/
│   ├── mupdf/
│   └── poppler/
│
├── cases.json          # 案例配置
├── selected_large_cases.json  # 筛选结果
│
├── ARVO-Meta/          # Ground truth 数据源
│
└── [旧脚本...]         # 保留的原有脚本（待整理）
```

---

## 🔄 完整工作流程

### 1. 数据准备阶段 (Prepare)

```bash
cd oss_fuzz

# 一键准备（推荐）
bash prepare/prepare_all.sh

# 或分步执行
python3 prepare/select_cases.py       # 筛选 cases
python3 prepare/download_data.py      # 下载数据
python3 prepare/cleanup_data.py       # 清理整理
```

**输出**: 
- ✅ 30 个精选 cases
- ✅ 测试用例、元数据、patch 完整
- ✅ `cases.json` 更新

---

### 2. 数据验证阶段 (Validate)

```bash
# 验证数据完整性
bash validate/validate_dataset.sh
```

**验证项**:
- ✅ 文件完整性
- ✅ Patch 单函数（1 hunk）
- ✅ 测试用例大小（>4KB）
- ✅ 无多余数据
- ✅ 统计汇总

**输出示例**:
```
总计 cases: 30
  ✓ Passed:  30
  ✗ Failed:  0

项目统计:
ffmpeg       5    8.5KB    143.2KB    716.1KB
harfbuzz     5    8.6KB    155.2KB    776.0KB
...
总计         30   6.3KB    229.2KB    6.72MB
```

---

### 3. 实验执行阶段 (Experiment)

```bash
cd oss_fuzz/experiment

# 运行 ReduceFix 实验
bash run_ossfuzz.sh

# 查看进度
tail -f ../artifacts/reduce_*.log

# 查看结果
cat reduce_summary.txt
```

**功能**:
- **ReduceFix 缩减**: 测试用例从 229KB → ~50KB（平均）
- **自动检测**: 验证缩减后的测试用例仍能触发崩溃
- **统计报告**: 缩减率、时间等统计信息

**预期效果**:
- 平均缩减率: 60-90%
- 保持崩溃触发: 100%
- 为后续 APR 提供更小的测试用例

---

## 📊 数据集统计

| 项目 | Cases | Patch 大小 | TestInput 大小 |
|------|-------|-----------|---------------|
| ffmpeg | 5 | 8.5KB | 143.2KB |
| harfbuzz | 5 | 8.6KB | 155.2KB |
| imagemagick | 5 | 8.4KB | 575.9KB |
| libxml2 | 5 | 2.5KB | 150.3KB |
| mupdf | 5 | 3.5KB | 297.3KB |
| poppler | 5 | 6.1KB | 53.4KB |
| **总计** | **30** | **6.3KB (平均)** | **229.2KB (平均)** |

**特点**:
- ✅ 所有 patch 都是单函数修改（1 hunk）
- ✅ 测试用例足够大（平均 229KB）
- ✅ 真实漏洞（OSS-Fuzz 发现）
- ✅ 多样化崩溃类型

---

## 🎯 实验设计

### 策略对比

| 策略 | 说明 | 测试用例 | 预期成功率 |
|------|------|---------|-----------|
| **without_test** | 纯 baseline | ✗ 无 | 20-30% |
| **origin_test** | 原始测试用例 | ✓ 大 (229KB) | 30-40% |
| **reduced_test** | ReduceFix | ✓ 小 (~50KB) | **40-60%** |

### 评估指标

- **Pass@K**: 10个版本中至少1个通过 → 成功
- **成功率**: 成功 cases / 总 cases
- **缩减率**: (原始 - 缩减) / 原始

---

## 📂 各模块详情

### validate/ - 数据验证

**作用**: 确保数据质量和完整性

**主脚本**: `validate_dataset.sh`

**验证内容**:
- 文件完整性（testcase, metadata, patch）
- Patch 格式（单函数、hunk 数量）
- 测试用例大小
- 无多余数据
- 统计汇总

**何时运行**:
- ✅ 准备数据后
- ✅ 开始实验前
- ✅ 数据迁移后

**详情**: [validate/README.md](validate/README.md)

---

### prepare/ - 数据准备

**作用**: 筛选和下载符合条件的 cases

**主脚本**: `prepare_all.sh`

**流程**:
1. 筛选 cases (select_cases.py)
2. 下载数据 (download_data.py)
3. 清理整理 (cleanup_data.py)
4. 验证数据 (调用 validate/)

**输出**:
- `selected_large_cases.json`
- `cases.json` (更新)
- `cases_data/` (30 cases)

**详情**: [prepare/README.md](prepare/README.md)

---

### experiment/ - 实验执行

**作用**: 运行 ReduceFix 测试用例缩减实验

**主脚本**: `run_ossfuzz.sh`

**功能**:
- ReduceFix 测试用例缩减
- 自动崩溃检测
- 生成统计报告

**配置**: `config.sh`

**输出位置**:
- `../cases_data/*/arvo-*/reduced_testcase` - 缩减后的测试用例
- `../artifacts/` - 实验结果汇总
- `reduce_summary.txt` - 统计报告

**详情**: [experiment/README.md](experiment/README.md)

---

## 🚀 快速开始

### 首次使用

```bash
# Step 1: 准备数据
bash prepare/prepare_all.sh

# Step 2: 验证数据
bash validate/validate_dataset.sh

# Step 3: 运行实验
cd experiment && bash run_ossfuzz.sh
```

### 已有数据

```bash
# 验证数据
bash validate/validate_dataset.sh

# 运行实验
cd experiment && bash run_ossfuzz.sh
```

---

## 📝 旧脚本映射

| 旧脚本 | 新位置 | 状态 |
|--------|--------|------|
| `validate_dataset.sh` | `validate/validate_dataset.sh` | ✅ 已移动 |
| `select_large_single_function_cases.py` | `prepare/select_cases.py` | ✅ 已移动并重命名 |
| `download_selected_large_cases.py` | `prepare/download_data.py` | ✅ 已移动并重命名 |
| `cleanup_and_update_for_new_cases.py` | `prepare/cleanup_data.py` | ✅ 已移动并重命名 |
| `run_ossfuzz.sh` | `experiment/run_ossfuzz.sh` | ✅ 已移动 |
| 其他脚本 | 保留在根目录 | 📝 保留（工具脚本） |

**注意**: 根目录的重复文件已清理，所有功能脚本都在子目录中。

---

## 🔧 依赖环境

- Python 3.8+
- Docker
- gsutil（下载 OSS-Fuzz testcases）
- jq（JSON 处理）
- 磁盘空间: 至少 10GB

---

## 🎯 可用项目

**6 个项目，每个 5 个 cases，共 30 个：**
- `ffmpeg`
- `harfbuzz`
- `imagemagick`
- `libxml2`
- `mupdf`
- `poppler`

## 🚀 快速开始

```bash
# 1. 验证数据
bash validate/validate_dataset.sh

# 2. 运行实验（推荐先测试小项目）
cd experiment
bash run_ossfuzz.sh --project mupdf

# 3. 运行所有项目
bash run_ossfuzz.sh --all
```

## 🧹 最终清理状态

**已删除的旧脚本（11 个）**:
- 旧的下载脚本: `download_selected_projects.py`, `download_top10_large_projects.py`, `download_all_testcases.py`
- 旧的准备脚本: `sync_cases_from_arvo_meta.py`, `prune_and_annotate_cases.py`
- 临时脚本: `cleanup_root_duplicates.sh`
- 已移动的脚本: 5 个（移至 validate/, prepare/, experiment/）

**保留在根目录（18 个核心工具模块）**:
- 实验核心: `run_complete_reducefix.py`, `compute_reduce_stats.py`, `reorganize_artifacts.py`
- 工具模块: `apr_repair.py`, `utils.py`, `crash_detector.py`, 等
- Docker 相关: `pull_docker_images.py`, `check_docker_fuzzers.sh`

详见 `FINAL_CLEANUP.md`

---

## 📖 相关文档

- **核心文档**:
  - [INDEX.md](INDEX.md) - 主文档索引
  - [FINAL_CLEANUP.md](FINAL_CLEANUP.md) - 最终清理报告
  - [PROJECT_STRUCTURE.md](PROJECT_STRUCTURE.md) - 项目结构

- **模块文档**:
  - [数据准备 README](prepare/README.md)
  - [数据验证 README](validate/README.md)
  - [实验执行 README](experiment/README.md)

- **历史记录**:
  - [重组总结](REORGANIZATION_SUMMARY.md)
  - [清理总结](CLEANUP_SUMMARY.md)

---

**最后更新**: 2025-10-24  
**版本**: 清理完成 v3  
**状态**: ✅ 所有准备工作完成，可以开始实验

