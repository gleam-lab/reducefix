#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true));
    vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (!grid[r][c]) continue;

        grid[r][c] = false;
        for (auto& [dr, dc] : directions) {
            int x = r + dr, y = c + dc;
            while (x >= 0 && x < h && y >= 0 && y < w && grid[x][y]) {
                grid[x][y] = false;
                x += dr;
                y += dc;
            }
        }
    }

    int ans = 0;
    rep(i, h) rep(j, w) ans += grid[i][j];
    cout << ans << "\n";
    return 0;
}