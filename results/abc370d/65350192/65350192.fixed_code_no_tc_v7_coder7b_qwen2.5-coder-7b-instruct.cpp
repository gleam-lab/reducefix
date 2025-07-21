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
        r--; c--;
        if (grid[r][c]) {
            grid[r][c] = false;
        } else {
            for (int i = r - 1; i >= 0; --i) {
                if (!grid[i][c]) break;
                grid[i][c] = false;
            }
            for (int i = r + 1; i < h; ++i) {
                if (!grid[i][c]) break;
                grid[i][c] = false;
            }
            for (int j = c - 1; j >= 0; --j) {
                if (!grid[r][j]) break;
                grid[r][j] = false;
            }
            for (int j = c + 1; j < w; ++j) {
                if (!grid[r][j]) break;
                grid[r][j] = false;
            }
        }
    }
    int ans = 0;
    for (auto &row : grid) {
        ans += count(row.begin(), row.end(), true);
    }
    cout << ans << "\n";
    return 0;
}