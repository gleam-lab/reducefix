#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true));  // Initialize all walls as present.
    int remainingWalls = h * w;  // All walls are initially present.

    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        r--; c--;  // Convert to zero-based index.

        if (grid[r][c]) {
            // There is a wall at (r, c).
            grid[r][c] = false;  // Remove the wall.
            remainingWalls--;
        } else {
            // There is no wall at (r, c), so we need to remove walls in the four directions.
            // Remove horizontal walls.
            for (int j = 0; j < w; ++j) {
                if (grid[r][j]) {
                    grid[r][j] = false;
                    remainingWalls--;
                }
            }
            // Remove vertical walls.
            for (int j = 0; j < h; ++j) {
                if (grid[j][c]) {
                    grid[j][c] = false;
                    remainingWalls--;
                }
            }
        }
    }

    cout << remainingWalls << endl;
    return 0;
}