import sys
from collections import deque

def main():
    H, W, Y = map(int, sys.stdin.readline().split())
    A = []
    for _ in range(H):
        row = list(map(int, sys.stdin.readline().split()))
        A.append(row)
    
    # We want to compute the remaining area after each year (sea level = i)
    # Instead of simulating rising water, we simulate sinking from the borders inward
    # using a min-heap or BFS with priority by elevation.
    
    # Idea: Process cells in increasing order of elevation. 
    # Start from all border cells (they are exposed to sea).
    # Use a priority queue to process the lowest elevation first.
    # When sea level reaches 'year', any cell with elevation <= year that is connected
    # to the sea via <= year elevations will be submerged.
    
    visited = [[False] * W for _ in range(H)]
    heap = []
    
    # Directions for adjacent cells (up, down, left, right)
    directions = [(-1,0), (1,0), (0,-1), (0,1)]
    
    # Initialize the priority queue with all border cells
    for i in range(H):
        for j in range(W):
            if i == 0 or i == H-1 or j == 0 or j == W-1:
                heap.append((A[i][j], i, j))
                visited[i][j] = True
    
    # Min-heap
    import heapq
    heapq.heapify(heap)
    
    # To store result: area remaining at each year
    remaining = H * W  # initially full island
    results = []
    year_index = 1
    
    # Process cells in order of increasing elevation
    while heap and year_index <= Y:
        # All cells with elevation <= current sea level (year_index) should be removed
        while heap and heap[0][0] <= year_index:
            elev, i, j = heapq.heappop(heap)
            remaining -= 1
            
            # Check neighbors
            for di, dj in directions:
                ni, nj = i + di, j + dj
                if 0 <= ni < H and 0 <= nj < W and not visited[ni][nj]:
                    visited[ni][nj] = True
                    heapq.heappush(heap, (A[ni][nj], ni, nj))
        
        results.append(remaining)
        year_index += 1
    
    # If we finished early (no more cells to sink), remaining stays constant
    while len(results) < Y:
        results.append(remaining)
    
    # Output each result on separate line
    for res in results:
        print(res)

if __name__ == "__main__":
    main()