# OSS-Fuzz ReduceFix 实验框架

本目录包含针对 OSS-Fuzz 项目的 ReduceFix 测试用例缩减和自动修复实验框架。

## 📋 目录结构

```
oss_fuzz/
├── 🎯 核心运行脚本
├── 📊 数据目录
├── 🛠️ 功能模块
├── 🔧 工具脚本
└── ⚙️ 配置文件
```

---

## 🎯 核心运行脚本

### 主要入口
- **`run_ossfuzz.sh`** - 一键运行脚本，包装 `run_complete_reducefix.py`
  - 提供友好的命令行接口
  - 支持参数：`--project`, `--all`, `--model`, `--repair-model`, `--timeout`, `--skip-*`, `--force`
  - 使用示例：`./run_ossfuzz.sh --project poppler`

- **`run_complete_reducefix.py`** - ReduceFix 完整实验流程控制器
  - 步骤 1: 为每个 project 生成 LLM reducer（调用 `reducer_builder.py`）
  - 步骤 2: 对每个 case 运行三种缩减方法（调用 `bench.py`）
  - 步骤 3: 使用 ReduceFix 缩减结果进行修复评估（调用 `apr_repair.py`）
  - 自动汇总统计结果

---

## 📊 数据目录

### 输入数据
- **`cases_data/`** - 测试案例数据（按项目分组）
  ```
  cases_data/
  ├── <project>/
  │   └── arvo-<id>/
  │       ├── testcase          # POC 文件（崩溃输入）
  │       ├── metadata.json     # 案例元数据
  │       └── fix.patch         # Ground truth 修复补丁
  ```

- **`ARVO-Meta/`** - ARVO 数据集元数据（权威信息源）
  ```
  ARVO-Meta/archive_data/meta/*.json
  ```

### 输出数据
- **`artifacts/`** - 实验结果输出目录
  ```
  artifacts/
  ├── <project>/
  │   └── reducefix_<model>/
  │       └── reducer.py        # LLM 生成的 reducer
  └── <case_id>/
      └── reducefix_<model>/
          ├── original.bin            # 原始输入
          ├── reduced.ddmin           # DDMin 缩减结果
          ├── reduced.reducefix       # ReduceFix 缩减结果
          ├── reduced.llm_generated   # LLM 直接生成结果
          ├── stats.json              # 缩减统计
          └── repair_results/
              └── <model>/
                  ├── results.json    # 修复评估结果
                  └── patches/        # 生成的补丁文件
  ```

- **`experiment_results/`** - 实验汇总结果
  - `FINAL_REPORT.md` - 最终实验报告
  - `summary.json` - 总体统计摘要
  - `reduce_overview.json` - 缩减结果概览
  - `<project>_reducefix_<model>_reduce_summary.json` - 按项目的汇总

- **`testcase_cache/`** - 从 OSS-Fuzz 下载的测试用例缓存
  - 格式：`<testcase_id>.testcase`
  - 用于备份和快速恢复

---

## 🛠️ 功能模块

### 缩减模块
- **`reducer_builder.py`** - LLM Reducer 生成器
  - 使用 one-shot learning 生成测试用例缩减器
  - 为整个 project 生成通用 reducer（非特定案例）
  - 输出：`artifacts/<project>/reducefix_<model>/reducer.py`

- **`bench.py`** - 三种缩减方法对比测试
  - 方法 1: **DDMin-only** - 经典 delta debugging
  - 方法 2: **ReduceFix** - 使用 LLM 生成的 reducer
  - 方法 3: **LLM-generated** - LLM 直接压缩输入
  - 输出：缩减后的文件和统计信息（`stats.json`）

- **`ddmin.py`** - DDMin 算法实现
  - 经典的 delta debugging minimization 算法
  - 支持按行（line-level）或按块（block-level）分割
  - 用于基线对比

- **`reducefix.py`** - ReduceFix 基础算法
  - 启发式块级优先缩减
  - 策略：块级贪心 → 二分搜索 → 行级微调

### 修复模块
- **`apr_repair.py`** - 自动程序修复（APR）评估模块
  - 三种策略对比：
    1. `without_test` - 不使用测试用例
    2. `origin_test` - 使用原始测试用例
    3. `reduced_test` - 使用 ReduceFix 缩减后的测试用例
  - 每个策略生成 TOP_K=10 个补丁版本
  - 使用 Docker 进行真实编译和崩溃测试验证
  - 输出：`results.json` 和补丁文件

- **`docker_patch_tester.py`** - Docker 补丁测试器
  - 真实的编译和崩溃测试
  - 工作流程：启动容器 → 应用补丁 → 编译 → 测试崩溃
  - 支持增量验证和详细日志

### 适配器模块
- **`adapters.py`** - 程序运行器和 Docker 适配器
  - `Runner` 类：通用程序运行器
  - `DockerRunner` 类：Docker 容器内运行
  - 特定项目的 runner：`pdfium_runner`, `harfbuzz_runner` 等
  - `default_oracle()`：崩溃判定函数（检测 Sanitizer 输出）

- **`crash_detector.py`** - 崩溃检测工具
  - 检测各种 Sanitizer 报告（ASan, UBSan, MSan, TSan, LSan）
  - 识别崩溃信号（SIGSEGV, SIGABRT 等）

---

## 🔧 工具脚本

### 数据获取
- **`sync_cases_from_arvo_meta.py`** - 从 ARVO-Meta 同步元数据到 `cases.json`
  - 回填字段：target, arvo_id, description, docker_image 等
  - 优先处理的项目：php-src, mruby, libraw, poppler, mupdf

- **`download_all_testcases.py`** - 批量下载测试用例（POC 文件）
  - 从 OSS-Fuzz 官方网站下载
  - 保存到：`cases_data/<project>/arvo-<id>/testcase`

- **`pull_docker_images_robust.py`** - 稳定的 Docker 镜像拉取工具
  - 支持重试机制和断点续传
  - 拉取格式：`n132/arvo:<id>-vul` 和 `n132/arvo:<id>-fix`
  - 保存进度到：`docker_pull_progress.json`

- **`pull_docker_images.py`** - 简单版 Docker 镜像拉取（已被 robust 版本替代）

- **`prune_and_annotate_cases.py`** - 裁剪和标注 `cases.json`
  - 只保留已下载的案例
  - 补充 patch 内容和大小信息

### 数据处理
- **`download_selected_projects.py`** - 下载指定项目的案例
  - 支持按项目列表批量下载

- **`download_top10_large_projects.py`** - 下载 Top-10 大型项目

### 统计分析
- **`compute_reduce_stats.py`** - 计算缩减统计数据
  - 分析 `artifacts/` 中的 `stats.json` 文件
  - 生成汇总报告到 `experiment_results/`

- **`batch_test_and_stats.py`** - 批量测试和统计（早期版本，已不推荐使用）

- **`show_case_info.py`** - 显示案例详细信息
  - 查询工具，展示案例的元数据、大小等

### 辅助工具
- **`check_docker_fuzzers.sh`** - 检查 Docker 容器中的 fuzzer
  - 列出容器内的可用 fuzzer 程序
  - 帮助确定正确的 fuzzer 路径

- **`reducefix_with_timeout.py`** - 带超时的 ReduceFix 执行器
  - 包装 ReduceFix，添加超时控制
  - 功能已整合到主流程中

---

## ⚙️ 配置文件

### 主要配置
- **`cases.json`** - 案例配置文件（核心配置）
  ```json
  {
    "arvo-<id>": {
      "target": "项目名",
      "arvo_id": "ARVO ID",
      "description": "崩溃描述",
      "crash_type": "崩溃类型",
      "data_dir": "数据目录路径",
      "docker_image_vul": "漏洞镜像",
      "docker_image_fix": "修复镜像",
      "metadata_file": "元数据文件路径",
      "patch_file": "补丁文件路径",
      ...
    }
  }
  ```

- **`project_groups.json`** - 项目分组配置
  ```json
  [
    {
      "project": "项目名",
      "cases": ["arvo-xxx", ...],
      "reducer_case": "arvo-xxx"  // 用于生成 reducer 的代表案例
    }
  ]
  ```
  - 被 `run_complete_reducefix.py` 使用
  - 定义实验的项目和案例分组

### 模块配置
- **`config.py`** - 全局配置常量
  - GitHub Token
  - API Keys（Bailian, DeepSeek, Qwen）
  - Neo4j 配置
  - LLM 参数（MAX_TOKENS, TEMPERATURE 等）
  - 知识图谱配置

- **`utils.py`** - 通用工具函数库
  - 文件操作、Git 操作、语法检查
  - 文本分析、代码提取
  - 各种辅助功能（1300+ 行）

### Python 包配置
- **`__init__.py`** - Python 包初始化文件
  - 导出常用类和函数
  - 版本信息

---

## 🚀 使用流程

### 1. 准备数据
```bash
# 从 ARVO-Meta 同步元数据
python3 oss_fuzz/sync_cases_from_arvo_meta.py

# 下载测试用例
python3 oss_fuzz/download_all_testcases.py

# 拉取 Docker 镜像
python3 oss_fuzz/pull_docker_images_robust.py

# 裁剪和标注 cases.json
python3 oss_fuzz/prune_and_annotate_cases.py
```

### 2. 运行实验
```bash
# 运行单个项目
./oss_fuzz/run_ossfuzz.sh --project poppler

# 运行所有项目
./oss_fuzz/run_ossfuzz.sh --all

# 指定模型和超时
./oss_fuzz/run_ossfuzz.sh --project mupdf --model qwen-plus --timeout 900

# 跳过某些步骤
./oss_fuzz/run_ossfuzz.sh --project harfbuzz --skip-build

# 强制重新运行
./oss_fuzz/run_ossfuzz.sh --project poppler --force
```

### 3. 查看结果
```bash
# 查看统计信息
find oss_fuzz/artifacts -name 'stats.json' -exec cat {} \;

# 查看修复结果
find oss_fuzz/artifacts -name 'results.json' | head -5

# 查看汇总报告
cat oss_fuzz/experiment_results/FINAL_REPORT.md
```

---

## 📦 依赖项

### Python 包
- `llm` - LLM API 调用（父目录）
- `docker` - Docker 操作
- `unidiff` - Patch 解析
- `github` - GitHub API
- `chardet` - 字符编码检测
- 其他标准库

### 外部工具
- Docker - 容器化测试
- Git - 版本控制
- file - 文件类型识别

### LLM 模型
- Qwen Plus（默认 reducer 生成）
- DeepSeek v3.1（默认修复）
- 其他支持的模型：Qwen 2.5 Coder 7B, GPT-4, Claude-3 等

---

## 📝 注意事项

1. **数据结构**：确保 `cases.json` 和 `cases_data/` 目录结构正确
2. **Docker 镜像**：实验前需要拉取对应的 Docker 镜像（`n132/arvo:*`）
3. **API Keys**：在 `.env` 文件中配置必要的 API keys
4. **磁盘空间**：实验结果会占用较多空间，建议预留至少 10GB
5. **超时设置**：大型测试用例可能需要更长的超时时间（`--timeout` 参数）
6. **缓存机制**：脚本会自动检测已完成的步骤，使用 `--force` 强制重新运行

---

## 🔗 相关资源

- ARVO-Meta: https://github.com/n132/ARVO-Meta
- OSS-Fuzz: https://github.com/google/oss-fuzz
- ReduceFix 论文: [待补充]

---

## 📄 文件清单

### 脚本文件（按字母排序）
- adapters.py
- apr_repair.py
- batch_test_and_stats.py
- bench.py
- check_docker_fuzzers.sh
- compute_reduce_stats.py
- config.py
- crash_detector.py
- ddmin.py
- docker_patch_tester.py
- download_all_testcases.py
- download_selected_projects.py
- download_top10_large_projects.py
- prune_and_annotate_cases.py
- pull_docker_images.py
- pull_docker_images_robust.py
- reducer_builder.py
- reducefix.py
- reducefix_with_timeout.py
- run_complete_reducefix.py
- run_ossfuzz.sh
- show_case_info.py
- sync_cases_from_arvo_meta.py
- utils.py
- __init__.py

### 配置文件
- cases.json
- project_groups.json
- config.py

### 目录
- artifacts/
- ARVO-Meta/
- cases_data/
- experiment_results/
- testcase_cache/
- __pycache__/

---

*最后更新：2025-10-24*

