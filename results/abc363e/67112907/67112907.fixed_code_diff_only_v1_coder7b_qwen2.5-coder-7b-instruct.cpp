#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 1010;
int n, m, y, h[maxn][maxn];
bool vis[maxn][maxn];

struct node {
    int x, y, z;
    bool operator<(const node& b) const {
        return z > b.z;
    }
};

void bfs(int t) {
    priority_queue<node> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (h[i][j] <= t && !vis[i][j]) {
                q.push({i, j, h[i][j]});
                vis[i][j] = true;
            }
        }
    }
    while (!q.empty()) {
        auto [x, y, z] = q.top();
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny]) continue;
            if (h[nx][ny] <= t) {
                q.push({nx, ny, h[nx][ny]});
                vis[nx][ny] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m >> y;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> h[i][j];
        }
    }
    vector<int> res(y + 1);
    for (int i = 1; i <= y; ++i) {
        memset(vis, false, sizeof(vis));
        bfs(i);
        res[i] = n * m - count(vis[0], vis[n], false);
    }
    for (int i = 1; i <= y; ++i) {
        cout << res[i] << endl;
    }
    return 0;
}