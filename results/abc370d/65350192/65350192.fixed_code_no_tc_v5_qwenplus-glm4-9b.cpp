#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;

    // Initialize the grid with walls
    bool grid[h][w];
    memset(grid, true, sizeof(grid));

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        // Check if there is a wall at the given position
        if (grid[r][c]) {
            grid[r][c] = false; // Destroy the wall
        } else {
            // If there is no wall at (r, c), destroy the walls around it
            // Check and destroy vertical walls
            bool destroyed = false;
            int down = r + 1, up = r - 1;
            while (down < h && grid[down][c]) {
                grid[down++][c] = false;
                destroyed = true;
            }
            while (up >= 0 && grid[up][c]) {
                grid[up--][c] = false;
                destroyed = true;
            }
            if (destroyed) continue;

            // Check and destroy horizontal walls
            destroyed = false;
            int right = c + 1, left = c - 1;
            while (right < w && grid[r][right]) {
                grid[r][right++] = false;
                destroyed = true;
            }
            while (left >= 0 && grid[r][left]) {
                grid[r][left--] = false;
                destroyed = true;
            }
        }
    }

    // Count the remaining walls
    int remaining = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j]) remaining++;
        }
    }

    cout << remaining << "\n";
    return 0;
}