#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int H, W, Y;
vector<vector<int>> A(MAXN, vector<int>(MAXN));
vector<vector<bool>> F(MAXN, vector<bool>(MAXN, true));
vector<queue<pair<int, int>>> Q(2 * MAXN * MAXN);

int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

void bfs(int sea_level) {
    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!F[i][j] && A[i][j] <= sea_level) {
                F[i][j] = true;
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int k = 0; k < 8; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !F[nx][ny] && A[nx][ny] <= sea_level) {
                F[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                F[i][j] = false;
                Q[A[i][j]].push({i, j});
            }
        }
    }

    int ans = H * W;
    for (int sea_level = 1; sea_level <= Y; ++sea_level) {
        while (!Q[sea_level].empty()) {
            auto [x, y] = Q[sea_level].front(); Q[sea_level].pop();
            --ans;
            for (int k = 0; k < 8; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && F[nx][ny]) {
                    F[nx][ny] = false;
                    Q[max(A[nx][ny], sea_level)].push({nx, ny});
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}