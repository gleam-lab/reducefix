#include <bits/stdc++.h>

using namespace std;

constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> island(H, vector<bool>(W, true));
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    vector<queue<pair<int, int>>> q(1e5 + 5);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    // Initialize border cells to be processed at their respective elevations
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                q[A[i][j]].push({i, j});
                visited[i][j] = true;
            }
        }
    }

    int ans = H * W;

    for (int i = 1; i <= Y; i++) {
        while (!q[i].empty()) {
            auto [x, y] = q[i].front();
            q[i].pop();

            if (island[x][y]) {
                island[x][y] = false;
                ans--;
            }

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
                if (visited[nx][ny]) continue;

                if (A[nx][ny] <= i) {
                    q[i].push({nx, ny});
                    visited[nx][ny] = true;
                } else {
                    q[A[nx][ny]].push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}