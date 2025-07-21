int totalWalls = H * W;
for (each query in queries) {
    r, c = query;
    if (no wall at (r, c)) {
        // Destroy walls in all four directions
        destroyWall(r-1, c); // Up
        destroyWall(r+1, c); // Down
        destroyWall(r, c-1); // Left
        destroyWall(r, c+1); // Right
    } else {
        // Destroy the wall at (r, c)
        destroyWall(r, c);
    }
    totalWalls -= number of destroyed walls
}
print(totalWalls);