import heapq
import sys

def main():
    H, W, Y = map(int, sys.stdin.readline().split())
    
    # Read the grid
    A = []
    for _ in range(H):
        row = list(map(int, sys.stdin.readline().split()))
        A.append(row)
    
    # Initialize visited array and result array
    visited = [[False] * W for _ in range(H)]
    result = [H * W] * (Y + 1)  # result[i] will store area after i years
    
    # Priority queue for Dijkstra-like algorithm
    # We'll process cells in order of increasing elevation
    pq = []
    
    # Add all border cells to the priority queue
    for i in range(H):
        for j in range(W):
            if i == 0 or i == H-1 or j == 0 or j == W-1:
                heapq.heappush(pq, (A[i][j], i, j))
                visited[i][j] = True
    
    # Directions for adjacent cells (up, down, left, right)
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    
    # Process cells in order of increasing elevation
    while pq:
        elevation, i, j = heapq.heappop(pq)
        
        # For each year up to the current elevation, decrease the area
        # The cell (i,j) gets submerged at year = elevation
        for year in range(1, min(elevation + 1, Y + 1)):
            result[year] -= 1
        
        # Explore neighbors
        for di, dj in directions:
            ni, nj = i + di, j + dj
            if 0 <= ni < H and 0 <= nj < W and not visited[ni][nj]:
                visited[ni][nj] = True
                heapq.heappush(pq, (A[ni][nj], ni, nj))
    
    # Print results for years 1 to Y
    for i in range(1, Y + 1):
        print(result[i])

if __name__ == "__main__":
    main()