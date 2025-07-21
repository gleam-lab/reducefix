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

    for (int t = 0; t < Y; ++t) {
        vector<vector<bool>> visited(H, vector<bool>(W, false));
        queue<pair<int, int>> q;

        // Add all cells that are initially above the sea level
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (A[i][j] > t) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        // Perform BFS to mark all connected components above the sea level
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; ++k) {
                int nx = x + d[k][0], ny = y + d[k][1];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] > t) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }

        // Count the number of cells still above the sea level
        int remaining_area = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (visited[i][j]) {
                    ++remaining_area;
                }
            }
        }

        cout << remaining_area << '\n';
    }

    return 0;
}