import sys

def solve():
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    T = int(data[index])
    index += 1
    
    results = []
    
    for _ in range(T):
        N = int(data[index])
        K = int(data[index + 1])
        index += 2
        
        A = list(map(int, data[index:index + N]))
        index += N
        
        B = list(map(int, data[index:index + N]))
        index += N
        
        # Create list of (A_i, B_i, i) and sort by A_i
        items = [(A[i], B[i], i) for i in range(N)]
        items.sort()
        
        min_cost = float('inf')
        
        # For each possible maximum A_i value in the subset
        for right in range(K - 1, N):
            # We must include items[right] to have A[right] as max
            current_A = items[right][0]
            
            # Collect B values from indices [0:right+1] and take K-1 smallest ones plus current
            candidates = []
            for i in range(right + 1):
                candidates.append(items[i][1])
            
            # Sort and take K smallest B values (including the current one)
            candidates.sort()
            total_B = sum(candidates[:K])
            
            cost = current_A * total_B
            min_cost = min(min_cost, cost)
        
        results.append(str(min_cost))
    
    print('\n'.join(results))

solve()