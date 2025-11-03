import sys
import heapq

def main():
    H, W, Y = map(int, sys.stdin.readline().split())
    
    # Read elevation data
    A = []
    for _ in range(H):
        row = list(map(int, sys.stdin.readline().split()))
        A.append(row)
    
    # Priority queue for processing cells by elevation
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
    
    # Process cells in order of increasing elevation
    while heap:
        elev, i, j = heapq.heappop(heap)
        
        # The year when this cell gets submerged
        year = max(elev, submerge_year[i][j])
        if submerge_year[i][j] == float('inf'):
            submerge_year[i][j] = elev
        
        # Check neighbors
        for di, dj in directions:
            ni, nj = i + di, j + dj
            if 0 <= ni < H and 0 <= nj < W and not visited[ni][nj]:
                # The neighbor will be submerged at max(current_cell_submerge_year, neighbor_elevation)
                # But it can't be submerged before its own elevation
                future_submerge = max(year, A[ni][nj])
                submerge_year[ni][nj] = min(submerge_year[ni][nj], future_submerge)
                
                visited[ni][nj] = True
                heapq.heappush(heap, (A[ni][nj], ni, nj))
    
    # Count remaining area for each year
    total_cells = H * W
    result = [total_cells] * (Y + 1)  # result[i] = area after i years
    
    # For each cell, subtract it from areas for years >= its submerge year
    for i in range(H):
        for j in range(W):
            submerge = submerge_year[i][j]
            if submerge <= Y:
                for year in range(submerge, Y + 1):
                    result[year] -= 1
    
    # Output results for years 1 to Y
    for i in range(1, Y + 1):
        print(result[i])

if __name__ == "__main__":
    main()