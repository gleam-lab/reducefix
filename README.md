# ReduceFix

ReduceFix is an automated program repair (APR) system that leverages LLM-generated reducers to minimize failure-inducing test inputs before using them to guide repair generation. This repository contains the implementation and experimental scripts for reproducing the results presented in our paper.

## Overview

ReduceFix consists of three main phases:
1. **Reducer Generation**: Prompts a code LLM once to generate a customized reducer script that can automatically reduce failure-inducing inputs for the specific task
2. **Input Reduction**: Executes the generated reducer script to shrink the failure-inducing input i₀ into a reduced test input i* while preserving the failure
3. **Patch Generation**: Embeds ⟨P, $s_w$, i*⟩ in a repair prompt, samples candidate patches, and validates each one against the entire test suite until a correct program is found

The pipeline receives five inputs: the task description P, a correct reference solution A, a buggy submission $s_w$, the hidden test suite I, and one failure-inducing input i₀.

## Prerequisites

- Python 3.8+
- Access to LLM APIs (Qwen-Plus, DeepSeek-V3, etc.) with API keys configured in `config.py`

## Quick Start

1. **Setup Configuration**:
   ```bash
   # Configure your API keys in config.py
   # Edit config.py with your actual API credentials
   ```

2. run the following scripts:

```bash
./rq1.sh
./rq2.sh
./rq3.sh
./rq4.sh
./rq5.sh
```

3. The LFTBench (including C++ and Python versions) is located in the `lftbench` sub-directory.

## Repository Structure

```
ReduceFix/
├── lftbench/                  # LFTBench dataset
│   ├── data/                  # Ground truth and submissions
│   │   ├── ground_truth/      # AC (Accepted) solutions
│   │   │   ├── cpp/           # C++ AC codes
│   │   │   └── python/        # Python AC codes
│   │   └── submissions/       # WA (Wrong Answer) submissions
│   │       ├── cpp/           # C++ submissions
│   │       └── python/        # Python submissions
│   ├── metadata/              # Problem metadata
│   │   ├── problems.json      # Problem descriptions, samples
│   │   ├── cpp_submissions.jsonl
│   │   └── python_submissions.jsonl
│   ├── tests/                 # Full test suites
│   │   ├── abc361/C/in/       # Test inputs for each problem
│   │   └── ...
│   └── README.md              # Dataset documentation
│
├── results/                   # Experiment artifacts
│   ├── abc361c/               # Per-problem directory
│   │   ├── reducer.py         # Generated reducer
│   │   ├── ac.cpp             # AC code
│   │   ├── 68123456_cpp/      # Per-submission artifacts
│   │   └── ...
│   └── ...
│
├── oss_fuzz_results/          # OSS-Fuzz evaluation data
│   ├── cases_data/            # Case-by-case data
│   ├── experiment_results/    # Experiment statistics
│   └── compute_*.py           # OSS-Fuzz analysis scripts
│
├── temp/                      # Full result backups
│   ├── result_reducer_reducefix_full.json
│   └── ...
│
├── result_reducer_*.json      # Minimized reduction results (RQ1)
├── result_repair_*.json       # Minimized repair results (RQ2, RQ3)
├── result_chatrepair.json     # ChatRepair results (RQ4)
├── result_cref.json           # CRef results (RQ4)
│
├── rq1.sh                     # RQ1: Reducer effectiveness
├── rq2.sh                     # RQ2: Repair with reduced tests
├── rq3.sh                     # RQ3: Prompt composition
├── rq4.sh                     # RQ4: ChatRepair & CRef integration
├── rq5.sh                     # RQ5: OSS-Fuzz evaluation
│
├── reducer_builder.py         # Generate problem-specific reducers
├── reducer_test.py            # Test reducers on submissions
├── retest_single.py           # Single submission testing (RQ1 demo)
│
├── evaluate_repair.py         # Repair evaluation (main)
├── evaluate_repair_main.py    # Repair evaluation (RQ3)
├── evaluate_repair_with_chatrepair.py  # ChatRepair evaluation
│
├── analyze_*.py               # Statistical analysis for each RQ
├── compare_rq1_methods.py     # RQ1 comparison table
├── summarize_*.py             # Result summarization scripts
│
├── llm.py                     # LLM API interface
├── tutor.py                   # API client configuration
├── config.py                  # API keys and configuration
├── lftbench_utils.py          # Dataset access utilities
├── tools.py                   # Utility functions
└── README.md                  # This file
```

### Key Components

- **`lftbench/`**: Self-contained benchmark dataset with problems, solutions, submissions, and test suites
- **`results/`**: Generated reducers and per-problem/per-submission artifacts
- **`rq*.sh`**: Main entry points for reproducing each research question
- **`result_*.json`**: Consolidated experimental results (minimized for portability)
- **`temp/`**: Full-version result files with detailed metadata (not for distribution)
- **Core scripts**: `reducer_builder.py`, `reducer_test.py`, `evaluate_repair*.py`
- **Analysis scripts**: `analyze_*.py`, `summarize_*.py` for statistical analysis

## Reproducing Research Questions

### RQ-1: Effectiveness of LLM-generated Reducers

```bash
./rq1.sh
```

For details and options, see the script content.

You can run a demo for RQ-1:

```bash
./rq1.sh --retest abc376e 66915962
```

### RQ-2: Effectiveness of Reduced Test Cases for Repair

```bash
./rq2.sh
```

For details and options, see the script content.

### RQ-3: Influence of Prompt Composition

```bash
./rq3.sh
```

For details and options, see the script content.

### RQ-4: Integration with ChatRepair and CREF

```bash
./rq4.sh
```

For details and options, see the script content.

### RQ-5: Evaluation on OSS-Fuzz

```bash
./rq5.sh
```

For details and options, see the script content.
