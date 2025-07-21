int h, w, q;
cin >> h >> w >> q;
vector<vector<set<pair<int, int>>> > grid(h, vector<set<pair<int, int>>>(w));

// Initialize the grid with walls
for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
        grid[i][j].insert({i, j});
    }
}

for (int i = 0; i < q; i++) {
    int r, c;
    cin >> r >> c;
    if (!grid[r-1][c-1].empty()) {
        // Destroy walls in the specified cell
        grid[r-1][c-1].erase({r-1, c-1});
    } else {
        // Destroy walls in the four directions
        // (Implement logic to identify and destroy walls correctly)
    }
}

int remainingWalls = 0;
for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
        remainingWalls += grid[i][j].size();
    }
}

cout << remainingWalls << endl;