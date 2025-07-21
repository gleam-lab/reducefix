#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> grid(h, vector<int>(w, 1));  // Using a 2D vector to represent the grid with walls

    // Process each query
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (grid[r][c] == 1) {  // Check if there's a wall
            grid[r][c] = 0;  // Destroy the wall
        } else {  // No wall at the position, destroy walls in four directions
            // Destroy walls upwards
            for (int i = r - 1; i >= 0 && grid[i][c] == 1; --i) {
                grid[i][c] = 0;
            }
            // Destroy walls downwards
            for (int i = r + 1; i < h && grid[i][c] == 1; ++i) {
                grid[i][c] = 0;
            }
            // Destroy walls to the left
            for (int j = c - 1; j >= 0 && grid[r][j] == 1; --j) {
                grid[r][j] = 0;
            }
            // Destroy walls to the right
            for (int j = c + 1; j < w && grid[r][j] == 1; ++j) {
                grid[r][j] = 0;
            }
        }
    }

    // Count remaining walls
    int remaining_walls = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            remaining_walls += grid[i][j];
        }
    }

    cout << remaining_walls << "\n";
    return 0;
}