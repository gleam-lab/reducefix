import sys
from collections import deque

def main():
    H, W, Y = map(int, sys.stdin.readline().split())
    
    # Read elevation matrix
    A = []
    for _ in range(H):
        row = list(map(int, sys.stdin.readline().split()))
        A.append(row)
    
    # Initialize result array for each year
    result = [H * W] * Y  # Area remaining after i years (1-indexed)
    
    # We'll simulate the flooding process using a BFS from the borders
    # Instead of simulating year by year (too slow), we precompute when each cell gets flooded
    
    # Priority queue: (elevation_threshold, row, col)
    heap = []
    visited = [[False] * W for _ in range(H)]
    
    # Add all border cells to the priority queue
    # These are the first points where sea enters
    for i in range(H):
        for j in range(W):
            if i == 0 or i == H-1 or j == 0 or j == W-1:
                visited[i][j] = True
                # The year when this cell drowns is min(A[i][j], Y) but we store threshold
                # Cell drowns at year = A[i][j] if no earlier path exists
                heap.append((A[i][j], i, j))
    
    import heapq
    heapq.heapify(heap)
    
    # Directions for adjacent moves (up, down, left, right)
    directions = [(0,1), (0,-1), (1,0), (-1,0)]
    
    # Process cells in order of increasing "flooding time"
    # Flooding time of a cell = minimum sea level at which it becomes submerged
    # This is determined by the lowest-elevation path from the sea
    while heap:
        elev, i, j = heapq.heappop(heap)
        
        # This cell gets flooded at 'elev' years
        # So from year 'elev' onward, it's underwater
        if elev <= Y:
            # All years from elev to Y have one less area
            for y in range(elev, Y):
                result[y] -= 1
        
        # Propagate to neighbors
        for di, dj in directions:
            ni, nj = i + di, j + dj
            if 0 <= ni < H and 0 <= nj < W and not visited[ni][nj]:
                visited[ni][nj] = True
                # The flooding time for neighbor is max(current flooding level, its own elevation)
                # Because water can only flow over it when sea level reaches at least its elevation
                # But water comes through current path with threshold 'elev'
                # So actual flooding threshold is max(elev, A[ni][nj])
                new_elev = max(elev, A[ni][nj])
                heapq.heappush(heap, (new_elev, ni, nj))
    
    # Output results for each year 1..Y
    for i in range(Y):
        print(result[i])

if __name__ == "__main__":
    main()