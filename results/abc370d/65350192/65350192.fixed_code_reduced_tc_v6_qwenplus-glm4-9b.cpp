#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<int>> grid(H, vector<int>(W, 1)); // Start with 1 wall in each cell

    while (Q--) {
        int r, c;
        cin >> r >> c;
        r--; c--; // Convert to 0-based index

        if (grid[r][c] == 1) {
            // If there's a wall, destroy it
            grid[r][c] = 0;
        } else {
            // No wall, destroy walls around it
            for (int i = r - 1; i >= 0 && grid[i][c] == 1; --i) grid[i][c] = 0;
            for (int i = r + 1; i < H && grid[i][c] == 1; ++i) grid[i][c] = 0;
            for (int j = c - 1; j >= 0 && grid[r][j] == 1; --j) grid[r][j] = 0;
            for (int j = c + 1; j < W && grid[r][j] == 1; ++j) grid[r][j] = 0;
        }
    }

    // Count remaining walls
    int remaining_walls = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            remaining_walls += grid[i][j];
        }
    }

    cout << remaining_walls << endl;
    return 0;
}