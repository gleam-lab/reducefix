import sys
import heapq

def main():
    H, W, Y = map(int, sys.stdin.readline().split())
    
    # Read the elevation data
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
                visited[i][j] = True
                heapq.heappush(heap, (A[i][j], i, j))
    
    # Array to store remaining area after each year
    result = [H * W] * (Y + 1)  # result[i] = area after i years
    
    # Process cells in order of increasing elevation
    while heap:
        elevation, i, j = heapq.heappop(heap)
        
        # For each year up to this cell's elevation, decrease the area
        # This cell will be submerged when sea level >= elevation
        year = min(elevation, Y)
        for y in range(1, year + 1):
            result[y] -= 1
        
        # Check neighbors
        for di, dj in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            ni, nj = i + di, j + dj
            if 0 <= ni < H and 0 <= nj < W and not visited[ni][nj]:
                visited[ni][nj] = True
                heapq.heappush(heap, (A[ni][nj], ni, nj))
    
    # Output results for years 1 to Y
    for i in range(1, Y + 1):
        print(result[i])

if __name__ == "__main__":
    main()