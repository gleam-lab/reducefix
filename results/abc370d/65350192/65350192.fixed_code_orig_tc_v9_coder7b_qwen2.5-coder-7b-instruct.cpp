#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<bool>> grid(h, vector<bool>(w, true));
    set<pair<int, int>> bombs;

    while (q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;  // Convert to zero-based indexing

        if (grid[r][c]) {
            grid[r][c] = false;
            bombs.erase(bombs.find({r, c}));
        } else {
            bool found = false;
            for (int i = r + 1; i < h && !found; ++i) {
                if (grid[i][c]) {
                    grid[i][c] = false;
                    bombs.insert({i, c});
                    found = true;
                }
            }

            for (int i = r - 1; i >= 0 && !found; --i) {
                if (grid[i][c]) {
                    grid[i][c] = false;
                    bombs.insert({i, c});
                    found = true;
                }
            }

            for (int j = c + 1; j < w && !found; ++j) {
                if (grid[r][j]) {
                    grid[r][j] = false;
                    bombs.insert({r, j});
                    found = true;
                }
            }

            for (int j = c - 1; j >= 0 && !found; --j) {
                if (grid[r][j]) {
                    grid[r][j] = false;
                    bombs.insert({r, j});
                    found = true;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j]) ++ans;
        }
    }

    cout << ans << '\n';
    return 0;
}