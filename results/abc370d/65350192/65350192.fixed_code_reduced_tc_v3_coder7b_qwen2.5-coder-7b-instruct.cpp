#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true));
    vector<int> col_walls(w, h);
    vector<int> row_walls(h, w);

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (grid[r][c]) {
            grid[r][c] = false;
            col_walls[c]--;
            row_walls[r]--;
        } else {
            // Check up
            for (int i = r - 1; i >= 0 && grid[i][c]; --i) {
                grid[i][c] = false;
                col_walls[c]--;
                row_walls[i]--;
            }

            // Check down
            for (int i = r + 1; i < h && grid[i][c]; ++i) {
                grid[i][c] = false;
                col_walls[c]--;
                row_walls[i]--;
            }

            // Check left
            for (int j = c - 1; j >= 0 && grid[r][j]; --j) {
                grid[r][j] = false;
                col_walls[j]--;
                row_walls[r]--;
            }

            // Check right
            for (int j = c + 1; j < w && grid[r][j]; ++j) {
                grid[r][j] = false;
                col_walls[j]--;
                row_walls[r]--;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < h; ++i) {
        ans += row_walls[i];
    }
    for (int j = 0; j < w; ++j) {
        ans += col_walls[j];
    }

    cout << ans << "\n";
    return 0;
}