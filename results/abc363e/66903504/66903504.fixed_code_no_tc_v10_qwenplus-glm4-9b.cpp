#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Directions for neighbors: up, down, left, right
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    vector<queue<P>> levels(H * W + 1);
    ll initial_area = 0;

    // Initialize the queue with the edges of the island
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] >= 0) {
                levels[A[i][j]].push({i, j});
                initial_area++;
            }
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                visited[i][j] = true;
            }
        }
    }

    // Process each year
    for (int year = 1; year <= Y; ++year) {
        ll area_this_year = 0;
        for (int level = year; level < H * W + 1; ++level) {
            while (!levels[level].empty()) {
                auto [x, y] = levels[level].front();
                levels[level].pop();
                visited[x][y] = true;
                area_this_year++;
                for (const auto &dir : directions) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] > level) {
                        levels[level].push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        cout << initial_area - area_this_year << '\n';
    }

    return 0;
}