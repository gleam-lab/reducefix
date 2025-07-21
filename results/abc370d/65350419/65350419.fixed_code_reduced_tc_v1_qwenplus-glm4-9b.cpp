#include <iostream>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true)); // Initially, all cells have walls.

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (grid[r][c]) {
            grid[r][c] = false; // Destroy the wall at the given cell.
        } else {
            // Check and destroy walls in all four directions.
            // Up
            for (int i = r - 1; i >= 0 && grid[i][c]; i--) {
                grid[i][c] = false;
            }
            // Down
            for (int i = r + 1; i < h && grid[i][c]; i++) {
                grid[i][c] = false;
            }
            // Left
            for (int j = c - 1; j >= 0 && grid[r][j]; j--) {
                grid[r][j] = false;
            }
            // Right
            for (int j = c + 1; j < w && grid[r][j]; j++) {
                grid[r][j] = false;
            }
        }
    }

    // Count the remaining walls.
    int remainingWalls = 0;
    rep(i, h) {
        rep(j, w) {
            if (grid[i][j]) {
                remainingWalls++;
            }
        }
    }

    cout << remainingWalls << endl;
    return 0;
}