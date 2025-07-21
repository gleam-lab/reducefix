#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int h[N], w[N], y;
bool vis[N][N];

void bfs(int sea_level) {
    queue<pair<int, int>> q;
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < h[0]; ++i) if (h[i] > sea_level && !vis[i][0]) {
        q.push({i, 0});
        vis[i][0] = true;
    }
    for (int i = 1; i < w[0]; ++i) if (w[i] > sea_level && !vis[0][i]) {
        q.push({0, i});
        vis[0][i] = true;
    }
    for (int i = 1; i < h[0]; ++i) if (h[i] > sea_level && !vis[i][w[0]-1]) {
        q.push({i, w[0]-1});
        vis[i][w[0]-1] = true;
    }
    for (int i = 0; i < w[0]-1; ++i) if (w[i] > sea_level && !vis[h[0]-1][i]) {
        q.push({h[0]-1, i});
        vis[h[0]-1][i] = true;
    }
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int dx = -1; dx <= 1; ++dx) for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < h[0] && ny >= 0 && ny < w[0] && !vis[nx][ny] && h[nx] > sea_level) {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> h[0] >> w[0] >> y;
    for (int i = 0; i < h[0]; ++i) for (int j = 0; j < w[0]; ++j) cin >> h[i][j] >> w[i][j];
    sort(h, h+h[0]);
    sort(w, w+w[0]);
    vector<int> areas(y+1, h[0]*w[0]);
    for (int i = 1; i <= y; ++i) {
        bfs(i-1);
        for (int j = 0; j < h[0]; ++j) for (int k = 0; k < w[0]; ++k) {
            if (vis[j][k]) areas[i] -= (h[j] > i-1 && w[k] > i-1);
        }
    }
    for (int i = 1; i <= y; ++i) cout << areas[i] << endl;
    return 0;
}