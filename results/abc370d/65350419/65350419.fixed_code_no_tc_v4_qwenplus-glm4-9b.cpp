#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    // Initialize the grid with walls
    vector<vector<int>> grid(h + 2, vector<int>(w + 2, 1)); // Extra padding for boundary conditions

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    for (int qi = 0; qi < q; ++qi) {
        int r, c;
        cin >> r >> c;
        r--; c--; // Convert to 0-indexed

        // Process the query
        if (grid[r + 1][c + 1] == 2) {
            // The cell already has a bomb, do nothing
        } else {
            // Place a bomb and remove walls
            grid[r + 1][c + 1] = 2;

            // Remove walls above
            for (int i = r + 1; i > 1 && grid[i - 1][c + 1] == 1; --i) {
                grid[i - 1][c + 1] = 0;
            }

            // Remove walls below
            for (int i = r + 1; i <= h && grid[i + 1][c + 1] == 1; ++i) {
                grid[i + 1][c + 1] = 0;
            }

            // Remove walls to the left
            for (int j = c + 1; j > 1 && grid[r + 1][j - 1] == 1; --j) {
                grid[r + 1][j - 1] = 0;
            }

            // Remove walls to the right
            for (int j = c + 1; j <= w && grid[r + 1][j + 1] == 1; ++j) {
                grid[r + 1][j + 1] = 0;
            }
        }
    }

    // Count the remaining walls
    int remainingWalls = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            remainingWalls += grid[i][j];
        }
    }

    // Output the result
    cout << remainingWalls << "\n";

    return 0;
}