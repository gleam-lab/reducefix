#include <bits/stdc++.h>
using namespace std;

#define MAXN 400005
#define MAXQ 200000

int h, w, q;
vector<vector<int>> grid(MAXN, vector<int>(MAXN, 1)); // Initialize with walls

int main() {
    cin >> h >> w >> q;
    for (int i = 1; i <= q; ++i) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if (grid[r][c] == 1) {
            // The cell (r, c) has a wall, so we remove it
            grid[r][c] = 0;
        } else {
            // No wall at (r, c), so we remove walls in all four directions
            // Upward
            for (int i = r - 1; i >= 0 && grid[i][c] == 1; --i) {
                grid[i][c] = 0;
            }
            // Downward
            for (int i = r + 1; i < h && grid[i][c] == 1; ++i) {
                grid[i][c] = 0;
            }
            // Leftward
            for (int j = c - 1; j >= 0 && grid[r][j] == 1; --j) {
                grid[r][j] = 0;
            }
            // Rightward
            for (int j = c + 1; j < w && grid[r][j] == 1; ++j) {
                grid[r][j] = 0;
            }
        }
    }

    // Count the remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            remainingWalls += grid[i][j];
        }
    }

    cout << remainingWalls << endl;
    return 0;
}