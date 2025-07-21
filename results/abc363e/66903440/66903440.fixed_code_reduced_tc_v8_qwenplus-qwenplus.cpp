#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Total area initially
    int remaining = H * W;

    // visited matrix to mark if a cell is processed or not
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Queue for BFS processing
    queue<pair<int, int>> q;

    // Initialize the borders as visited and process them
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                visited[i][j] = true;
                q.push({i, j});
            }
        }
    }

    // Decrease remaining area when a cell is processed
    remaining -= q.size();

    // Directions: up, down, left, right
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // Process all years
    vector<int> result(Y + 1);
    for (int year = 1; year <= Y; ++year) {
        result[year] = remaining;

        // Only process cells whose elevation equals current year
        queue<pair<int, int>> new_q;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j] && A[i][j] == year) {
                    visited[i][j] = true;
                    new_q.push({i, j});
                }
            }
        }

        while (!new_q.empty()) {
            auto [x, y] = new_q.front();
            new_q.pop();
            remaining--;

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    new_q.push({nx, ny});
                }
            }
        }
    }

    // Output results
    for (int i = 1; i <= Y; ++i) {
        cout << result[i] << "\n";
    }

    return 0;
}