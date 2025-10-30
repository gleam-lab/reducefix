import sys

def solve():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    
    # Create list of (A_i, B_i) and sort by A_i
    items = sorted(zip(A, B), key=lambda x: x[0])
    
    # We'll try each possible max A_i in the subset S
    # Since we want to minimize (max_A) * (sum_B), we can fix the maximum A_i
    # and then choose up to K-1 additional elements with smaller or equal A_i
    # that maximize sum of B_i (but we must include at least one element with A_i = current)
    
    min_cost = float('inf')
    
    # Use a min-heap to maintain the K smallest (in terms of B_i) elements
    # Actually, we want to select K elements including current with largest possible B sum
    # So we'll use a min-heap to keep track of the smallest B values among selected ones
    
    from heapq import heappush, heappop
    
    # Try every position as the one that determines the max A_i
    # All selected items must have A_i <= current A_i
    # And at least one has A_i == current A_i
    
    # We'll iterate through items sorted by A_i
    # For each item i, consider it as the one setting max A_i
    # Then we can pick this item and up to K-1 other items from [0...i]
    
    # Maintain a min-heap of B values for the best K items so far
    heap = []
    b_sum = 0
    
    for i in range(N):
        a_val, b_val = items[i]
        
        # Include current item
        if len(heap) < K:
            heappush(heap, b_val)
            b_sum += b_val
        else:
            # If current B is larger than the smallest in our heap
            if b_val > heap[0]:
                removed = heappop(heap)
                heappush(heap, b_val)
                b_sum = b_sum - removed + b_val
            # Otherwise don't include it in our running set
        
        # If we have at least K items available up to index i
        if len(heap) == K:
            # Current a_val is the maximum A in our selected set
            cost = a_val * b_sum
            min_cost = min(min_cost, cost)
    
    return min_cost

def main():
    T = int(input())
    for _ in range(T):
        print(solve())

if __name__ == "__main__":
    main()