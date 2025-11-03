import heapq
import sys

def main():
    H, W, Y = map(int, sys.stdin.readline().split())
    
    # Read the grid
    A = []
    for _ in range(H):
        row = list(map(int, sys.stdin.readline().split()))
        A.append(row)
    
    # Initialize variables
    total_cells = H * W
    remaining = total_cells
    results = [0] * (Y + 1)
    results[0] = total_cells
    
    # Priority queue for processing cells in order of elevation
    heap = []
    
    # Mark boundary cells and add them to the heap
    visited = [[False] * W for _ in range(H)]
    
    # Add all boundary cells to the heap
    for i in range(H):
        for j in range(W):
            if i == 0 or i == H-1 or j == 0 or j == W-1:
                heapq.heappush(heap, (A[i][j], i, j))
                visited[i][j] = True
    
    # Directions for adjacent cells (up, down, left, right)
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    
    # Process cells in order of increasing elevation
    for year in range(1, Y + 1):
        # Process all cells with elevation <= current sea level (year)
        while heap and heap[0][0] <= year:
            elevation, i, j = heapq.heappop(heap)
            
            # Check all adjacent cells
            for di, dj in directions:
                ni, nj = i + di, j + dj
                if 0 <= ni < H and 0 <= nj < W and not visited[ni][nj]:
                    visited[ni][nj] = True
                    remaining -= 1
                    # If the adjacent cell's elevation is <= current sea level,
                    # it will also sink, so we process it immediately
                    if A[ni][nj] <= year:
                        heapq.heappush(heap, (A[ni][nj], ni, nj))
                    else:
                        # Otherwise, add it to the heap for future years
                        heapq.heappush(heap, (A[ni][nj], ni, nj))
        
        results[year] = remaining
    
    # Output results for years 1 to Y
    for i in range(1, Y + 1):
        print(results[i])

if __name__ == "__main__":
    main()