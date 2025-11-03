import sys

def solve():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    
    # Create list of (A_i, B_i) and sort by A_i
    items = [(A[i], B[i]) for i in range(N)]
    items.sort()
    
    # We'll try each possible value of max_A in the subset S
    # If we fix max_A = A[i], then we can only pick indices j with A[j] <= A[i]
    # And we must include at least one index with A[j] == A[i] to achieve this max
    # To minimize the product, for fixed max_A, we want to minimize sum_B
    
    from heapq import heappush, heappop
    
    min_sum = float('inf')
    
    # Consider each item as the one setting the maximum A value
    for i in range(K - 1, N):  # We need at least K items with A <= A[i], so start from K-1
        # Use a max-heap to maintain the smallest K B-values among items [0:i+1]
        heap = []
        total_b = 0
        
        # First, add all items from 0 to i
        for j in range(i + 1):
            a_val, b_val = items[j]
            if len(heap) < K:
                heappush(heap, -b_val)  # negative for max-heap
                total_b += b_val
            else:
                # If current B is smaller than the largest in heap, replace
                if b_val < -heap[0]:
                    removed = -heappop(heap)
                    heappush(heap, -b_val)
                    total_b = total_b - removed + b_val
                else:
                    # Skip this element
                    continue
        
        # We need exactly K elements
        if len(heap) == K:
            # The maximum A in our chosen set is items[i][0]
            # But note: we might not have included items[i] itself
            # So we need to ensure that the maximum A among selected items is <= items[i][0]
            # However, since we're iterating by sorted A, and we're considering position i,
            # we need to make sure that our selection includes an element with A >= some value
            # Actually, we want to consider items[i] as the maximum.
            
            # Let's revise: we'll force that the maximum A in our subset is exactly items[i][0]
            # So we must include at least one item with A = items[i][0]
            # But easier: try every i as the maximum, and consider all j <= i
            
            # Our current selection has K items from indices 0..i, so max A is <= items[i][0]
            # Since items are sorted by A, items[i][0] is the maximum possible A in this group
            # So the max_A in the expression is items[i][0]
            candidate = items[i][0] * total_b
            min_sum = min(min_sum, candidate)
    
    return min_sum

def main():
    input = sys.stdin.read
    data = input().split()
    
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
        
        result = solve()
        results.append(str(result))
    
    print('\n'.join(results))

if __name__ == '__main__':
    main()