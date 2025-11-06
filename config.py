"""
Configuration file - Centralized management of all API tokens and sensitive information
Ensure this file is not committed to public repositories
"""

# ============================================================================
# LLM API Configuration
# ============================================================================

# DeepSeek API
DEEPSEEK_API_KEY = ''
DEEPSEEK_BASE_URL = 'https://dashscope.aliyuncs.com/compatible-mode/v1'

# Qwen API (Alibaba Cloud Tongyi Qianwen)
QWEN_API_KEY = ''
QWEN_BASE_URL = 'https://dashscope.aliyuncs.com/compatible-mode/v1'

# Baidu Qianfan API (ERNIE)
BAIDU_QIANFAN_URL = "https://qianfan.baidubce.com/v2/chat/completions"
BAIDU_QIANFAN_TOKEN = ""  # Fill in if needed

# ============================================================================
# AtCoder Configuration
# ============================================================================

DEFAULT_LANGUAGE = 'cpp'
ATCODER_CPP_LANG_ID = '5001'

# ============================================================================
# LLM Request Configuration
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
# Evaluation Configuration
# ============================================================================

JUDGE_POLL_ATTEMPTS = 60
JUDGE_POLL_WAIT = 5

# ============================================================================
# Important Notes
# ============================================================================
# 1. Do not commit this file to public Git repositories
# 2. It is recommended to add config.py to .gitignore
# 3. Create config.example.py as a template without real tokens

