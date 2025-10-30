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
        
        # Create list of (A_i, B_i) pairs and sort by A_i
        items = [(A[i], B[i]) for i in range(N)]
        items.sort()
        
        # We'll try each possible maximum A_i value
        min_cost = float('inf')
        
        # Use a min-heap to maintain the smallest B_i values among selected items
        import heapq
        
        # Precompute prefix sums of B for the first K elements when sorted by A
        # But we need to consider: for a fixed max_A = A[j], we want to pick K-1 other items 
        # from indices [0, j] with smallest B_i sum, plus item j
        
        # Process from left to right, maintaining a max-heap (using negative values) of size K-1
        heap = []  # max-heap using negative values
        b_sum = 0
        
        for j in range(N):
            a_val, b_val = items[j]
            
            if len(heap) < K - 1:
                heapq.heappush(heap, -b_val)
                b_sum += b_val
            else:
                # We have K-1 elements already
                if K == 1:
                    # Only take this element
                    cost = a_val * b_val
                    min_cost = min(min_cost, cost)
                else:
                    # Try using this element as the one with maximum A
                    cost = a_val * (b_sum + b_val)
                    min_cost = min(min_cost, cost)
                    
                    # Now add current b_val to our candidate set for future
                    if b_val < -heap[0]:
                        removed = -heapq.heappop(heap)
                        heapq.heappush(heap, -b_val)
                        b_sum = b_sum - removed + b_val
            
            # If we've collected K elements (including current), update cost
            if j >= K - 1:
                if K == 1:
                    cost = a_val * b_val
                    min_cost = min(min_cost, cost)
                elif len(heap) == K - 1:
                    cost = a_val * (b_sum + b_val)
                    min_cost = min(min_cost, cost)
        
        results.append(str(min_cost))
    
    print("\n".join(results))

solve()