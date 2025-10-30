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
        
        # We'll try each possible max A_i value as the upper bound
        min_cost = float('inf')
        
        # Use a min-heap to maintain the K-1 smallest B_i values among candidates
        import heapq
        
        # Process from largest A_i down to smallest
        # For each position i, consider items[0..i] as candidates
        # Then max_A = items[i][0], and we need to choose K items from [0..i]
        
        # We'll go from left to right (increasing A_i), maintaining a max-heap of size K
        # Actually: better to iterate over possible maximums
        
        # Alternative approach:
        # For each i from K-1 to N-1 (so we have at least K elements up to i)
        # Let current max_A = items[i][0]
        # We must include item i (to make this the maximum)
        # Then choose K-1 items from items[0:i] with minimum sum of B_i
        
        heap = []  # max-heap using negative values to keep largest B_i at top
        current_sum = 0
        
        for i in range(N):
            a_val, b_val = items[i]
            
            if i < K:
                # Initially fill the heap
                heapq.heappush(heap, -b_val)
                current_sum += b_val
                if i == K - 1:
                    # We can form a valid set
                    cost = a_val * current_sum
                    min_cost = min(min_cost, cost)
            else:
                # We have K elements in heap
                # If current B is smaller than the largest in our selection
                if b_val < -heap[0]:
                    # Remove the largest B and add current
                    removed = -heapq.heappop(heap)
                    heapq.heappush(heap, -b_val)
                    current_sum = current_sum - removed + b_val
                
                # Now we have best K items from 0..i
                cost = a_val * current_sum
                min_cost = min(min_cost, cost)
        
        results.append(str(min_cost))
    
    print("\n".join(results))

solve()