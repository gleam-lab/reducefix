#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w, q;
    cin >> h >> w >> q;

    // Initialize the grid with walls
    vector<vector<bool>> grid(h, vector<bool>(w, true));

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--; // Convert to 0-indexed

        // Check if there's a wall at the given position
        if (grid[r][c]) {
            grid[r][c] = false; // Destroy the wall
        } else {
            // Find the nearest wall above and below
            int u = r - 1, d = r + 1;
            while (u >= 0 && !grid[u][c]) u--;
            while (d < h && !grid[d][c]) d++;

            // Find the nearest wall to the left and right
            int l = c - 1, r2 = c + 1;
            while (l >= 0 && !grid[r][l]) l--;
            while (r2 < w && !grid[r][r2]) r2++;

            // If there's no wall at (r, c), destroy the walls in the vicinity
            if (u >= 0) grid[u][c] = false;
            if (d < h) grid[d][c] = false;
            if (l >= 0) grid[r][l] = false;
            if (r2 < w) grid[r][r2] = false;
        }
    }

    // Count the remaining walls
    int remaining_walls = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            remaining_walls += grid[i][j];
        }
    }

    // Output the result
    cout << remaining_walls << endl;

    return 0;
}