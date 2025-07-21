#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1010;
int h, w, y;
int a[N][N];
bool vis[N][N];

struct node {
    int x, y, z;
    bool operator<(const node &b) const {
        return z > b.z;
    }
};

void bfs(int level) {
    priority_queue<node> q;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            if (!vis[i][j] && a[i][j] <= level) {
                q.push({i, j, a[i][j]});
                vis[i][j] = true;
            }
    
    while (!q.empty()) {
        auto [x, y, z] = q.top();
        q.pop();
        
        for (int k = 0; k < 4; ++k) {
            int nx = x + d[k][0], ny = y + d[k][1];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w || vis[nx][ny])
                continue;
            if (a[nx][ny] <= level) {
                q.push({nx, ny, a[nx][ny]});
                vis[nx][ny] = true;
            }
        }
    }
}

int main() {
    cin >> h >> w >> y;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> a[i][j];
    
    for (int i = 1; i <= y; ++i) {
        memset(vis, false, sizeof(vis));
        bfs(i);
        cout << (h * w - count_if(vis[0], vis[h], [](auto &row) { return count(row.begin(), row.end(), true) == w; })) << '\n';
    }
    
    return 0;
}