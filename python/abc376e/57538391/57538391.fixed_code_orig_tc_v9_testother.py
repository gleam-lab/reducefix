import sys
from typing import List, Tuple

def solve_case(n: int, k: int, a: List[int], b: List[int]) -> int:
    # Create list of (A_i, B_i, index) and sort by A_i
    items = [(a[i], b[i], i) for i in range(n)]
    items.sort()
    
    # We'll try each possible maximum A_i value
    min_cost = float('inf')
    
    # Use a min-heap to maintain the smallest B_i values when we need to remove elements
    import heapq
    
    for max_idx in range(k - 1, n):
        # Current maximum A value is items[max_idx][0]
        current_a = items[max_idx][0]
        
        # Collect B values from indices 0 to max_idx
        candidates = [items[i][1] for i in range(max_idx + 1)]
        
        # If we have exactly k items, use them
        if len(candidates) == k:
            total_b = sum(candidates)
            cost = current_a * total_b
            min_cost = min(min_cost, cost)
        else:
            # Take the k smallest B values from the first max_idx+1 items
            candidates.sort()
            total_b = sum(candidates[:k])
            cost = current_a * total_b
            min_cost = min(min_cost, cost)
    
    return min_cost

def main():
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
    main()