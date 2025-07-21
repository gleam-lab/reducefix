#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<bool>> grid(h, vector<bool>(w, true)); // Use a boolean grid to track walls
    vector<vector<int>> up(h, vector<int>(w, -1)); // To store the last up wall before the current position
    vector<vector<int>> left(h, vector<int>(w, -1)); // To store the last left wall before the current position

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--; // Convert to 0-based index

        // If there's a wall at the given position, destroy it
        if (grid[r][c]) {
            grid[r][c] = false;
        } else {
            // Find the highest wall above the current position
            int ur = r - 1;
            while (ur >= 0 && !grid[ur][c]) --ur;
            up[r][c] = ur; // Update the up wall position

            // Find the leftmost wall to the current position
            int lc = c - 1;
            while (lc >= 0 && !grid[r][lc]) --lc;
            left[r][c] = lc; // Update the left wall position

            // Remove walls above and to the left
            while (ur != -1) {
                if (left[ur][c]) {
                    grid[ur][c] = false;
                    lc = left[ur][c];
                    while (lc != -1) {
                        if (grid[ur][lc]) {
                            grid[ur][lc] = false;
                        } else {
                            break;
                        }
                        lc = left[ur][lc];
                    }
                }
                ur = up[ur][c];
            }
        }
    }

    // Count the remaining walls
    ll remaining_walls = 0;
    rep(i, h) rep(j, w) {
        remaining_walls += grid[i][j];
    }

    cout << remaining_walls << endl;
    return 0;
}