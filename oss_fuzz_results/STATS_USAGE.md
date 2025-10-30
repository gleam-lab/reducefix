# 实验统计工具使用指南

## 主要统计脚本

### 📊 compute_experiment_stats.py（推荐使用）
**完整的 ReduceFix 实验统计工具**

统计内容：
- ✅ **Reduce 效果**：DDMin、ReduceFix、LLM-Generated 三种策略的成功率和压缩率
- ✅ **Repair 成功率**：pass@1、pass@5、pass@10（前k个版本中至少1个成功）
- ✅ 自动去重，按项目分组

使用方法：
```bash
# 完整统计（包含每个样本详情）
python3 oss_fuzz/compute_experiment_stats.py --model-tag reducefix_qwen

# 只看汇总数据
python3 oss_fuzz/compute_experiment_stats.py --model-tag reducefix_qwen --no-details
```

输出文件：
- `oss_fuzz/experiment_results/experiment_overview.json`

---

### 📋 compute_repair_stats.py
**专门的 Repair 统计工具**

统计内容：
- 三种策略的总体成功率（无测试/原始测试/缩减测试）
- 按项目显示详细结果

使用方法：
```bash
# 显示详细统计
python3 oss_fuzz/compute_repair_stats.py --detailed

# 指定输出文件
python3 oss_fuzz/compute_repair_stats.py --detailed --output results.json
```

输出文件：
- `oss_fuzz/artifacts/repair_summary.json`（默认）

---

## 统计指标说明

### Reduce 指标
- **成功率**：压缩后大小 < 原始大小的案例比例
- **平均压缩率**：所有案例的平均压缩百分比

### Repair 指标
- **pass@1**：第1个生成的补丁就成功的案例比例
- **pass@5**：前5个补丁中至少1个成功的案例比例
- **pass@10**：前10个补丁中至少1个成功的案例比例

---

## 当前实验数据（6个案例）

### Reduce 效果总结
| 项目 | 案例数 | ReduceFix 成功率 | 平均压缩率 |
|------|--------|-----------------|-----------|
| mupdf | 5 | 100% | 87.4% |
| php-src | 1 | 100% | 97.7% ⭐ |
| poppler | 5 | 80% | 41.1% |

### Repair 成功率总结（pass@10）
| 策略 | 成功案例 | 总案例 | 成功率 |
|------|---------|--------|--------|
| 无测试用例（Baseline） | 2 | 6 | 33.3% |
| 原始测试用例 | 0 | 6 | 0% |
| 缩减测试用例（ReduceFix） | 0 | 6 | 0% |

---

## 备注
- `compute_reduce_stats.py.backup`：旧版本的 reduce 统计脚本（已被 compute_experiment_stats.py 替代）
