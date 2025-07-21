struct DSU {
    // DSU structure
};

int H, W, Y;
int grid[H][W];

DSU dsu;

// Initialize the DSU with each cell
for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
        dsu.initialize(grid[i][j]);
    }
}

for (int year = 1; year <= Y; ++year) {
    // Update DSU based on the current sea level
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            // Check if the cell is at or below the current sea level
            if (grid[i][j] <= year) {
                // Union with adjacent cells
                dsu.union_nodes(i, j);
            }
        }
    }
    
    // Calculate the size of the connected components still above the sea level
    int remaining_area = dsu.calculate_remaining_area(year);
    cout << remaining_area << endl;
}