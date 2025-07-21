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
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    vector<queue<pair<int, int>>> q(Y + 1);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if ((i == 0) || (i == H - 1) || (j == 0) || (j == W - 1)) {
                q[A[i][j]].push({i, j});
                visited[i][j] = true;
            }
        }
    }

    int total_land = H * W;
    for (int height = 1; height <= Y; height++) {
        while (!q[height].empty()) {
            auto [x, y] = q[height].front();
            q[height].pop();
            total_land--;
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q[height].push({nx, ny});
                }
            }
        }
        cout << total_land << '\n';
    }

    return 0;
}