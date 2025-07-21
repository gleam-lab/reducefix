function simulateRisingSeaLevel(H, W, Y, A):
    vis = create 2D array of H x W with all values initially false
    queue = empty queue
    // Initialize the queue with cells on the edges that will definitely sink
    for each row from 0 to H-1:
        if A[row][0] <= Y:
            enqueue (row, 0, A[row][0])
            vis[row][0] = true
        if A[row][W-1] <= Y:
            enqueue (row, W-1, A[row][W-1])
            vis[row][W-1] = true
    for each col from 0 to W-1:
        if A[0][col] <= Y:
            enqueue (0, col, A[0][col])
            vis[0][col] = true
        if A[H-1][col] <= Y:
            enqueue (H-1, col, A[H-1][col])
            vis[H-1][col] = true

    while not queue.empty():
        row, col, height = dequeue()
        for each neighbor (new_row, new_col) in neighbors(row, col):
            if not vis[new_row][new_col] and A[new_row][new_col] <= height:
                enqueue (new_row, new_col, A[new_row][new_col])
                vis[new_row][new_col] = true

    // Number of cells that remained above sea level
    remaining_cells = H * W - count of true in vis
    for year from 1 to Y:
        new_remaining_cells = 0
        for each cell:
            if not vis[cell] and cell's height > year:
                new_remaining_cells += 1
                for each neighbor of cell:
                    if not vis[neighbor] and neighbor's height <= year:
                        enqueue neighbor for sinking in the next year
        remaining_cells -= count of cells that sunk
        remaining_cells += new_remaining_cells
        print remaining_cells