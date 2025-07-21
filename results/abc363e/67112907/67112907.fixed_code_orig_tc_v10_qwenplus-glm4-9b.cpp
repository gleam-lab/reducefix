// Pseudocode
function simulateSeaLevelRise(H, W, Y, A):
    initialSeaLevel = findInitialSeaLevel(A) // Find the lowest elevation
    totalArea = H * W
    sunkenArea = 0

    queue = createQueue()
    // Add coastal sections with elevation equal to initialSeaLevel to the queue
    for (i in range(H)):
        for (j in range(W)):
            if (A[i][j] == initialSeaLevel and isCoastal(A, i, j)):
                queue.enqueue((i, j))

    while (Y > 0):
        Y -= 1
        yearSunkenArea = 0

        while not queue.isEmpty():
            (x, y) = queue.dequeue()
            yearSunkenArea += 1
            for (dx, dy) in directions:
                nx, ny = x + dx, y + dy
                if isValid(nx, ny, H, W) and A[nx][ny] <= initialSeaLevel + Y:
                    queue.enqueue((nx, ny))
                    A[nx][ny] = -1 // Mark as sunken

        sunkenArea += yearSunkenArea
        remainingArea = totalArea - sunkenArea
        print(remainingArea)

    return

// Call simulateSeaLevelRise with the given input