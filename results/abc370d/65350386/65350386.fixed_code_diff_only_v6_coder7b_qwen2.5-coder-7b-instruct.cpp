#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true)); // Initialize grid with walls

    rep(qi,q) {
        int r, c;
        cin >> r >> c;
        r--; c--; // Adjust indices since problem statement uses 1-based indexing

        if (grid[r][c]) { // If there is a wall at (r, c)
            grid[r][c] = false; // Destroy the wall
        } else {
            // Look up
            for (int i = r - 1; i >= 0 && grid[i][c]; --i) {
                grid[i][c] = false;
            }
            // Look down
            for (int i = r + 1; i < h && grid[i][c]; ++i) {
                grid[i][c] = false;
            }
            // Look left
            for (int j = c - 1; j >= 0 && grid[r][j]; --j) {
                grid[r][j] = false;
            }
            // Look right
            for (int j = c + 1; j < w && grid[r][j]; ++j) {
                grid[r][j] = false;
            }
        }
    }

    int ans = 0;
    rep(i,h) rep(j,w) if (grid[i][j]) ++ans; // Count remaining walls
    cout << ans << "\n";

    return 0;
}