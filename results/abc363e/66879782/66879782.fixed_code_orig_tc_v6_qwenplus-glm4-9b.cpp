function floodFill(matrix, seaLevel) {
    queue<int[]> q
    q.add(0, 0)  // Start flood fill from (0, 0)
    while (q is not empty) {
        int[] cell = q.poll()
        int r = cell[0]
        int c = cell[1]
        if (matrix[r][c] >= seaLevel and !visited[r][c]) {
            visited[r][c] = true
            for (all 4 directions:
                if (isValid(r + dr, c + dc) and matrix[r + dr][c + dc] >= seaLevel and !visited[r + dr][c + dc]):
                    q.add(r + dr, c + dc)
        }
    }
}

function main() {
    int h, w, y
    read dimensions and sea level rise over the years
    int[][] visited = new int[h][w]
    for each year up to Y:
        for all cells:
            if (cell elevation >= current sea level and !visited[cell]):
                floodFill(visited, current sea level)
        calculate the remaining area
}