import sys
from collections import deque

def main():
    H, W, Y = map(int, sys.stdin.readline().split())
    A = []
    for _ in range(H):
        row = list(map(int, sys.stdin.readline().split()))
        A.append(row)
    
    # We'll simulate the flooding process using BFS from the borders
    # For each year i (sea level = i), we want to know how many cells remain above water
    
    # Instead of simulating year by year (which would be too slow), we can:
    # - Use a priority queue or sort all cells by elevation
    # - Process cells in increasing order of elevation and simulate flooding
    # - Record when each cell gets flooded
    
    # Each cell gets flooded when sea level >= its effective flooding threshold
    # However, due to connectivity: a cell floods when sea level >= its own height
    # AND it is connected to the ocean via cells with height <= sea level
    
    # Idea: start from border cells and flood inward. The time a cell drowns is
    # the minimum sea level at which there's a path from the ocean to that cell
    # through cells of height <= sea level.
    
    # We can use Dijkstra-like algorithm:
    # Let flood_time[i][j] = minimum sea level at which (i,j) becomes submerged
    # Initially, all border cells have flood_time = A[i][j]
    # Then we propagate: from a cell (i,j), neighbor (ni,nj) will flood at max(A[ni][nj], flood_time[i][j])
    # Because: to reach (ni,nj), the sea must be high enough to flood the path up to (i,j) AND cover (ni][nj]
    
    INF = 10**9
    flood_time = [[INF] * W for _ in range(H)]
    heap = []
    
    # Directions for adjacent moves (up, down, left, right)
    directions = [(0,1), (0,-1), (1,0), (-1,0)]
    
    # Initialize border cells
    for i in range(H):
        for j in range(W):
            if i == 0 or i == H-1 or j == 0 or j == W-1:
                flood_time[i][j] = A[i][j]
                heap.append((A[i][j], i, j))
    
    # Convert list to heap
    import heapq
    heapq.heapify(heap)
    
    # Dijkstra-style propagation
    while heap:
        t, i, j = heapq.heappop(heap)
        if t != flood_time[i][j]:
            continue
            
        for di, dj in directions:
            ni, nj = i + di, j + dj
            if 0 <= ni < H and 0 <= nj < W:
                # The new flooding time for neighbor is max(current cell's flood time, neighbor's height)
                new_time = max(t, A[ni][nj])
                if new_time < flood_time[ni][nj]:
                    flood_time[ni][nj] = new_time
                    heapq.heappush(heap, (new_time, ni, nj))
    
    # Count how many cells survive after each year
    # After i years, sea level = i
    # A cell survives if flood_time[i][j] > i
    survival_count = [0] * (Y + 2)  # survival_count[t] = number of cells that flood at time t
    
    total_cells = H * W
    for i in range(H):
        for j in range(W):
            t = flood_time[i][j]
            if t <= Y:
                survival_count[t] += 1
            # Cells that never flood within Y years will not be counted in any survival_count[t] for t<=Y
    
    # Now compute remaining area for each year
    remaining = total_cells
    result = []
    for year in range(1, Y + 1):
        remaining -= survival_count[year]
        result.append(str(remaining))
    
    print('\n'.join(result))

if __name__ == "__main__":
    main()