#include <bits/stdc++.h>

using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

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

    vector<vector<bool>> vis(H, vector<bool>(W));

    auto bfs = [&](int h) {
        int ans = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!vis[i][j] && A[i][j] <= h) {
                    q.emplace(i, j);
                    vis[i][j] = true;
                    ++ans;
                }
            }
        }
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny] && A[nx][ny] <= h) {
                    q.emplace(nx, ny);
                    vis[nx][ny] = true;
                    ++ans;
                }
            }
        }
        return ans;
    };

    for (int i = 0; i < Y; ++i) {
        cout << bfs(i) << '\n';
    }

    return 0;
}