#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

bool grid[N][N];

void solve() {
    int h, w, q;
    cin >> h >> w >> q;
    memset(grid, 1, sizeof grid);

    while(q--) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        if(grid[x][y]) {
            grid[x][y] = 0;
        } else {
            for(int i = 0; i < 4; ++i) {
                int dx[] = {0, 0, -1, 1};
                int dy[] = {-1, 1, 0, 0};
                int nx = x + dx[i], ny = y + dy[i];
                while(nx >= 0 && nx < h && ny >= 0 && ny < w) {
                    if(!grid[nx][ny]) break;
                    grid[nx][ny] = 0;
                    nx += dx[i];
                    ny += dy[i];
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            ans += grid[i][j];
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}