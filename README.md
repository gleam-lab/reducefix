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

**Objective**: Evaluate whether LLM can generate reducers that preserve program failure while reducing test input size.

**Experimental Setup**:
- Dataset: 200 buggy C++ submissions from 20 AtCoder problems
- Metrics: Success rate and compression ratio
- Comparison: Pure LLM reduction vs. ReduceFix (LLM + ddmin)

**Commands**:
```bash
# Run all problems for reducer generation and testing
./rq1.sh qwen-baseline

# For regenerating all reducers from scratch
./rq1.sh qwen-regenerate --force

# Analyze results
python3 analyze_rq1.py --result-file reducer_results.json
```

**Expected Results**:
- ReduceFix success rate: 95% overall (100% C-difficulty, 96% D-difficulty, 88% E&F-difficulty)
- Compression ratio: 89.1% average reduction
- Pure LLM baseline: 40% success rate with 37x higher token cost

### RQ-2: Effectiveness of Reduced Test Cases for Repair

**Objective**: Determine if reduced counterexamples improve repair accuracy compared to no test case or full test case.

**Experimental Setup**:
- 4 LLMs: Qwen2.5-Coder-7B, GLM4-9B, Qwen-Plus, DeepSeek-V3
- 3 prompting strategies: Baseline (no test), Origin Test (full input), Reduced Test (ReduceFix)
- Metrics: pass@k for k ∈ {1,5,10}

**Commands**:
```bash
# Run repair evaluation for all strategies and models
./rq2.sh qwen25-coder7b qwen2.5-coder-7b-instruct
./rq2.sh glm4-9b glm4-9b-chat  
./rq2.sh qwenplus qwen-plus
./rq2.sh deepseekv3 deepseek-v3

# For regenerating all repair attempts
./rq2.sh qwen25-coder7b qwen2.5-coder-7b-instruct --regenerate

# Compare results across strategies
python3 analyze_rq2.py --compare-strategies
```

**Expected Results**:
- Reduced Test consistently outperforms both Baseline and Origin Test
- Qwen2.5-Coder-7B: 20.0% → 25.5% pass@10 improvement
- Larger improvements on harder problems (D-difficulty: +11.2%, E&F: +1.7%)

### RQ-3: Influence of Prompt Composition

**Objective**: Distinguish between the benefits of length reduction vs. information selection in prompts.

**Experimental Setup**:
- 5 prompt variants: Baseline, Origin Test, Diff Lines, Reduced Test, Reduced + Origin
- Model: Qwen2.5-Coder-7B-instruct
- Analysis: Prompt length vs. repair accuracy

**Commands**:
```bash
# Run all prompt variants
./rq3.sh qwen25-ablation

# For regenerating with all prompt variants
./rq3.sh qwen25-ablation --regenerate

# Analyze prompt composition effects
python3 analyze_rq3.py --prompt-analysis
```

**Expected Results**:
- Reduced Test (6.4KB): 25.5% pass@10
- Diff Lines (3.1KB): 20.0% pass@10  
- Reduced + Origin (36.4KB): 19.0% pass@10
- Both length and information content matter for optimal performance

### RQ-4: Integration with ChatRepair

**Objective**: Validate extensibility by integrating ReduceFix with existing APR system ChatRepair.

**Experimental Setup**:
- Base system: ChatRepair with MAX_RETRY=1, length=2
- Comparison: Original vs. ReduceFix-enhanced version
- Same dataset and evaluation metrics

**Commands**:
```bash
# Run ChatRepair with original and reduced inputs
./rq4.sh chatrepair-baseline

# For regenerating ChatRepair experiments
./rq4.sh chatrepair-baseline --regenerate

# Compare ChatRepair variants
python3 analyze_rq4.py --chatrepair-comparison
```

**Expected Results**:
- Overall pass@10 improvement: 30.5% → 37.0% (+21.3% relative)
- Largest gains on hardest problems (E&F: +67.0% relative improvement)

## Batch Processing Scripts

### `rq1.sh` - Reducer Generation and Testing
```bash
#!/bin/bash
# Usage: ./rq1.sh <result_tag> [--force]
# Generates reducers and tests them on all 20 problems
```

### `rq2.sh` - Multi-Strategy Repair Evaluation  
```bash
#!/bin/bash
# Usage: ./rq2.sh <result_tag> <repair_model> [--regenerate]
# Evaluates 3 repair strategies (baseline, origin, reduced) using specified model
```

### `rq3.sh` - Prompt Ablation Study
```bash
#!/bin/bash
# Usage: ./rq3.sh <result_tag> [--regenerate] 
# Tests 5 prompt variants to analyze composition effects
```

### `rq4.sh` - ChatRepair Integration
```bash
#!/bash
# Usage: ./rq4.sh <result_tag> [--regenerate]
# Runs ChatRepair with original and ReduceFix-enhanced prompts
```

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

## Key Parameters

### Reducer Generation
- Model: qwen-plus (configurable via `--llm-model`)
- Temperature: 0.0 (greedy decoding as per paper)
- Max tokens: 4096
- Timeout: 60 seconds (as per paper)

### Repair Evaluation  
- Default model: qwen2.5-coder-7b-instruct
- Temperature: 0.8
- Versions per strategy: 10 (TOP_K, corresponding to N=10 in paper)
- Max threads: 5 (configurable via `--max-threads`)
- Evaluation: pass@k for k ∈ {1,5,10}

## Troubleshooting

1. **API Key Issues**: Ensure your API keys are correctly configured in `tutor.py`
2. **Missing Test Cases**: Download AtCoder test cases and place in `tests/` directory
3. **Memory Issues**: Reduce `--max-threads` parameter for repair evaluation
4. **Timeout Issues**: Increase timeout values in configuration files

## Citation

If you use ReduceFix in your research, please cite our paper:

```bibtex
@article{reducefix2024,
  title={ReduceFix: Automated Program Repair with LLM-Generated Input Reduction},
  author={[Authors]},
  journal={[Journal]},
  year={2024}
}
```