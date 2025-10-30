import sys
from collections import deque

def main():
    H, W, Y = map(int, sys.stdin.readline().split())
    
    # Read elevation data
    A = []
    for _ in range(H):
        row = list(map(int, sys.stdin.readline().split()))
        A.append(row)
    
    # Directions for adjacent cells (up, down, left, right)
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    
    # Initialize the island area for each year
    result = []
    current_area = H * W
    
    # We'll simulate the flooding process using a priority queue (min-heap)
    # Start with all border cells since they are adjacent to the sea
    heap = []
    visited = [[False] * W for _ in range(H)]
    
    # Add all border cells to the heap
    for i in range(H):
        for j in range(W):
            if i == 0 or i == H-1 or j == 0 or j == W-1:
                heap.append((A[i][j], i, j))
                visited[i][j] = True
    
    # Heapify the list
    import heapq
    heapq.heapify(heap)
    
    # Process cells in order of increasing elevation
    # For each sea level rise from 1 to Y, count remaining land
    year = 1
    while heap and year <= Y:
        # All land with elevation <= 'year' will be submerged
        while heap and heap[0][0] <= year:
            elev, i, j = heapq.heappop(heap)
            current_area -= 1
            
            # Check all 4 adjacent neighbors
            for di, dj in directions:
                ni, nj = i + di, j + dj
                if 0 <= ni < H and 0 <= nj < W and not visited[ni][nj]:
                    visited[ni][nj] = True
                    heapq.heappush(heap, (A[ni][nj], ni, nj))
        
        result.append(current_area)
        year += 1
    
    # For years beyond when all possible flooding has occurred
    while year <= Y:
        result.append(current_area)
        year += 1
    
    # Output each year's result
    for res in result:
        print(res)

if __name__ == "__main__":
    main()