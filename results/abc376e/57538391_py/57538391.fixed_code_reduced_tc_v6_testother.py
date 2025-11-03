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
        items = sorted(zip(A, B), key=lambda x: x[0])
        
        # We want to minimize (max_A_in_S) * (sum_B_in_S)
        # Idea: fix the maximum A_i in the subset S, then choose K-1 other elements 
        # from indices with A_i <= current A_i, prioritizing smaller B_i values
        
        # Use a min-heap to maintain the smallest B_i values among candidates
        import heapq
        
        # Precompute prefix sums of B for smallest K-1 values?
        # Instead: iterate through sorted items, maintaining a max-heap (or use min-heap with negatives) 
        # of size K-1 for the smallest B_i values seen so far
        
        # Actually: we'll consider each element as the one that sets max A_i
        # Then we need to pick K-1 elements from previous ones (with A_i <= current) with smallest sum of B_i
        # So maintain a max-heap (using negative values) of up to K-1 smallest B_i's
        
        if K == 1:
            ans = float('inf')
            for i in range(N):
                ans = min(ans, A[i] * B[i])
            results.append(str(ans))
            continue
            
        # Max-heap to store the largest B_i among the smallest K-1 values
        heap = []  # will store negative values to simulate max-heap
        sum_b = 0
        ans = float('inf')
        
        for i in range(N):
            a_i, b_i = items[i]
            
            # If we have less than K-1 elements, just add this one
            if len(heap) < K - 1:
                heapq.heappush(heap, -b_i)
                sum_b += b_i
            else:
                # We already have K-1 elements
                # If this B_i is smaller than the largest in our heap, replace it
                if b_i < -heap[0]:
                    removed_b = -heapq.heappop(heap)
                    heapq.heappush(heap, -b_i)
                    sum_b = sum_b - removed_b + b_i
                # else ignore this element for now (not part of best K-1)
            
            # Now if we have exactly K-1 elements, we can form a valid set with current item
            if len(heap) == K - 1:
                total_sum_b = sum_b + b_i
                candidate = a_i * total_sum_b
                ans = min(ans, candidate)
        
        results.append(str(ans))
    
    print("\n".join(results))

solve()