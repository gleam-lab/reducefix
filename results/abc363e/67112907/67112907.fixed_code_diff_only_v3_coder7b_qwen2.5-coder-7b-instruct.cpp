#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
int A[MAXN][MAXN];
bool vis[MAXN][MAXN];
int H, W, Y;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void bfs(int level) {
    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!vis[i][j] && A[i][j] > level) {
                q.push({i, j});
                vis[i][j] = true;
            }
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny] && A[nx][ny] > level) {
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }
}

int main() {
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    for (int i = 0; i <= Y; ++i) {
        bfs(i);
        int count = 0;
        for (int j = 0; j < H; ++j) {
            for (int k = 0; k < W; ++k) {
                if (!vis[j][k]) {
                    ++count;
                }
            }
        }
        cout << count << '\n';
        memset(vis, false, sizeof(vis));
    }
    return 0;
}