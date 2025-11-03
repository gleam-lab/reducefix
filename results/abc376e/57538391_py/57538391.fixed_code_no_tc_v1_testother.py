import sys

def solve():
    data = sys.stdin.read().split()
    t = int(data[0])
    index = 1
    results = []
    
    for _ in range(t):
        N = int(data[index])
        K = int(data[index + 1])
        index += 2
        
        A = list(map(int, data[index:index + N]))
        index += N
        
        B = list(map(int, data[index:index + N]))
        index += N
        
        # Create list of (A_i, B_i) and sort by A_i
        items = sorted([(A[i], B[i]) for i in range(N)])
        
        # We'll try each possible maximum A_i value as the candidate for max(S)
        min_cost = float('inf')
        
        # Use a min-heap to maintain the smallest B_i values among selected items
        import heapq
        
        # Precompute prefix sums of B for the first K items when sorted by A
        # But we need to consider: fix max_A = A[j], then choose K-1 items from indices <= j with smallest B_i
        if K == 1:
            min_cost = min(A[i] * B[i] for i in range(N))
        else:
            # Process each position as potential maximum
            b_sum = 0
            heap = []  # max-heap using negative values
            
            for i in range(N):
                a_val, b_val = items[i]
                
                # Add current item
                if len(heap) < K - 1:
                    heapq.heappush(heap, b_val)
                    b_sum += b_val
                else:
                    # Maintain exactly K-1 smallest B values from indices [0, i-1]
                    if b_val < heap[-1] if heap else False:
                        # This comparison won't work directly with heap...
                        pass
            
            # Better approach: iterate from left to right, maintaining K-1 smallest B values
            heap = []
            b_sum = 0
            
            for i in range(N):
                a_val, b_val = items[i]
                
                # We can use this element as the one that sets the max A
                # So we need K-1 other elements from indices <= i with minimal sum of B
                if len(heap) >= K - 1:
                    # We already have at least K-1 elements before or including this one
                    total_b = b_sum + b_val
                    cost = a_val * total_b
                    min_cost = min(min_cost, cost)
                
                # Now add current b_val to our pool for future consideration
                if len(heap) < K - 1:
                    heapq.heappush(heap, -b_val)  # max-heap
                    b_sum += b_val
                else:
                    if b_val < -heap[0]:
                        removed = -heapq.heappop(heap)
                        heapq.heappush(heap, -b_val)
                        b_sum = b_sum - removed + b_val
                    else:
                        # Do not include it in the K-1 set
                        pass
        
        results.append(str(min_cost))
    
    print("\n".join(results))

solve()