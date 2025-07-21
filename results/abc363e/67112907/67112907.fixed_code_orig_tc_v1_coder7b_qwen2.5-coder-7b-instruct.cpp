#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> vis(H, vector<bool>(W, false));

    auto bfs = [&](int sea_level) {
        queue<pair<int, int>> q;
        for (int i = 0; i < H; ++i) {
            if (!vis[i][0]) {
                q.emplace(i, 0);
                vis[i][0] = true;
            }
            if (!vis[i][W - 1]) {
                q.emplace(i, W - 1);
                vis[i][W - 1] = true;
            }
        }
        for (int j = 1; j < W - 1; ++j) {
            if (!vis[0][j]) {
                q.emplace(0, j);
                vis[0][j] = true;
            }
            if (!vis[H - 1][j]) {
                q.emplace(H - 1, j);
                vis[H - 1][j] = true;
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; ++k) {
                int nx = x + d[k][0], ny = y + d[k][1];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny] && A[nx][ny] <= sea_level) {
                    q.emplace(nx, ny);
                    vis[nx][ny] = true;
                }
            }
        }
    };

    for (int i = 0; i < Y; ++i) {
        bfs(i);
        int ans = 0;
        for (int j = 0; j < H; ++j) {
            for (int k = 0; k < W; ++k) {
                if (!vis[j][k]) {
                    ++ans;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}