# ReduceFix

ReduceFix is an automated program repair (APR) system that leverages LLM-generated reducers to minimize failure-inducing test inputs before using them to guide repair generation. This repository contains the implementation and experimental scripts for reproducing the results presented in our paper.

## Overview

ReduceFix consists of three main phases:
1. **Reducer Generation**: Prompts a code LLM once to generate a customized reducer script that can automatically reduce failure-inducing inputs for the specific task
2. **Input Reduction**: Executes the generated reducer script to shrink the failure-inducing input i₀ into a reduced test input i* while preserving the failure
3. **Patch Generation**: Embeds ⟨P, s_w, i*⟩ in a repair prompt, samples candidate patches, and validates each one against the entire test suite until a correct program is found

The pipeline receives five inputs: the task description P, a correct reference solution A, a buggy submission s_w, the hidden test suite I, and one failure-inducing input i₀.

## Prerequisites

- Python 3.8+
- Required Python packages: `pip install -r requirements.txt`
- Access to LLM APIs (Qwen-Plus, DeepSeek-V3, etc.) with API keys configured in `tutor.py`
- AtCoder test cases (download and place in `tests/` directory)

## Quick Start

1. **Setup Configuration**:
   ```bash
   # Configure your API keys in tutor.py
   cp tutor.py.template tutor.py
   # Edit tutor.py with your actual API credentials
   ```

2. **Download Test Cases**:
   ```bash
   # Download AtCoder test cases to tests/ directory
   # Structure: tests/{contest_id}/{problem_letter}/in/
   ```

3. **Run a Single Problem**:
   ```bash
   # Generate reducer for abc361c
   python3 reducer_builder.py abc361c --llm-model qwen-plus --model-tag example
   
   # Test the reducer and collect WA submissions
   python3 reducer_test.py abc361c --model-tag example --reducer-model qwen-plus
   
   # Evaluate repair strategies
   python3 evaluate_repair.py abc361c --model-tag example --repair-model qwen-plus
   ```

## Reproducing Research Questions

### RQ-1: Effectiveness of LLM-generated Reducers

```bash
./rq1.sh qwen-baseline
```

For details and options, see the script content.

### RQ-2: Effectiveness of Reduced Test Cases for Repair

```bash
./rq2.sh qwen25-coder7b qwen2.5-coder-7b-instruct
./rq2.sh glm4-9b glm4-9b-chat  
./rq2.sh qwenplus qwen-plus
./rq2.sh deepseekv3 deepseek-v3
```

For details and options, see the script content.

### RQ-3: Influence of Prompt Composition

```bash
./rq3.sh qwen25-ablation
```

For details and options, see the script content.

### RQ-4: Integration with ChatRepair

```bash
./rq4.sh chatrepair-baseline
```

For details and options, see the script content.

## Directory Structure

```
ReduceFix/
├── results/                    # Problem-specific directories
│   ├── abc361c/               # AC code, WA submissions, reducers
│   ├── abc362d/
│   └── ...
├── tests/                     # AtCoder test cases
│   ├── abc361/C/in/
│   ├── abc362/D/in/  
│   └── ...
├── reducer_builder.py         # Generate problem-specific reducers
├── reducer_test.py            # Test reducers on WA submissions
├── evaluate_repair.py         # Evaluate repair strategies
├── consolidate_reducer_results.py  # Merge reducer results
├── summarize_repair_results.py     # Analyze repair results
├── llm.py                     # LLM interface
├── tutor.py                   # API client configuration
├── tools.py                   # Utility functions
└── analyze_*.py               # Analysis scripts for each RQ
```

## Result Files

- `reducer_results.json`: Consolidated reducer testing results
- `result_<model_tag>.json`: Repair evaluation results for each model
- `<problem>/reducer.py`: Generated reducer for each problem
- `<problem>/<submission_id>.*`: Individual submission artifacts

## Troubleshooting

1. **API Key Issues**: Ensure your API keys are correctly configured in `tutor.py`
2. **Missing Test Cases**: Download AtCoder test cases and place in `tests/` directory
3. **Memory Issues**: Reduce `--max-threads` parameter for repair evaluation
4. **Timeout Issues**: Increase timeout values in configuration files