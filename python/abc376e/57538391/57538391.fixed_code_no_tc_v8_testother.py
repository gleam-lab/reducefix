import sys

def solve():
    input = sys.stdin.read
    data = input().split()
    
    idx = 0
    T = int(data[idx])
    idx += 1
    results = []
    
    for _ in range(T):
        N = int(data[idx])
        K = int(data[idx + 1])
        idx += 2
        A = list(map(int, data[idx:idx + N]))
        idx += N
        B = list(map(int, data[idx:idx + N]))
        idx += N
        
        # Create list of (A_i, B_i) and sort by A_i
        items = sorted(zip(A, B))
        
        # We want to minimize (max_A_in_S) * (sum_B_in_S)
        # Idea: fix the maximum A_i in the subset S, then choose K-1 other elements 
        # from indices with A_i <= current A_i, prioritizing smaller B_i
        
        min_cost = float('inf')
        
        # Use a max-heap (simulated with negative values) to maintain the K smallest B_i values
        import heapq
        heap = []  # max-heap for B values (store negative)
        b_sum = 0
        
        # Traverse items in increasing order of A_i
        for i in range(N):
            a_val, b_val = items[i]
            
            # Push current B value
            if len(heap) < K:
                heapq.heappush(heap, -b_val)
                b_sum += b_val
            else:
                # If current B is smaller than the largest in heap, replace it
                if b_val < -heap[0]:
                    removed = -heapq.heappop(heap)
                    heapq.heappush(heap, -b_val)
                    b_sum = b_sum - removed + b_val
                else:
                    # Need to include this element because max A is fixed to a_val
                    # So we must have exactly K elements up to index i
                    # But we can't fit without removing one, so try to add and remove largest
                    heapq.heappush(heap, -b_val)
                    removed = -heapq.heappop(heap)
                    b_sum += b_val - removed
            
            # If we have at least K elements up to this point
            if i >= K - 1:
                cost = a_val * b_sum
                min_cost = min(min_cost, cost)
        
        results.append(str(min_cost))
    
    print('\n'.join(results))

solve()