function simulateSinking(H, W, Y, A):
    # Step 1: Initialize the island grid
    grid = [[true for _ in range(W)] for _ in range(H)]
    for i in range(H):
        for j in range(W):
            if A[i][j] <= 0:
                grid[i][j] = false

    # Step 2: Simulate sinking each year
    for year in range(Y):
        for i in range(H):
            for j in range(W):
                # Check if the cell is sinking
                if grid[i][j] and isSinking(grid, i, j, A):
                    grid[i][j] = false
        # After sinking, calculate the remaining area above sea level
        remaining_area = calculateRemainingArea(grid, A)
        print(remaining_area)

# Function to check if a cell is sinking
function isSinking(grid, i, j, A):
    neighbors = checkNeighbors(grid, A, i, j)
    for neighbor in neighbors:
        if grid[neighbor[0]][neighbor[1]] == false:
            return true
    return false

# Function to check all four neighbors
function checkNeighbors(grid, A, i, j):
    # Add logic to check all four directions and return the coordinates of neighbors
    return []

# Function to calculate remaining area
function calculateRemainingArea(grid, A):
    # Add logic to calculate the area of cells that are still true (floating)
    return 0

# Read input
H, W, Y = readInput()
A = readElevationData(H, W)

# Call the simulation function
simulateSinking(H, W, Y, A)