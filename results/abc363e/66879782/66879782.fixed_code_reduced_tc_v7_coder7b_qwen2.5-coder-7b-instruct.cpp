#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int n, m, y;
int h[MAXN][MAXN];
bool vis[MAXN][MAXN];

struct Cell {
    int x, y, h;
};

struct cmp {
    bool operator()(const Cell &a, const Cell &b) {
        return a.h > b.h;
    }
};

void bfs(int x, int y, int target_h) {
    queue<Cell> q;
    q.push({x, y, h[x][y]});
    vis[x][y] = true;
    while (!q.empty()) {
        Cell cur = q.front(); q.pop();
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx * dy != 0) continue;
                int nx = cur.x + dx, ny = cur.y + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (vis[nx][ny] || h[nx][ny] > target_h) continue;
                vis[nx][ny] = true;
                q.push({nx, ny, h[nx][ny]});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m >> y;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> h[i][j];
        }
    }

    vector<int> ans(y + 1);
    for (int t = 1; t <= y; ++t) {
        fill(vis[0], vis[n], false);
        priority_queue<Cell, vector<Cell>, cmp> pq;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    pq.push({i, j, h[i][j]});
                }
            }
        }
        while (!pq.empty() && pq.top().h <= t) {
            Cell cur = pq.top(); pq.pop();
            if (vis[cur.x][cur.y]) continue;
            bfs(cur.x, cur.y, t);
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!vis[i][j]) ++cnt;
            }
        }
        ans[t] = cnt;
    }

    for (int i = 1; i <= y; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}