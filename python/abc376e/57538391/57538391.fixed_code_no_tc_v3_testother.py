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
        
        # We'll consider each element as the maximum A_i in the subset
        # Then we want to pick K-1 other elements with smallest B sum among those with A_i <= current A_i
        from heapq import heappush, heappop
        
        min_sum_heap = []  # max-heap using negative values to keep smallest B_i values
        current_b_sum = 0
        
        ans = float('inf')
        
        # Traverse from smallest to largest A_i
        for i in range(N):
            a_val, b_val = items[i]
            
            # Include current element
            if len(min_sum_heap) < K - 1:
                heappush(min_sum_heap, -b_val)
                current_b_sum += b_val
            else:
                # Maintain exactly K-1 smallest B values from previous elements
                if K > 1:
                    if b_val < -min_sum_heap[0]:
                        removed = -heappop(min_sum_heap)
                        heappush(min_sum_heap, -b_val)
                        current_b_sum = current_b_sum - removed + b_val
                # else K == 1, we don't need any other elements
                
            # If we have at least K-1 elements before or including this one, we can form a valid set
            if i >= K - 1:
                total_b_sum = current_b_sum + b_val
                candidate = a_val * total_b_sum
                ans = min(ans, candidate)
                
        results.append(str(ans))
    
    print("\n".join(results))

solve()