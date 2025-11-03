import sys
import bisect

def main():
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])
    X = list(map(int, data[1:1 + N]))
    P = list(map(int, data[1 + N:1 + 2 * N]))
    
    # Create the prefix sum array
    prefix = [0] * (N + 1)  # One extra to avoid index bound issues
    for i in range(N):
        prefix[i + 1] = prefix[i] + P[i]
    
    # Handle the queries
    results = []
    query_start_index = 1 + 2 * N
    for i in range(Q):
        Li = int(data[query_start_index + 2 * i])
        Ri = int(data[query_start_index + 2 * i + 1])
        
        left_index = bisect.bisect_left(X, Li)
        right_index = bisect.bisect_right(X, Ri)
        
        total_villagers = prefix[right_index] - prefix[left_index]
        results.append(total_villagers)
    
    # Print all results for the queries
    sys.stdout.write('\n'.join(map(str, results)) + '\n')

if __name__ == "__main__":
    main()