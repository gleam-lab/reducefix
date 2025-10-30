"""OSS-Fuzz 长输入项目对比实验框架。

模块结构：
- adapters: 程序运行器与判定逻辑（包含 Runner, RunResult, InterestingOracle）
- ddmin: 经典 ddmin 缩减
- reducefix: 强化缩减器（启发式 + 分块 + 可选 LLM 引导）
- bench: CLI，对比 ddmin 与 ReduceFix 并输出指标
"""

from .adapters import Runner, RunResult, InterestingOracle
from .ddmin import ddmin_reduce
from .reducefix import reduce_fix

__all__ = [
    "Runner",
    "RunResult",
    "InterestingOracle",
    "ddmin_reduce",
    "reduce_fix",
]


