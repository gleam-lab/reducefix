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

    vector<vector<bool>> visited(H, vector<bool>(W, false));

    auto bfs = [&](int sea_level) {
        queue<pair<int, int>> q;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j] && A[i][j] > sea_level) {
                    q.emplace(i, j);
                    visited[i][j] = true;
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : d) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] > sea_level) {
                    q.emplace(nx, ny);
                    visited[nx][ny] = true;
                }
            }
        }
    };

    for (int i = 0; i < Y; ++i) {
        bfs(i);
        int count = 0;
        for (int j = 0; j < H; ++j) {
            for (int k = 0; k < W; ++k) {
                if (!visited[j][k]) {
                    ++count;
                }
            }
        }
        cout << count << '\n';
        fill(visited.begin(), visited.end(), false); // Reset visited array for next iteration
    }

    return 0;
}