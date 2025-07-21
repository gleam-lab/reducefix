#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    // Initialize the grid with walls
    vector<vector<int>> grid(h + 2, vector<int>(w + 2, 4)); // +2 for boundaries

    // Process each query
    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        r++; c++; // Convert to 1-based indexing

        // Check if there's a wall at the given cell
        if (grid[r][c] > 0) {
            grid[r][c]--;
        } else {
            // Destroy walls around the cell
            for (int i = max(1, r - 1); i <= min(h + 1, r + 1); ++i) {
                grid[i][c]--;
            }
            for (int j = max(1, c - 1); j <= min(w + 1, c + 1); ++j) {
                grid[r][j]--;
            }
        }
    }

    // Count the remaining walls
    int remainingWalls = 0;
    for (int i = 1; i <= h + 1; ++i) {
        for (int j = 1; j <= w + 1; ++j) {
            remainingWalls += grid[i][j];
        }
    }

    // Output the result
    cout << remainingWalls << endl;

    return 0;
}