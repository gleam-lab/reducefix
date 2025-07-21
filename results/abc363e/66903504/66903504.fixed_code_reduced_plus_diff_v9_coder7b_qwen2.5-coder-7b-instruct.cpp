#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    vector<vector<int>> result(Y + 1, vector<int>(H * W, H * W));

    for (int y = 1; y <= Y; ++y) {
        queue<pair<int, int>> q;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j] && A[i][j] > y) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            result[y][x]--;

            static const array<pair<int, int>, 4> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= y) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    for (int i = 1; i <= Y; ++i) {
        cout << result[i][0] << endl;
    }

    return 0;
}