import heapq as hq
import sys

def main():
    H, W, Y = map(int, sys.stdin.readline().split())
    
    # Read the elevation matrix
    A = []
    for _ in range(H):
        row = list(map(int, sys.stdin.readline().split()))
        A.append(row)
    
    # Priority queue to process cells in order of elevation
    heap = []
    
    # Directions for adjacent cells (up, down, left, right)
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    
    # Mark boundary cells and add them to the heap
    visited = [[False] * W for _ in range(H)]
    
    # Add all boundary cells to the heap
    for i in range(H):
        for j in range(W):
            if i == 0 or i == H-1 or j == 0 or j == W-1:
                visited[i][j] = True
                heapq.heappush(heap, (A[i][j], i, j))
    
    # Track when each cell gets submerged
    submerge_year = [[float('inf')] * W for _ in range(H)]
    
    # Process the heap
    while heap:
        elev, i, j = heapq.heappop(heap)
        
        # This cell gets submerged at year = elev (since sea level rises by 1 per year)
        # But it can only be reached/submerged at max(elev, earliest time we can reach it)
        current_level = elev
        
        # Update neighbors
        for di, dj in directions:
            ni, nj = i + di, j + dj
            if 0 <= ni < H and 0 <= nj < W and not visited[ni][nj]:
                # The water can flow to this neighbor if its elevation <= current sea level
                # When we reach a cell, it gets submerged at max(neighbor's elevation, current_level)
                future_level = max(A[ni][nj], current_level)
                visited[ni][nj] = True
                submerge_year[ni][nj] = future_level
                heapq.heappush(heap, (future_level, ni, nj))
    
    # Count remaining area for each year
    # Initially all cells are above water
    remaining = H * W
    
    # For each year from 1 to Y, calculate remaining area
    result = []
    
    # Create an array to count how many cells get submerged at each year
    submerged_count = [0] * (max(Y, 100000) + 2)  # Be safe with size
    
    # Boundary cells are already in the heap, but we need to account for their submergence
    for i in range(H):
        for j in range(W):
            # Cells that are on boundary get submerged at their own elevation
            # Non-boundary cells get submerged at submerge_year[i][j]
            level = A[i][j] if (i == 0 or i == H-1 or j == 0 or j == W-1) else submerge_year[i][j]
            if level <= Y:
                submerged_count[level] += 1
    
    # Calculate remaining area for each year
    for year in range(1, Y + 1):
        remaining -= submerged_count[year]
        result.append(str(remaining))
    
    # Output each result on separate line
    print('\n'.join(result))

if __name__ == '__main__':
    main()