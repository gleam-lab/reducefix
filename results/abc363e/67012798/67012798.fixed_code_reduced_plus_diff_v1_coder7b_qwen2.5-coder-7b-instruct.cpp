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
    queue<pair<int, int>> q;

    // Initial queue setup: Add cells that are already submerged
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] <= 0) {
                visited[i][j] = true;
                q.push({i, j});
            }
        }
    }

    vector<int> result(Y, 0);

    for (int sea_level = 1; sea_level <= Y; sea_level++) {
        int count = 0;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (visited[x][y]) continue;
            visited[x][y] = true;
            count++;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= sea_level) {
                    q.push({nx, ny});
                }
            }
        }

        result[Y - sea_level] = count;
    }

    for (const auto &val : result) {
        cout << val << endl;
    }

    return 0;
}