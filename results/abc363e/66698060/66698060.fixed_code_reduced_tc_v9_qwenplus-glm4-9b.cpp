function floodFill(grid, start_i, start_j):
    stack = [(start_i, start_j)]
    while stack is not empty:
        i, j = stack.pop()
        if grid[i][j] == true:
            grid[i][j] = false
            for k in range(4):  # up, down, left, right
                ni, nj = i + dx[k], j + dy[k]
                if 0 <= ni < H and 0 <= nj < W and grid[ni][nj] == true:
                    stack.push((ni, nj))

function simulateSeaRise(H, W, Y, grid):
    total_area = H * W
    for sea_level in range(1, Y + 1):
        for i in range(H):
            for j in range(W):
                if grid[i][j] and grid[i][j] <= sea_level:
                    floodFill(grid, i, j)
        remaining_area = 0
        for i in range(H):
            for j in range(W):
                if grid[i][j]:
                    remaining_area += 1
        print(remaining_area)

# Input reading and initialization
H, W, Y = readInput()
grid = [[true for _ in range(W)] for _ in range(H)]
for i in range(H):
    row = readInputLine()  # This should read a single line and parse to integers
    for j in range(W):
        grid[i][j] = row[j]

simulateSeaRise(H, W, Y, grid)