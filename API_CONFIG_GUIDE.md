# API 配置指南 - 启用 Pure LLM 基线

## 📋 概述

当前 `./rq1.sh --retest` 命令中，Pure LLM 基线显示的是预运行结果。如果你想**实际调用 LLM API** 运行 Pure LLM 基线，需要配置 API key。

## ⚠️ 为什么默认不调用？

1. **成本考虑**: LLM API 调用需要消耗 token，有实际费用
2. **隐私安全**: API key 是敏感信息，不应硬编码在代码中
3. **演示效果**: 预运行结果已经足够展示三种方法的对比
4. **运行速度**: ReduceFix 和 DDmin-only 不需要网络调用即可快速运行

## 🔧 配置步骤

### 方法 1: 修改 tutor.py（不推荐用于公开发布）

编辑 `tutor.py` 文件：

```python
# 找到第 22 行，替换为你的真实 API key:
QWEN_API_KEY = 'sk-xxxxxxxxxxxxxx'  # 替换为真实 key
```

### 方法 2: 使用环境变量（推荐）

创建一个 `.env` 文件或在 shell 中设置：

```bash
# 方式 1: 临时设置（当前 session）
export QWEN_API_KEY="your-actual-api-key-here"

# 方式 2: 持久化到 ~/.bashrc 或 ~/.zshrc
echo 'export QWEN_API_KEY="your-actual-api-key-here"' >> ~/.bashrc
source ~/.bashrc
```

然后修改 `tutor.py` 来读取环境变量：

```python
import os

# 改为从环境变量读取
QWEN_API_KEY = os.environ.get('QWEN_API_KEY', 'YOUR_QWEN_API_KEY')
QWEN_BASE_URL = 'https://dashscope.aliyuncs.com/compatible-mode/v1'
```

## 📝 获取 API Key

### Qwen API (阿里云通义千问)

1. 访问 https://dashscope.aliyun.com/
2. 注册/登录阿里云账号
3. 开通 DashScope 服务
4. 在控制台创建 API key
5. 复制 API key

### 其他 LLM API

`tutor.py` 也支持 DeepSeek，配置方法类似。

## ✅ 验证配置

配置完成后，运行以下命令验证：

```python
python3 -c "import tutor; print('✓ 配置成功!' if tutor.qwen_client else '✗ 配置失败')"
```

## 🚀 使用 Pure LLM

配置成功后，你可以：

1. **在研究中使用**: 运行完整的 RQ1 实验，包含 Pure LLM 基线
2. **实际对比**: 在 `retest_single.py` 中实际调用 LLM 进行压缩

## 💰 成本估算

每次 Pure LLM 压缩调用大约消耗：
- 输入: ~5000 tokens (问题描述 + 原始输入 + 指令)
- 输出: ~100 tokens (压缩后的输入)
- 总计: ~5100 tokens/次

根据通义千问的定价（截至 2024 年）：
- qwen-plus: ¥0.008/千tokens（输入）+ ¥0.02/千tokens（输出）
- 单次调用成本: ~¥0.05

对于 200 个提交的完整实验: ~¥10

## 📌 注意事项

1. **不要提交 API key 到 Git**:
   ```bash
   # 添加到 .gitignore
   echo "tutor_local.py" >> .gitignore  # 如果你创建了本地配置
   echo ".env" >> .gitignore
   ```

2. **使用前测试**: 先用一个小例子测试配置是否正确

3. **监控费用**: 定期检查 API 使用情况和费用

4. **速率限制**: 注意 API 的调用频率限制，避免被限流

## 🎯 当前默认策略

为了方便其他研究者复现和测试，我们的默认配置：
- ✅ **ReduceFix**: 可以直接运行（不需要 API）
- ✅ **DDmin-only**: 可以直接运行（不需要 API）
- ⚠️ **Pure LLM**: 显示预运行结果（避免 API 成本）

这样用户下载项目后可以立即体验前两种方法的完整流程！

## 🔍 依赖关系

```
retest_single.py (Pure LLM 调用)
    ↓
llm.py (LLM 调用封装)
    ↓
tutor.py (qwen_client 初始化)
    ↓
OpenAI API (需要 QWEN_API_KEY)
```

**缺失环节**: `tutor.py` 中的 `QWEN_API_KEY` 是占位符 `'YOUR_QWEN_API_KEY'`

**解决方案**: 按照上述步骤配置真实的 API key

---

**如有问题，请参考 `llm.py` 和 `tutor.py` 中的代码实现。**

