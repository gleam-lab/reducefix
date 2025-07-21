#include <bits/stdc++.h>
using namespace std;

#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAXN 1100
#define LIMIT 22
#define inf 0x3f3f3f3f3f3f
#define endl '\n'
const double eps = 1e-7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int MOD = 1e9 + 7;

void bfs(int h, int w, vector<vector<int>>& grid, int level, vector<vector<bool>>& visited) {
    queue<pair<int, int>> q;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!visited[i][j] && grid[i][j] <= level) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && grid[nx][ny] <= level) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

signed main() {
    close;
    int h, w; cin >> h >> w;
    int y; cin >> y;
    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(h, vector<bool>(w, false));

    int res = h * w;
    for (int level = 1; level <= y; ++level) {
        bfs(h, w, grid, level, visited);
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (visited[i][j]) {
                    --res;
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}