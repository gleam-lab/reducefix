function solve():
    # Initialize 2D list to store sinking years
    sink_year = [[0] * W for _ in range(H)]
    
    # Initialize queue and process outer edges
    queue = []
    for i in range(H):
        for j in range(W):
            if i == 0 or i == H - 1 or j == 0 or j == W - 1:
                queue.push((0, i, j))  # (sinking_year, row, col)
                sink_year[i][j] = 0
    
    # BFS to calculate sinking years
    while queue is not empty:
        year, r, c = queue.pop()
        for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nr, nc = r + dr, c + dc
            if 0 <= nr < H and 0 <= nc < W:
                new_year = year + 1
                if new_year < sink_year[nr][nc] or sink_year[nr][nc] != 0:
                    sink_year[nr][nc] = min(sink_year[nr][nc], new_year)
                queue.push((new_year, nr, nc))
    
    # Calculate remaining areas
    area_above_sea_level = H * W
    for i in range(H):
        for j in range(W):
            if sink_year[i][j] > Y:
                area_above_sea_level -= 1
    
    # Output Y lines of results
    for i in range(1, Y + 1):
        print(area_above_sea_level)

# Read input
H, W, Y = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(H)]

# Solve the problem
solve()