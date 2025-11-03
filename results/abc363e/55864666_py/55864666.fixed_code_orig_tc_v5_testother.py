import heapq
import sys

def main():
    H, W, Y = map(int, sys.stdin.readline().split())
    
    # Read the grid
    A = []
    for _ in range(H):
        row = list(map(int, sys.stdin.readline().split()))
        A.append(row)
    
    # Initialize visited array and priority queue
    visited = [[False] * W for _ in range(H)]
    heap = []
    
    # Add all border cells to the heap with their elevation
    for i in range(H):
        for j in range(W):
            if i == 0 or i == H-1 or j == 0 or j == W-1:
                heapq.heappush(heap, (A[i][j], i, j))
                visited[i][j] = True
    
    # Array to store the area at each year
    result = [H * W] * (Y + 1)
    remaining = H * W
    
    # Process cells in order of increasing elevation
    while heap:
        elevation, i, j = heapq.heappop(heap)
        
        # For each year up to this cell's elevation, decrease the area
        # This cell gets submerged when sea level reaches its elevation
        year = min(elevation, Y)
        for y in range(1, year + 1):
            result[y] -= 1
        
        # Check neighbors
        for di, dj in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            ni, nj = i + di, j + dj
            if 0 <= ni < H and 0 <= nj < W and not visited[ni][nj]:
                # If neighbor has lower or equal elevation, it will also be submerged
                # We set its effective elevation to max(current_elevation, its own elevation)
                # This ensures water flows over low areas
                effective_elevation = max(elevation, A[ni][nj])
                heapq.heappush(heap, (effective_elevation, ni, nj))
                visited[ni][nj] = True
    
    # Output results for years 1 to Y
    for i in range(1, Y + 1):
        print(result[i])

if __name__ == "__main__":
    main()