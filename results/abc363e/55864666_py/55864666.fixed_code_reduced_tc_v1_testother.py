import sys
import heapq as hq

def main():
    H, W, Y = map(int, sys.stdin.readline().split())
    
    # Read the elevation matrix
    A = []
    for _ in range(H):
        row = list(map(int, sys.stdin.readline().split()))
        A.append(row)
    
    # Initialize result array for each year
    result = [H * W] * (Y + 1)  # result[i] will store area at year i
    
    # Use a min-heap to simulate the flooding process
    heap = []
    
    # Directions for adjacent cells (up, down, left, right)
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    
    # Mark visited cells
    visited = [[False] * W for _ in range(H)]
    
    # Add all border cells to the heap with their elevation
    for i in range(H):
        for j in range(W):
            if i == 0 or i == H-1 or j == 0 or j == W-1:
                heapq.heappush(heap, (A[i][j], i, j))
                visited[i][j] = True
    
    # Process the flooding over time
    current_area = H * W
    
    # For each sea level from 1 to Y
    for sea_level in range(1, Y + 1):
        # Flood all cells that can be reached and have elevation <= sea_level
        while heap and heap[0][0] <= sea_level:
            elev, i, j = heapq.heappop(heap)
            
            # This cell is now underwater
            current_area -= 1
            
            # Check all adjacent cells
            for di, dj in directions:
                ni, nj = i + di, j + dj
                if 0 <= ni < H and 0 <= nj < W and not visited[ni][nj]:
                    visited[ni][nj] = True
                    # If the adjacent cell would be flooded at its own elevation,
                    # add it to the heap
                    heapq.heappush(heap, (A[ni][nj], ni, nj))
        
        # Store the remaining area after this year
        result[sea_level] = current_area
    
    # Output results for years 1 to Y
    for i in range(1, Y + 1):
        print(result[i])

if __name__ == "__main__":
    main()