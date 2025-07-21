#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> A[i][j];

    vector<vector<bool>> visited(H, vector<bool>(W, false));

    auto valid = [&](int x, int y) {
        return x >= 0 && x < H && y >= 0 && y < W;
    };

    auto bfs = [&](int level) {
        queue<pair<int, int>> q;
        for (int i = 0; i < H; ++i)
            for (int j = 0; j < W; ++j)
                if (!visited[i][j] && A[i][j] > level) {
                    q.emplace(i, j);
                    visited[i][j] = true;
                }

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (auto [dx, dy] : vector<pair<int, int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
                int nx = x + dx, ny = y + dy;
                if (valid(nx, ny) && !visited[nx][ny] && A[nx][ny] > level) {
                    q.emplace(nx, ny);
                    visited[nx][ny] = true;
                }
            }
        }
    };

    vector<int> result(Y);
    for (int level = 0; level <= 1e5; ++level) {
        bfs(level);
        int count = 0;
        for (int i = 0; i < H; ++i)
            for (int j = 0; j < W; ++j)
                if (!visited[i][j])
                    ++count;
        for (int i = 0; i < min(Y, level + 1); ++i)
            result[i] = count;
    }

    for (int i = 0; i < Y; ++i)
        cout << result[i] << '\n';

    return 0;
}