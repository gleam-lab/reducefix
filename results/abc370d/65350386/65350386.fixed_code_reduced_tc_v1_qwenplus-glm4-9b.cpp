int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> grid(h, vector<int>(w, 0));
    // Initialize walls in each cell
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            grid[i][j] = 1; // Assume one wall per cell initially
        }
    }

    // Process each query
    while (q--) {
        int r, c;
        cin >> r >> c;
        if (grid[r - 1][c - 1] == 0) {
            // No wall at this cell, perform surrounding wall removal
            // ...
        } else {
            // Bomb placed on a wall, destroy this wall
            grid[r - 1][c - 1] = 0;
        }
    }

    // Count remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == 1) {
                remainingWalls++;
            }
        }
    }

    cout << remainingWalls << endl;
    return 0;
}