#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true));
    while (q--) {
        int r, c;
        cin >> r >> c;
        r--, c--;
        if (grid[r][c]) {
            grid[r][c] = false;
        } else {
            for (int i = 0; i < h; ++i) {
                if (grid[i][c] && i >= r) break;
                if (!grid[i][c]) continue;
                grid[i][c] = false;
                break;
            }
            for (int i = h - 1; i >= 0; --i) {
                if (grid[i][c] && i <= r) break;
                if (!grid[i][c]) continue;
                grid[i][c] = false;
                break;
            }
            for (int j = 0; j < w; ++j) {
                if (grid[r][j] && j >= c) break;
                if (!grid[r][j]) continue;
                grid[r][j] = false;
                break;
            }
            for (int j = w - 1; j >= 0; --j) {
                if (grid[r][j] && j <= c) break;
                if (!grid[r][j]) continue;
                grid[r][j] = false;
                break;
            }
        }
    }
    int ans = 0;
    for (const auto &row : grid) {
        ans += count(row.begin(), row.end(), true);
    }
    cout << ans << '\n';
    return 0;
}