#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true));
    while (q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        if (grid[r][c]) {
            grid[r][c] = false;
            int cnt = 0;
            // Check up
            for (int i = r - 1; i >= 0 && grid[i][c]; --i) {
                grid[i][c] = false;
                ++cnt;
            }
            // Check down
            for (int i = r + 1; i < h && grid[i][c]; ++i) {
                grid[i][c] = false;
                ++cnt;
            }
            // Check left
            for (int j = c - 1; j >= 0 && grid[r][j]; --j) {
                grid[r][j] = false;
                ++cnt;
            }
            // Check right
            for (int j = c + 1; j < w && grid[r][j]; ++j) {
                grid[r][j] = false;
                ++cnt;
            }
        }
    }
    int ans = 0;
    for (auto &row : grid)
        for (bool b : row)
            if (b) ++ans;
    cout << ans << "\n";
    return 0;
}