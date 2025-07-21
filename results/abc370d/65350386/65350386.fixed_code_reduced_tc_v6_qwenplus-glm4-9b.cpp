#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<int>> grid(h, vector<int>(w, 1)); // Initially, there is one wall in each cell.

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--; // Convert to 0-based index.

        // Check if there's a wall at (r, c)
        if (grid[r][c] > 0) {
            grid[r][c]--; // Destroy the wall.
        } else {
            // Find the first wall in the row above and destroy it
            for (int i = r - 1; i >= 0; i--) {
                if (grid[i][c] > 0) {
                    grid[i][c]--;
                    break;
                }
            }

            // Find the first wall in the row below and destroy it
            for (int i = r + 1; i < h; i++) {
                if (grid[i][c] > 0) {
                    grid[i][c]--;
                    break;
                }
            }

            // Find the first wall in the column to the left and destroy it
            for (int j = c - 1; j >= 0; j--) {
                if (grid[r][j] > 0) {
                    grid[r][j]--;
                    break;
                }
            }

            // Find the first wall in the column to the right and destroy it
            for (int j = c + 1; j < w; j++) {
                if (grid[r][j] > 0) {
                    grid[r][j]--;
                    break;
                }
            }
        }
    }

    // Count the remaining walls
    int remaining_walls = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            remaining_walls += grid[i][j];
        }
    }

    cout << remaining_walls << endl;

    return 0;
}