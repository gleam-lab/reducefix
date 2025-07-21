#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int H, W, Y;
int A[MAXN][MAXN], B[MAXN][MAXN];
bool vis[MAXN][MAXN];

void bfs(int h) {
    queue<pair<int, int>> q;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (B[i][j] > h && !vis[i][j]) {
                q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (abs(dx) + abs(dy) != 1) continue;
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if (B[nx][ny] <= h || vis[nx][ny]) continue;
                q.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (B[i][j] > h && !vis[i][j]) {
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
            B[i][j] = A[i][j];
        }
    }
    sort(A[0], A[H]);
    int last = 0, cur = 1;
    for (int i = 0; i < H * W; ++i) {
        if (A[i] != A[last]) {
            for (int j = last; j < i; ++j) {
                B[(j / W)][j % W] = A[cur];
            }
            last = i, cur++;
        }
    }
    for (int i = last; i < H * W; ++i) {
        B[(i / W)][i % W] = A[cur];
    }
    for (int i = 1; i <= Y; ++i) {
        bfs(i);
    }
    return 0;
}