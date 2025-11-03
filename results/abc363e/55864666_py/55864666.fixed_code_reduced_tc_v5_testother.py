import heapq
import sys

def main():
    H, W, Y = map(int, sys.stdin.readline().split())
    
    # Read the elevation matrix
    A = []
    for _ in range(H):
        row = list(map(int, sys.stdin.readline().split()))
        A.append(row)
    
    # We'll use a min-heap to simulate the rising sea level
    # Start from the border cells and propagate inward
    heap = []
    visited = [[False] * W for _ in range(H)]
    
    # Add all border cells to the heap
    for i in range(H):
        for j in range(W):
            if i == 0 or i == H-1 or j == 0 or j == W-1:
                heapq.heappush(heap, (A[i][j], i, j))
                visited[i][j] = True
    
    # Array to store when each cell gets submerged
    submerge_year = [[float('inf')] * W for _ in range(H)]
    
    # Directions for adjacent cells (up, down, left, right)
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    
    # Process cells in order of their elevation
    while heap:
        elev, i, j = heapq.heappop(heap)
        submerge_year[i][j] = elev
        
        # Check neighbors
        for di, dj in directions:
            ni, nj = i + di, j + dj
            if 0 <= ni < H and 0 <= nj < W and not visited[ni][nj]:
                visited[ni][nj] = True
                # The water can reach this cell at level max(elev, A[ni][nj])
                # But since we're using a min-heap, we push the actual elevation
                heapq.heappush(heap, (max(elev, A[ni][nj]), ni, nj))
    
    # Count remaining area for each year
    total_cells = H * W
    submerged_count = 0
    result = []
    
    # For each year from 1 to Y
    for year in range(1, Y + 1):
        # All cells with submerge_year <= year are submerged
        while submerged_count < total_cells:
            # Find next cell to submerge
            min_year = float('inf')
            min_pos = None
            
            # This approach would be too slow, so let's restructure
            break
        
        # Let's take a different approach - precompute the count
        pass
    
    # Better approach: create an array of how many cells get submerged at each year
    count_submerged_at_year = [0] * (Y + 2)  # index by year
    
    for i in range(H):
        for j in range(W):
            year_submerged = submerge_year[i][j]
            if year_submerged <= Y:
                count_submerged_at_year[year_submerged] += 1
            elif year_submerged > Y:
                # This cell never submerges within our timeframe
                pass
    
    # Calculate cumulative submerged cells
    total_submerged = 0
    for year in range(1, Y + 1):
        total_submerged += count_submerged_at_year[year]
        remaining = total_cells - total_submerged
        result.append(remaining)
    
    # Output results
    for r in result:
        print(r)

if __name__ == "__main__":
    main()