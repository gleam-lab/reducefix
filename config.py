"""
配置文件 - 统一管理所有 API token 和敏感信息
使用前请确保不将此文件提交到公开仓库
"""

# ============================================================================
# LLM API 配置
# ============================================================================

# DeepSeek API
DEEPSEEK_API_KEY = ''
DEEPSEEK_BASE_URL = 'https://dashscope.aliyuncs.com/compatible-mode/v1'

# Qwen API (阿里云通义千问)
QWEN_API_KEY = ''
QWEN_BASE_URL = 'https://dashscope.aliyuncs.com/compatible-mode/v1'

# Baidu Qianfan API (ERNIE)
BAIDU_QIANFAN_URL = "https://qianfan.baidubce.com/v2/chat/completions"
BAIDU_QIANFAN_TOKEN = ""  # 如需使用请填写

# ============================================================================
# AtCoder 配置
# ============================================================================

DEFAULT_LANGUAGE = 'cpp'
ATCODER_CPP_LANG_ID = '5001'

# ============================================================================
# LLM 请求配置
# ============================================================================

LLM_REQUEST_COUNT = 2
DEFAULT_MODEL = "qwen-plus"
DEFAULT_MAX_TOKENS = 4096
DEFAULT_TEMPERATURE = 0.0
DEFAULT_TIMEOUT = 300  # 5 minutes

# Rate limiting
MAX_BAIDU_TOKENS = 3000
BAIDU_RATE_LIMIT_BACKOFF = 30  # seconds
BAIDU_RATE_LIMIT_RETRIES = 5

# ============================================================================
# 评测配置
# ============================================================================

JUDGE_POLL_ATTEMPTS = 60
JUDGE_POLL_WAIT = 5

# ============================================================================
# 注意事项
# ============================================================================
# 1. 请勿将此文件提交到公开的 Git 仓库
# 2. 建议将 config.py 添加到 .gitignore
# 3. 可以创建 config.example.py 作为模板，不包含真实 token

