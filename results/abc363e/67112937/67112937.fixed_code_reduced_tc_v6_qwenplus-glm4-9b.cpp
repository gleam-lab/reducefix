function simulateSubmersion(H, W, Y, matrix):
    visited = create 2D array of size HxW filled with False
    submergedCount = 0
    queue = empty queue

    // Initialize the queue with cells adjacent to the sea
    for each cell in matrix:
        if cell is on the border or matrix[cell.row][cell.col - 1] is sea or ...
            if not visited[cell.row][cell.col]:
                queue.enqueue(cell)
                visited[cell.row][cell.col] = true

    while queue is not empty:
        cell = queue.dequeue()
        submergedCount += 1
        for each neighbor in cell's neighbors:
            if neighbor is not visited and neighbor's elevation <= cell's elevation:
                queue.enqueue(neighbor)
                visited[neighbor.row][neighbor.col] = true

    remainingArea = H * W - submergedCount
    return remainingArea

function main():
    H, W, Y = read input
    matrix = read matrix of elevations
    for i from 1 to Y:
        remainingArea = simulateSubmersion(H, W, 1, matrix)
        print remainingArea