import sys
from typing import List, Tuple

def solve_case(n: int, k: int, a: List[int], b: List[int]) -> int:
    # Create list of (A_i, B_i, index) and sort by A_i
    items = [(a[i], b[i], i) for i in range(n)]
    items.sort()
    
    # We'll try each possible maximum A_i value
    min_cost = float('inf')
    
    # Use a min-heap to maintain the smallest B_i values
    import heapq
    
    for i in range(k - 1, n):
        # Current maximum A value is items[i][0]
        max_a = items[i][0]
        
        # We need to select k elements from items[0] to items[i]
        # Choose the ones with largest B values to minimize sum * max_a
        
        # Extract B values from first i+1 items
        b_vals = [items[j][1] for j in range(i + 1)]
        b_vals.sort(reverse=True)  # Sort in descending order
        
        # Take the k largest B values
        sum_b = sum(b_vals[:k])
        
        cost = max_a * sum_b
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