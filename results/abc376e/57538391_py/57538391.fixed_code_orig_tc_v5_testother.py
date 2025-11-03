import sys
from typing import List, Tuple

def solve_case(n: int, k: int, a: List[int], b: List[int]) -> int:
    # Create list of (A_i, B_i, index) and sort by A_i in ascending order
    items = sorted([(a[i], b[i], i) for i in range(n)])
    
    # We'll try each possible maximum A_i value
    min_cost = float('inf')
    
    # Use a min-heap to maintain the smallest B_i values when we need to select k elements
    import heapq
    
    # For each position as the maximum A_i
    for i in range(k-1, n):
        max_a = items[i][0]
        
        # We must include items[i] since it's the current max
        # From indices 0 to i, we need to pick k-1 more items (total k including current)
        # We want to minimize sum of B_i, so we take the k-1 smallest B_i values from 0 to i
        
        if i == 0:  # k must be 1 here
            total_b = items[0][1]
            cost = max_a * total_b
            min_cost = min(min_cost, cost)
            continue
            
        # Get the k-1 smallest B values from items[0:i+1]
        b_values = [items[j][1] for j in range(i+1)]
        b_values.sort()
        selected_b_sum = sum(b_values[:k])
        
        cost = max_a * selected_b_sum
        min_cost = min(min_cost, cost)
    
    return int(min_cost)

def solve() -> None:
    input = sys.stdin.read
    data = input().split()
    
    t = int(data[0])
    index = 1
    results = []
    
    for _ in range(t):
        n = int(data[index])
        k = int(data[index + 1])
        index += 2
        
        a = list(map(int, data[index:index + n]))
        index += n
        
        b = list(map(int, data[index:index + n]))
        index += n
        
        result = solve_case(n, k, a, b)
        results.append(str(result))
    
    print('\n'.join(results))

if __name__ == "__main__":
    solve()