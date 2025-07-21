#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
int H, W, Y;
int A[MAXN][MAXN];
bool vis[MAXN][MAXN];

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
        auto [x, y] = q.front(); q.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = x + d[k][0], ny = y + d[k][1];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny] && A[nx][ny] > level) {
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    vector<int> ans(Y + 1);
    for (int i = 0; i <= Y; ++i) {
        fill(vis, vis + H, false);
        bfs(i);
        for (int j = 0; j < H; ++j) {
            for (int k = 0; k < W; ++k) {
                if (!vis[j][k]) ans[i]++;
            }
        }
    }
    for (int i = 1; i <= Y; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}