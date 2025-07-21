#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n, m, q;
int h[MAXN][MAXN];
bool vis[MAXN][MAXN];

void bfs(int x, int y, int level) {
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;
    
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        
        for (int k = 0; k < 4; ++k) {
            int nx = cx + dx[k], ny = cy + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && h[nx][ny] <= level) {
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> n >> m >> q;
    vector<vector<int>> h(n, vector<int>(m));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> h[i][j];
        }
    }
    
    vector<int> levels(q);
    for (int i = 0; i < q; ++i) {
        cin >> levels[i];
    }
    
    sort(levels.begin(), levels.end());
    levels.erase(unique(levels.begin(), levels.end()), levels.end());
    
    int idx = 0;
    vector<int> res(q);
    
    for (int i = 0; i < q; ++i) {
        while (idx < levels.size() && levels[idx] <= i) {
            memset(vis, false, sizeof(vis));
            bfs(0, 0, levels[idx]);
            ++idx;
        }
        res[i] = n * m - count_if(begin(vis), end(vis), [](auto &v){ return v; });
    }
    
    for (int i = 0; i < q; ++i) {
        cout << res[i] << '\n';
    }
    
    return 0;
}