import sys

def solve():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    
    # Pair elements by index and sort by A_i (the max contributor)
    items = sorted([(A[i], B[i]) for i in range(N)])
    
    # We'll try each possible maximum A_i in the subset S
    # Since we want to minimize (max_A) * (sum_B), we consider each element's A as candidate for max
    ans = float('inf')
    
    # Use a min-heap to maintain the smallest B values when selecting K elements
    import heapq
    prefix_sum = 0
    heap = []
    
    # Traverse from left to right (increasing A_i)
    for i in range(N):
        a_i, b_i = items[i]
        
        # Include current item
        heapq.heappush(heap, -b_i)  # use negative for max-heap behavior
        prefix_sum += b_i
        
        # If we have more than K elements in our candidate set, remove the one with largest B_i
        # Why largest B_i? Because we want to minimize sum of B_i, so we prefer smaller B_i.
        # But note: we are using negative values in heap -> popping the smallest negative means largest positive
        if len(heap) > K:
            removed_b = -heapq.heappop(heap)
            prefix_sum -= removed_b
        
        # Once we have exactly K elements, update answer
        if len(heap) == K:
            # Current a_i is the maximum A in the selected subset (since sorted by A)
            ans = min(ans, a_i * prefix_sum)
    
    return ans

# Read number of test cases
T = int(input())
for _ in range(T):
    print(solve())