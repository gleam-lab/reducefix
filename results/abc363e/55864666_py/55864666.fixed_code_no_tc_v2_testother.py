import sys
from collections import deque

def main():
    H, W, Y = map(int, sys.stdin.readline().split())
    A = []
    for _ in range(H):
        row = list(map(int, sys.stdin.readline().split()))
        A.append(row)
    
    # We'll simulate the flooding process using a BFS from the borders
    # Instead of simulating year by year (which would be too slow),
    # we precompute for each cell the year when it gets flooded.
    
    # Initialize a 2D array to store the earliest sea level at which each cell is submerged
    flood_year = [[-1] * W for _ in range(H)]
    
    # Priority queue (min-heap) for Dijkstra-like algorithm: (elevation_threshold, row, col)
    heap = []
    
    # Directions for adjacent cells (up, down, left, right)
    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    
    # Initialize the border cells - they are adjacent to the sea
    for i in range(H):
        for j in range(W):
            if i == 0 or i == H-1 or j == 0 or j == W-1:
                # The sea level needed to flood this border cell is A[i][j]
                # So it floods at year = A[i][j] (since sea level rises 1 per year)
                hq.heappush(heap, (A[i][j], i, j))
                flood_year[i][j] = A[i][j]
    
    # Dijkstra-like propagation: water flows inward through lowest elevation paths
    while heap:
        level, i, j = hq.heappop(heap)
        if flood_year[i][j] != level:
            continue
            
        for di, dj in directions:
            ni, nj = i + di, j + dj
            if 0 <= ni < H and 0 <= nj < W and flood_year[ni][nj] == -1:
                # Water can flow from current cell to neighbor if neighbor's elevation <= path threshold
                # The effective flood level for the neighbor is max(A[ni][nj], level)
                new_level = max(A[ni][nj], level)
                flood_year[ni][nj] = new_level
                hq.heappush(heap, (new_level, ni, nj))
    
    # Count how many cells remain above water at each year
    # area[i] = number of cells with flood_year > i
    count = [0] * (Y + 2)  # index from 0 to Y+1
    
    total_cells = H * W
    for i in range(H):
        for j in range(W):
            year_flooded = flood_year[i][j]
            if year_flooded <= Y:
                count[year_flooded] += 1
            # If year_flooded > Y, it never floods within our observation period
    
    # Compute remaining area for each year
    remaining = total_cells
    result = []
    for year in range(1, Y + 1):
        remaining -= count[year]
        result.append(str(remaining))
    
    print('\n'.join(result))

if __name__ == '__main__':
    import heapq as hq
    main()