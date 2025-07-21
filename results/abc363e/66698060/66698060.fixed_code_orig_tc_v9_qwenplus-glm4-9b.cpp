function simulateFlooding(H, W, Y, A):
    initialize island as a 2D array with values corresponding to A
    initialize seaLevel to 0
    initialize floodedCells as a 2D array filled with False

    for year = 1 to Y:
        # Apply flood fill from boundary cells
        for each cell on boundary:
            if cell is not flooded:
                floodFill(cell, H, W, A, floodedCells, seaLevel)

        # Calculate the remaining area above sea level
        remainingArea = 0
        for i = 0 to H-1:
            for j = 0 to W-1:
                if island[i][j] > seaLevel and not floodedCells[i][j]:
                    remainingArea += 1
        print(remainingArea)

function floodFill(cell, H, W, A, floodedCells, seaLevel):
    queue = initializeQueue()
    queue.enqueue(cell)

    while not queue.isEmpty():
        current = queue.dequeue()
        if floodedCells[current.x][current.y]:
            continue
        floodedCells[current.x][current.y] = True
        if A[current.x][current.y] <= seaLevel:
            return (A[current.x][current.y] <= seaLevel)

        for each neighbor of current:
            if A[neighbor.x][neighbor.y] > A[current.x][current.y]:
                queue.enqueue(neighbor)