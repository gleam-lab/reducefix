#include <iostream>
#include <vector>
using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true)); // Initialize all cells with walls

    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        r--; c--; // Convert to 0-based index

        // Check if the bomb destroys a wall at (r, c)
        if (grid[r][c]) {
            grid[r][c] = false;
        } else {
            // Find and destroy the closest wall in all four directions
            // Destroy the wall just above
            for (int i = r - 1; i >= 0; --i) {
                if (grid[i][c]) {
                    grid[i][c] = false;
                    break;
                }
            }
            // Destroy the wall just below
            for (int i = r + 1; i < h; ++i) {
                if (grid[i][c]) {
                    grid[i][c] = false;
                    break;
                }
            }
            // Destroy the wall just to the left
            for (int j = c - 1; j >= 0; --j) {
                if (grid[r][j]) {
                    grid[r][j] = false;
                    break;
                }
            }
            // Destroy the wall just to the right
            for (int j = c + 1; j < w; ++j) {
                if (grid[r][j]) {
                    grid[r][j] = false;
                    break;
                }
            }
        }
    }

    // Count the number of remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j]) {
                remainingWalls++;
            }
        }
    }

    // Output the result
    cout << remainingWalls << endl;

    return 0;
}