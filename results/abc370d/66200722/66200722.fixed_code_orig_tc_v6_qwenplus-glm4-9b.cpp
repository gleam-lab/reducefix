#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            grid[i][j] = 1; // Initially, all cells have a wall.
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        --r; --c; // Convert to 0-indexed.

        // Check if there's a wall at the given cell.
        if (grid[r][c] == 1) {
            grid[r][c] = 0; // Remove the wall.
        } else {
            // Remove walls upwards until an empty cell is found.
            while (r >= 0 && grid[r][c] == 1) {
                grid[r][c] = 0;
                r--;
            }

            r++; // Put the row index back to the original position.

            // Remove walls downwards until an empty cell is found.
            while (r < h && grid[r][c] == 1) {
                grid[r][c] = 0;
                r++;
            }

            r--; // Put the row index back to the original position.

            // Remove walls to the left until an empty cell is found.
            while (c >= 0 && grid[r][c] == 1) {
                grid[r][c] = 0;
                c--;
            }

            c++; // Put the column index back to the original position.

            // Remove walls to the right until an empty cell is found.
            while (c < w && grid[r][c] == 1) {
                grid[r][c] = 0;
                c++;
            }
        }
    }

    // Count the remaining walls in the grid.
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