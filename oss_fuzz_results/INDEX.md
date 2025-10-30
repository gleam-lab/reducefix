# OSS-Fuzz ReduceFix 项目 - 文档索引

**项目**: ReduceFix 实验框架  
**数据集**: 30 个精选 OSS-Fuzz cases  
**更新日期**: 2025-10-24

---

## 📚 快速导航

### 🚀 快速开始

**首次使用（完整流程）**:
```bash
bash prepare/prepare_all.sh       # 准备数据
bash validate/validate_dataset.sh # 验证数据
cd experiment && bash run_ossfuzz.sh  # 运行实验
```

**已有数据**:
```bash
bash validate/validate_dataset.sh # 验证
cd experiment && bash run_ossfuzz.sh  # 实验
```

---

## 📖 主要文档

| 文档 | 说明 | 优先级 |
|------|------|--------|
| [PROJECT_STRUCTURE.md](PROJECT_STRUCTURE.md) | 📁 项目整体结构 | ⭐⭐⭐ |
| [REORGANIZATION_SUMMARY.md](REORGANIZATION_SUMMARY.md) | 🔄 重组总结 | ⭐⭐⭐ |
| [NEW_DATASET_README.md](NEW_DATASET_README.md) | 📊 数据集详情 | ⭐⭐ |
| [VALIDATION_SUMMARY.md](VALIDATION_SUMMARY.md) | ✅ 验证报告 | ⭐⭐ |

---

## 📂 模块文档

### 1. validate/ - 数据验证

| 文档 | 说明 |
|------|------|
| [validate/README.md](validate/README.md) | 验证模块使用说明 |

**快速使用**:
```bash
bash validate/validate_dataset.sh
```

**功能**:
- ✅ 验证文件完整性
- ✅ 检查 patch 格式（单函数）
- ✅ 验证测试用例大小
- ✅ 统计汇总

---

### 2. prepare/ - 数据准备

| 文档 | 说明 |
|------|------|
| [prepare/README.md](prepare/README.md) | 准备模块使用说明 |

**快速使用**:
```bash
bash prepare/prepare_all.sh  # 一键准备
```

**或分步执行**:
```bash
python3 prepare/select_cases.py   # 筛选
python3 prepare/download_data.py  # 下载
python3 prepare/cleanup_data.py   # 清理
```

---

### 3. experiment/ - 实验执行

| 文档 | 说明 |
|------|------|
| [experiment/README.md](experiment/README.md) | 实验模块使用说明 |
| [experiment/config.sh](experiment/config.sh) | 实验配置文件 |

**快速使用**:
```bash
cd experiment
bash run_ossfuzz.sh  # 运行 ReduceFix 实验
```

**查看结果**:
```bash
cat reduce_summary.txt              # 汇总报告
tail -f ../artifacts/reduce_*.log   # 查看进度
```

---

## 📊 数据集概览

| 项目 | Cases | 平均 Patch | 平均 TestInput |
|------|-------|-----------|---------------|
| ffmpeg | 5 | 8.5KB | 143.2KB |
| harfbuzz | 5 | 8.6KB | 155.2KB |
| imagemagick | 5 | 8.4KB | 575.9KB |
| libxml2 | 5 | 2.5KB | 150.3KB |
| mupdf | 5 | 3.5KB | 297.3KB |
| poppler | 5 | 6.1KB | 53.4KB |
| **总计** | **30** | **6.3KB** | **229.2KB** |

**特点**:
- ✅ 所有 patch 单函数修改（1 hunk）
- ✅ 测试用例大（平均 229KB）
- ✅ 真实漏洞（OSS-Fuzz）

详情: [NEW_DATASET_README.md](NEW_DATASET_README.md)

---

## 🎯 实验设计

### 三步流程

```
Step 1: ReduceFix 缩减 (run_reduce.sh)
   ↓
Step 2: APR 修复 (run_repair.sh)
   ↓
Step 3: 结果分析 (analyze_results.py)
```

### 策略对比

| 策略 | 测试用例 | 预期成功率 |
|------|---------|-----------|
| without_test | ✗ 无 | 20-30% |
| origin_test | ✓ 大 (229KB) | 30-40% |
| reduced_test | ✓ 小 (~50KB) | **40-60%** |

详情: [experiment/README.md](experiment/README.md)

---

## 🔍 常见任务

### 验证数据

```bash
# 完整验证
bash validate/validate_dataset.sh

# 查看报告
cat VALIDATION_SUMMARY.md
```

### 准备新数据

```bash
# 一键准备
bash prepare/prepare_all.sh

# 查看结果
cat selected_large_cases.json | jq
```

### 运行实验

```bash
# 进入实验目录
cd experiment

# 运行 ReduceFix
bash run_ossfuzz.sh

# 查看进度
tail -f ../artifacts/reduce_*.log
```

### 分析结果

```bash
# 查看汇总报告
cat reduce_summary.txt

# 统计缩减率
python3 ../compute_reduce_stats.py

# 查看单个 case 结果
cat ../cases_data/<project>/arvo-<id>/reduce_stats.json
```

---

## 📁 目录结构

```
oss_fuzz/
├── validate/           # 数据验证
│   ├── README.md
│   └── validate_dataset.sh
│
├── prepare/            # 数据准备
│   ├── README.md
│   ├── select_cases.py
│   ├── download_data.py
│   ├── cleanup_data.py
│   └── prepare_all.sh
│
├── experiment/         # 实验执行
│   ├── README.md
│   ├── config.sh
│   └── run_ossfuzz.sh     # 主实验脚本
│
├── cases_data/         # 数据目录
├── cases.json
├── selected_large_cases.json
└── [文档...]
```

---

## 🛠️ 故障排查

### 验证失败

```bash
# 查看详细错误
bash validate/validate_dataset.sh 2>&1 | grep ERROR

# 重新准备数据
bash prepare/prepare_all.sh
```

### 实验中断

```bash
# 查看日志
tail -n 100 experiment/logs/experiment_*.log

# 重新运行（支持断点续传）
bash experiment/run_experiment.sh
```

### 结果异常

```bash
# 验证结果文件
ls -lh experiment/results/

# 重新分析
python3 experiment/analyze_results.py
```

---

## 📞 获取帮助

1. **查看文档**: 先查看对应模块的 README
2. **检查日志**: `experiment/logs/` 目录
3. **验证数据**: 运行 `bash validate/validate_dataset.sh`
4. **查看配置**: `experiment/config.sh`

---

## ✅ 项目状态

- ✅ 数据准备完成 (30 cases, 6 项目)
- ✅ 验证通过 (30/30)
- ✅ 文档完整 (7 个 README + 总结)
- ✅ 实验脚本就绪 (experiment/run_ossfuzz.sh)
- ✅ 根目录已清理（删除 11 个旧脚本）
- ✅ 所有功能脚本已分类到子目录

**可以开始实验**: `cd experiment && bash run_ossfuzz.sh --project mupdf`

**可用项目**: ffmpeg, harfbuzz, imagemagick, libxml2, mupdf, poppler

---

**最后更新**: 2025-10-24  
**维护者**: Research Team

