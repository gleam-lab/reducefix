#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
int n, m, y;
int h[MAXN][MAXN];
bool vis[MAXN][MAXN];

struct Node {
    int x, y, h;
    bool operator<(const Node& other) const {
        return h > other.h;
    }
};

void bfs(int level) {
    memset(vis, false, sizeof(vis));
    priority_queue<Node> pq;
    for (int i = 0; i < n; ++i) {
        if (h[i][0] > level) pq.push({i, 0, h[i][0]});
        if (h[i][m-1] > level) pq.push({i, m-1, h[i][m-1]});
    }
    for (int j = 1; j < m-1; ++j) {
        if (h[0][j] > level) pq.push({0, j, h[0][j]});
        if (h[n-1][j] > level) pq.push({n-1, j, h[n-1][j]});
    }
    
    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        if (vis[cur.x][cur.y]) continue;
        vis[cur.x][cur.y] = true;
        
        for (int k = 0; k < 4; ++k) {
            int nx = cur.x + d[k][0], ny = cur.y + d[k][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && h[nx][ny] <= level) {
                pq.push({nx, ny, h[nx][ny]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    
    cin >> n >> m >> y;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> h[i][j];
        }
    }
    
    vector<int> res(y);
    for (int i = 1; i <= y; ++i) {
        bfs(i);
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                if (!vis[j][k]) ++cnt;
            }
        }
        res[i-1] = cnt;
    }
    
    for (int i = 0; i < y; ++i) {
        cout << res[i] << '\n';
    }
    
    return 0;
}