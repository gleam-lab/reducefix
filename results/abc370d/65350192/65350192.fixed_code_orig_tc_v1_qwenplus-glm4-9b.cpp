#include <iostream>
#include <vector>
using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    // Initialize grid with walls
    vector<vector<int>> grid(h, vector<int>(w, h + 1));

    // Process each query
    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        --r; --c; // Convert to 0-based index

        // Check if there's a wall at (r, c)
        if (grid[r][c] > 1) {
            grid[r][c]--; // Destroy the wall
        } else {
            // Destroy walls in all four directions
            // ... (Implement the logic to destroy walls here)
        }
    }

    // Calculate the number of remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            remainingWalls += grid[i][j] - 1; // Subtract the wall from the total
        }
    }

    // Output the result
    cout << remainingWalls << endl;

    return 0;
}