import sys

def solve():
    data = sys.stdin.read().split()
    t = int(data[0])
    index = 1
    results = []
    
    for _ in range(t):
        N = int(data[index]); K = int(data[index+1]); index += 2
        A = list(map(int, data[index:index+N])); index += N
        B = list(map(int, data[index:index+N])); index += N
        
        # Create list of (A_i, B_i) and sort by A_i
        items = sorted(zip(A, B), key=lambda x: x[0])
        
        min_cost = float('inf')
        
        # We'll use a min-heap to maintain the smallest B_i values
        import heapq
        
        # First, consider each possible max_A = A[i] when including item i
        # We want to pick K items with A_j <= A[i], and maximize sum of B_j
        # But we are minimizing (max_A) * (sum_B)
        
        # Process items in increasing order of A_i
        b_heap = []  # max-heap for B values (using negative values)
        b_sum = 0
        
        for i in range(N):
            a_val, b_val = items[i]
            
            # Add current item
            heapq.heappush(b_heap, b_val)
            b_sum += b_val
            
            # If we have more than K items, remove the smallest B value
            if len(b_heap) > K:
                removed = heapq.heappop(b_heap)
                b_sum -= removed
            
            # If we have exactly K items, update answer
            if len(b_heap) == K:
                cost = a_val * b_sum
                min_cost = min(min_cost, cost)
        
        results.append(str(min_cost))
    
    print("\n".join(results))

solve()