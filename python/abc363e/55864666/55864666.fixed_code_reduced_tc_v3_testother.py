import sys
import heapq as hq

def main():
    H, W, Y = map(int, sys.stdin.readline().split())
    
    # Read the elevation matrix
    A = []
    for _ in range(H):
        row = list(map(int, sys.stdin.readline().split()))
        A.append(row)
    
    # We'll process cells in increasing order of elevation using a min-heap
    heap = []
    visited = [[False] * W for _ in range(H)]
    
    # Add all border cells to the heap
    for i in range(H):
        for j in range(W):
            if i == 0 or i == H-1 or j == 0 or j == W-1:
                heap.append((A[i][j], i, j))
                visited[i][j] = True
    
    hq.heapify(heap)
    
    # Array to store area remaining after each year
    result = [H * W] * (Y + 1)  # result[i] = area after i years
    
    # Process cells in order of increasing elevation
    while heap:
        elevation, i, j = hq.heappop(heap)
        
        # For each year up to this cell's elevation, this cell will be submerged
        # So we decrement the area for all years >= elevation
        if elevation <= Y:
            for year in range(elevation, Y + 1):
                result[year] -= 1
        
        # Check neighbors
        for ni, nj in [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]:
            if 0 <= ni < H and 0 <= nj < W and not visited[ni][nj]:
                visited[ni][nj] = True
                hq.heappush(heap, (A[ni][nj], ni, nj))
    
    # Output the results for years 1 to Y
    for i in range(1, Y + 1):
        print(result[i])

if __name__ == "__main__":
    main()