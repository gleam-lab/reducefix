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
        
        # We'll consider each element as the maximum A_i in the subset
        # Then we want to pick up to K-1 other elements with smaller or equal A_i
        # that have the smallest possible sum of B_i, but we must include current
        
        from heapq import heappush, heappop
        
        # Forward approach: try fixing max A_i
        min_cost = float('inf')
        
        # We traverse each possible candidate for max A_i
        # For each i, we consider items[0..i] as available
        # We need to choose K items from [0..i], including i
        # To minimize sum(B), we should take the K-1 smallest B values among [0..i-1]
        
        if K == 1:
            # Just pick one element
            for a, b in items:
                min_cost = min(min_cost, a * b)
        else:
            # Use a max-heap to maintain the K-1 smallest B values
            heap = []  # max-heap using negative values
            total_b = 0
            
            # Traverse items in increasing order of A_i
            for i in range(N):
                a_i, b_i = items[i]
                
                # Include current item as the one with max A
                # We need K-1 items from indices [0, i-1]
                if i >= K - 1:
                    # We can form a valid set
                    current_sum_b = total_b + b_i
                    current_cost = a_i * current_sum_b
                    min_cost = min(min_cost, current_cost)
                
                # Add current b_i to the heap for future consideration
                if len(heap) < K - 1:
                    heappush(heap, -b_i)
                    total_b += b_i
                else:
                    # Only add if it's smaller than the largest in heap
                    if K > 1 and b_i < -heap[0]:
                        removed = -heappop(heap)
                        heappush(heap, -b_i)
                        total_b = total_b - removed + b_i
                    # Otherwise ignore this B value since it's too large
        
        results.append(str(min_cost))
    
    print("\n".join(results))

solve()