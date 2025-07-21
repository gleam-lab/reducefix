#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
int grid[MAXN][MAXN], sink[MAXN][MAXN], n, m, y;
bool vis[MAXN][MAXN];

void bfs(int level) {
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (grid[i][j] > level && !vis[i][j]) {
                q.emplace(i, j);
                vis[i][j] = true;
            }
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (auto [dx, dy] : vector<pair<int, int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}})
            if (x + dx >= 0 && x + dx < n && y + dy >= 0 && y + dy < m && !vis[x + dx][y + dy] && grid[x + dx][y + dy] > level) {
                q.emplace(x + dx, y + dy);
                vis[x + dx][y + dy] = true;
            }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m >> y;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];
    
    vector<int> ans(y + 1);
    for (int k = 1; k <= y; ++k) {
        memset(vis, false, sizeof(vis));
        bfs(k);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] > k && !vis[i][j])
                    ans[k]++;
    }
    
    partial_sum(ans.begin(), ans.end(), ans.begin());
    for (int i = 1; i <= y; ++i)
        cout << n * m - ans[i] << '\n';

    return 0;
}