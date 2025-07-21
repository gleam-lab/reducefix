#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
int A[MAXN][MAXN];
bool vis[MAXN][MAXN];

const vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void bfs(int H, int W, int targetLevel) {
    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!vis[i][j] && A[i][j] <= targetLevel) {
                q.push({i, j});
                vis[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny] && A[nx][ny] <= targetLevel) {
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    for (int t = 0; t < Y; ++t) {
        memset(vis, false, sizeof(vis));
        bfs(H, W, t);

        int remainingArea = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!vis[i][j]) {
                    ++remainingArea;
                }
            }
        }

        cout << remainingArea << '\n';
    }

    return 0;
}