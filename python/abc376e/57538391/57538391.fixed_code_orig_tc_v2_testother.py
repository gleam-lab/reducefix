import sys

def solve():
    import sys
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
        
        # Create list of (A_i, B_i, index) and sort by A_i
        items = [(A[i], B[i], i) for i in range(N)]
        items.sort()
        
        # We'll try each possible maximum A_i value
        min_cost = float('inf')
        
        # Use a min-heap to maintain the K-1 smallest B values among items with A_i <= current A_i
        import heapq
        heap = []  # max-heap using negative values
        sum_b = 0
        
        # Process items in increasing order of A_i
        for i in range(N):
            a_val, b_val, orig_idx = items[i]
            
            # Add current item's B value
            if len(heap) < K - 1:
                heapq.heappush(heap, b_val)
                sum_b += b_val
            else:
                if K == 1:
                    # Special case: only one element needed
                    cost = a_val * b_val
                    min_cost = min(min_cost, cost)
                else:
                    # We have K-1 elements in heap, consider current as the one with max A_i
                    cost = a_val * (sum_b + b_val)
                    min_cost = min(min_cost, cost)
                    
                    # Add current element to heap if it's smaller than the largest in heap
                    if heap and b_val < heap[0]:
                        removed = heapq.heappop(heap)
                        heapq.heappush(heap, b_val)
                        sum_b = sum_b - removed + b_val
                    # If we don't add it, just continue
        
        # For K=1 case, we need to handle it separately since the above loop doesn't cover it properly
        if K == 1:
            for i in range(N):
                cost = A[i] * B[i]
                min_cost = min(min_cost, cost)
        
        results.append(str(min_cost))
    
    print('\n'.join(results))

solve()