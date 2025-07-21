#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
int h, w, y;
int a[N][N];
bool vis[N][N];

int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};

void bfs(int sea_level) {
    queue<pair<int, int>> q;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j) {
            if (!vis[i][j] && a[i][j] > sea_level) {
                q.push({i, j});
                vis[i][j] = true;
            }
        }
    int count = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        count++;
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny] && a[nx][ny] > sea_level) {
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }
    cout << h * w - count << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> h >> w >> y;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> a[i][j];
    sort(a[0], a[h]);
    int last = a[0][w - 1];
    for (int i = 0; i <= y; ++i) {
        memset(vis, false, sizeof vis);
        bfs(last);
        last++;
    }
    return 0;
}