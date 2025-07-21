#include <iostream>
#include <vector>
using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true)); // true means wall exists

    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        --r; --c; // Convert to 0-based index

        // Check if there's a wall at (r, c)
        if (grid[r][c]) {
            grid[r][c] = false; // Destroy the wall
        } else {
            // Destroy walls vertically and horizontally within the grid
            // from (r, c)
            for (int i = 0; i < h; i++) {
                if (grid[i][c]) grid[i][c] = false;
            }
            for (int j = 0; j < w; j++) {
                if (grid[r][j]) grid[r][j] = false;
            }
        }
    }

    // Count remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j]) remainingWalls++;
        }
    }

    cout << remainingWalls << endl;
    return 0;
}