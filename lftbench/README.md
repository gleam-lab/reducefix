---
configs:
- config_name: default
  data_files:
  - split: cpp
    path: "data/submissions/cpp/*.cpp"
  - split: python
    path: "data/submissions/python/*.py"
---

# LFTBench: A Benchmark for LLM-based Fault Localization and Test Case Reduction

## Overview

LFTBench is a comprehensive benchmark dataset for evaluating automated program repair techniques, focusing on test case reduction and fault localization using Large Language Models. The dataset contains Wrong Answer (WA) submissions from AtCoder programming contests, along with ground truth solutions, failing test inputs, and problem descriptions.

### Dataset Statistics

- **Problems**: 20 (from ABC contests 361-377)
- **C++ Submissions**: 200 (10 per problem)
- **Python Submissions**: 20 (1 per problem)
- **Total Submissions**: 220

## Dataset Structure

```
lftbench/
├── README.md                           # This file
├── dataset_info.json                   # Dataset metadata
│
├── data/
│   ├── submissions/                    # Wrong Answer (WA) submissions
│   │   ├── cpp/                        # 200 C++ WA files
│   │   │   └── {problem}_{submission}.cpp
│   │   └── python/                     # 20 Python WA files
│   │       └── {problem}_{submission}.py
│   │
│   ├── ground_truth/                   # Accepted (AC) solutions
│   │   └── cpp/                        # 20 C++ AC files
│   │       └── {problem}.cpp
│   │
│   └── test_inputs/                    # Failing test inputs
│       ├── original/                   # Original failing inputs (220 files)
│       │   ├── {problem}_{submission}.txt
│       │   └── {problem}_{submission}_py.txt
│       └── reduced/                    # Reduced test inputs (220 files)
│           ├── {problem}_{submission}.txt
│           └── {problem}_{submission}_py.txt
│
├── metadata/
│   ├── cpp_submissions.jsonl           # C++ submission metadata
│   ├── python_submissions.jsonl        # Python submission metadata
│   ├── problems.json                   # Problem descriptions
│   └── editorials/                     # Problem editorials
│       └── {problem}.txt
│
└── tests/                              # Complete test suites (1660 files, 1.5GB)
    └── {contest}/                      # abc361-abc377 (17 contests)
        └── {problem_letter}/           # Problem letter (C, D, E, etc.)
            ├── in/                     # Test input files
            │   └── test_*
            ├── out/                    # Expected output files
            │   └── test_*
            └── list.txt                # List of test cases
```

## Metadata Format

### Submission Metadata (JSONL)

Each line contains a JSON object with the following fields:

```json
{
  "problem_id": "abc361c",
  "submission_id": "67213592",
  "language": "C++",
  
  "wa_code_path": "data/submissions/cpp/abc361c_67213592.cpp",
  "ac_code_path": "data/ground_truth/cpp/abc361c.cpp",
  "original_test_input_path": "data/test_inputs/original/abc361c_67213592.txt",
  "reduced_test_input_path": "data/test_inputs/reduced/abc361c_67213592.txt",
  
  "original_input_size_bytes": 6904,
  "reduced_input_size_bytes": 6903,
  
  "test_input_summary": {
    "first_line": "698 91",
    "total_lines": 2,
    "size_bytes": 6904
  },
  
  "repair_strategies": {
    "no_tc": {"passed": false, "successful_version": null},
    "orig_tc": {"passed": true, "successful_version": 3},
    "reduced_tc": {"passed": false, "successful_version": null}
  }
}
```

### Problem Metadata (JSON)

```json
{
  "abc361c": {
    "problem_id": "abc361c",
    "contest_id": "abc361",
    "problem_letter": "c",
    "title": "C - Make Them Narrow",
    "description": "Full problem statement...",
    "samples": [
      {"input": "5 2\n3 1 5 4 9\n", "output": "2\n"},
      {"input": "3 1\n1 2 3\n", "output": "1\n"}
    ],
    "editorial_path": "metadata/editorials/abc361c.txt",
    "editorial_available": true,
    "editorial_length": 1984,
    "ac_code_path": "data/ground_truth/cpp/abc361c.cpp"
  }
}
```

## Usage

### Loading the Dataset

```python
import json
from pathlib import Path

# Load C++ submissions
with open('metadata/cpp_submissions.jsonl', 'r') as f:
    cpp_submissions = [json.loads(line) for line in f]

# Load problem metadata
with open('metadata/problems.json', 'r') as f:
    problems = json.load(f)

# Access submission data
sub = cpp_submissions[0]
problem_id = sub['problem_id']

# Read WA code
with open(sub['wa_code_path'], 'r') as f:
    wa_code = f.read()

# Read AC code
with open(sub['ac_code_path'], 'r') as f:
    ac_code = f.read()

# Read original failing input
with open(sub['original_test_input_path'], 'r') as f:
    original_input = f.read()

# Get problem description
description = problems[problem_id]['description']

# Read editorial if available
if problems[problem_id]['editorial_available']:
    with open(problems[problem_id]['editorial_path'], 'r') as f:
        editorial = f.read()
```

## Using the Test Suites

The `tests/` directory contains complete test suites for all problems, allowing researchers to validate repairs against the full test suite rather than just the failing test case.

### Test Suite Structure

Each problem has a test suite organized as:

```
tests/{contest}/{problem_letter}/
├── in/          # Input files (test_01, test_02, ...)
├── out/         # Expected output files (test_01, test_02, ...)
└── list.txt     # List of all test cases
```

### Example: Running Tests

```python
import subprocess
from pathlib import Path

# Load a submission
problem_id = "abc361c"
submission_id = "67213592"

# Read the repaired code
with open(f"data/submissions/cpp/{problem_id}_{submission_id}.cpp") as f:
    repaired_code = f.read()

# Compile the repaired code
subprocess.run(["g++", "-o", "repaired", "-"], input=repaired_code.encode())

# Run all test cases
test_dir = Path(f"tests/{problem_id[:6]}/{problem_id[-1].upper()}")
test_cases = (test_dir / "list.txt").read_text().strip().split("\n")

passed = 0
for test_name in test_cases:
    input_file = test_dir / "in" / test_name
    expected_output = (test_dir / "out" / test_name).read_text()
    
    result = subprocess.run(
        ["./repaired"],
        stdin=open(input_file),
        capture_output=True,
        text=True,
        timeout=2
    )
    
    if result.stdout == expected_output:
        passed += 1

print(f"Passed {passed}/{len(test_cases)} test cases")
```

## Repair Strategies

The dataset includes evaluation results for multiple repair strategies:

1. **no_tc**: No test case provided (only problem description and code)
2. **orig_tc**: Original failing test case provided
3. **reduced_tc**: Reduced test case provided
4. **diff_only**: Only output difference provided
5. **reduced_plus_diff**: Reduced test case with output difference

Each strategy was evaluated with up to 10 repair attempts, and the metadata records whether the repair succeeded and which version first passed all tests.

## Important Notes

### Python Ground Truth

Python submissions use C++ AC code as ground truth. This is due to the original data collection process where Python AC solutions were not available. The `ac_code_path` for all Python submissions points to C++ AC code.

### Editorial Content

Editorial files are available for all problems in the `metadata/editorials/` directory. These contain detailed explanations of the solution approach, algorithm analysis, and sample code.

### Test Input Reduction

- Original test inputs range from 23 bytes to 7 KB
- Reduced test inputs are typically < 100 bytes
- Average reduction rate: > 95%

## Data Source

- **Platform**: AtCoder (https://atcoder.jp)
- **Contests**: ABC (AtCoder Beginner Contest) 361-377
- **Submission Type**: Wrong Answer (WA)
- **Reduction Method**: LLM-based test case reduction
- **Repair Method**: LLM-based automated program repair

## Applications

This benchmark is suitable for research in:

1. **Test Case Reduction**: Studying effective methods for reducing large test inputs
2. **Automated Program Repair**: Evaluating different repair strategies
3. **Fault Localization**: Analyzing error patterns and bug types
4. **Multi-language Comparison**: Comparing repair difficulty across C++ and Python
5. **Prompt Engineering**: Optimizing repair prompts for LLMs

## License

This dataset follows the usage terms of the original data source (AtCoder).

## Citation

If you use this dataset in your research, please cite:

```bibtex
@dataset{lftbench_2025,
  title={LFTBench: A Benchmark for LLM-based Fault Localization and Test Case Reduction},
  author={Anonymous},
  year={2025},
  publisher={Hugging Face}
}
```
