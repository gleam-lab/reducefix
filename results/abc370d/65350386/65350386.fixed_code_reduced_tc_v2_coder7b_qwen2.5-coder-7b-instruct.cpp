#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true));
    set<pair<int, int>> bombs;

    auto updateGrid = [&](int x, int y) {
        if (grid[x][y]) {
            grid[x][y] = false;
            bombs.erase(bombs.find({x, y}));
        } else {
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx == 0 && dy == 0) continue;
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < h && ny >= 0 && ny < w && grid[nx][ny]) {
                        grid[nx][ny] = false;
                        bombs.insert({nx, ny});
                    }
                }
            }
        }
    };

    while (q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        updateGrid(r, c);
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