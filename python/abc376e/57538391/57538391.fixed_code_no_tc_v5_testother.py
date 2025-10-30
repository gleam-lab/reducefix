import sys

def solve():
    T = int(sys.stdin.readline())
    
    for _ in range(T):
        N, K = map(int, sys.stdin.readline().split())
        A = list(map(int, sys.stdin.readline().split()))
        B = list(map(int, sys.stdin.readline().split()))
        
        # Create list of (A_i, B_i) and sort by A_i
        items = [(A[i], B[i]) for i in range(N)]
        items.sort()
        
        # We'll try each possible maximum A_i value
        # For a fixed max_A = items[i][0], we can only use indices <= i
        # We want to choose K items from [0, i] with minimal sum of B_i
        
        ans = float('inf')
        
        # Use a min-heap to maintain the largest K B values among first i+1 items
        import heapq
        heap = []  # max-heap using negative values
        b_sum = 0
        
        for i in range(N):
            a_val, b_val = items[i]
            
            # Add current B value
            if len(heap) < K:
                heapq.heappush(heap, b_val)
                b_sum += b_val
            else:
                # If current B value is smaller than the largest in our selection,
                # replace the largest with current
                if b_val < heap[0]:
                    removed = heapq.heappop(heap)
                    heapq.heappush(heap, b_val)
                    b_sum = b_sum - removed + b_val
                # Otherwise, don't include this item since we already have K smaller ones
            
            # If we have exactly K items, update answer
            if len(heap) == K:
                current_score = a_val * b_sum
                ans = min(ans, current_score)
        
        print(ans)

solve()