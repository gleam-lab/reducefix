#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int H, W, Y, A[N][N];
bool vis[N][N];

void bfs(int level) {
    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!vis[i][j] && A[i][j] > level) {
                q.emplace(i, j);
                vis[i][j] = true;
            }
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (auto [dx, dy] : vector<pair<int, int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny] && A[nx][ny] > level) {
                q.emplace(nx, ny);
                vis[nx][ny] = true;
            }
        }
    }
}

int main() {
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> A[i][j];

    memset(vis, false, sizeof(vis));
    for (int level = 1; level <= Y; ++level) {
        bfs(level);
        int cnt = 0;
        for (int i = 0; i < H; ++i)
            for (int j = 0; j < W; ++j)
                if (vis[i][j])
                    ++cnt;
        cout << cnt << '\n';
    }
    return 0;
}