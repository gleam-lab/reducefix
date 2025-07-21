#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    // Initialize the grid with walls.
    vector<vector<int>> grid(H, vector<int>(W, 1)); // 1 indicates a wall.

    for (int q = 0; q < Q; ++q) {
        int r, c;
        cin >> r >> c;
        --r, --c; // Convert to 0-based index.

        // Check if there is a wall at (r, c).
        if (grid[r][c] == 1) {
            // Wall at (r, c) exists, destroy it.
            grid[r][c] = 0;
        } else {
            // No wall at (r, c), destroy the first wall in each direction.
            // Left
            for (int i = c; i >= 0 && grid[r][i] == 1; --i) {
                grid[r][i] = 0;
            }
            // Right
            for (int i = c + 1; i < W && grid[r][i] == 1; ++i) {
                grid[r][i] = 0;
            }
            // Up
            for (int i = r; i >= 0 && grid[i][c] == 1; --i) {
                grid[i][c] = 0;
            }
            // Down
            for (int i = r + 1; i < H && grid[i][c] == 1; ++i) {
                grid[i][c] = 0;
            }
        }
    }

    // Calculate the number of remaining walls.
    int remaining_walls = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            remaining_walls += grid[i][j];
        }
    }

    cout << remaining_walls << endl;

    return 0;
}