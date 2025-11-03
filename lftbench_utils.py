#!/usr/bin/env python3
"""
Utility functions for loading data from lftbench
"""
import json
import os
from typing import Dict, Optional, List

# Path to lftbench directory
LFTBENCH_DIR = os.path.join(os.path.dirname(__file__), "lftbench")
METADATA_DIR = os.path.join(LFTBENCH_DIR, "metadata")
PROBLEMS_JSON = os.path.join(METADATA_DIR, "problems.json")

# Cache for loaded problems
_problems_cache = None

def load_all_problems() -> Dict[str, Dict]:
    """Load all problems from lftbench metadata"""
    global _problems_cache
    
    if _problems_cache is not None:
        return _problems_cache
    
    if not os.path.exists(PROBLEMS_JSON):
        raise FileNotFoundError(f"Problems metadata not found: {PROBLEMS_JSON}")
    
    with open(PROBLEMS_JSON, 'r', encoding='utf-8') as f:
        problems_data = json.load(f)
    
    # Convert to dict if it's a list
    if isinstance(problems_data, list):
        problems = {p['problem_id']: p for p in problems_data}
    else:
        problems = problems_data
    
    _problems_cache = problems
    return problems

def get_problem_details(problem_id: str) -> Optional[Dict]:
    """Get problem details from lftbench"""
    problems = load_all_problems()
    return problems.get(problem_id)

def get_problem_title(problem_id: str) -> str:
    """Get problem title"""
    problem = get_problem_details(problem_id)
    if problem and 'title' in problem:
        return problem['title']
    return f"Unknown Title ({problem_id})"

def get_problem_description(problem_id: str) -> str:
    """Get problem description"""
    problem = get_problem_details(problem_id)
    if problem and 'description' in problem:
        return problem['description']
    return f"# Error: Description not found for {problem_id}"

def get_problem_samples(problem_id: str) -> List[Dict]:
    """Get problem samples (input/output pairs)"""
    problem = get_problem_details(problem_id)
    if problem and 'samples' in problem:
        return problem['samples']
    return []

def get_problem_samples_json(problem_id: str) -> str:
    """Get problem samples as JSON string"""
    samples = get_problem_samples(problem_id)
    return json.dumps(samples, ensure_ascii=False, indent=2)

def get_ac_code_path(problem_id: str) -> Optional[str]:
    """Get path to AC code"""
    problem = get_problem_details(problem_id)
    if problem and 'ac_code_path' in problem:
        return os.path.join(LFTBENCH_DIR, problem['ac_code_path'])
    return None

def get_editorial_path(problem_id: str) -> Optional[str]:
    """Get path to editorial"""
    problem = get_problem_details(problem_id)
    if problem and 'editorial_path' in problem and problem.get('editorial_available', False):
        return os.path.join(LFTBENCH_DIR, problem['editorial_path'])
    return None

if __name__ == '__main__':
    # Test the functions
    test_problem_id = 'abc361c'
    
    print(f"Testing with problem: {test_problem_id}")
    print()
    
    title = get_problem_title(test_problem_id)
    print(f"Title: {title}")
    print()
    
    samples = get_problem_samples(test_problem_id)
    print(f"Samples: {len(samples)} found")
    if samples:
        print(f"  Sample 1 input (first 50 chars): {samples[0]['input'][:50]}...")
    print()
    
    description = get_problem_description(test_problem_id)
    print(f"Description length: {len(description)} characters")
    print(f"First 100 chars: {description[:100]}...")
