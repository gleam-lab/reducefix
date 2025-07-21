#include<bits/stdc++.h>
using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<int>> F(H + 1, vector<int>(W + 1, -1)); // extra layer for boundary conditions
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // up, right, down, left

    // Read the elevation matrix
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Initialize flood fill
    queue<pair<int, int>> q;
    F[1][1] = A[0][0];
    q.push({0, 0});

    // Perform flood fill
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (F[nx + 1][ny + 1] != -1) continue;
            if (A[nx][ny] < F[x + 1][y + 1]) continue; // cell is not higher than the current highest
            F[nx + 1][ny + 1] = A[nx][ny];
            q.push({nx, ny});
        }
    }

    // Process each year
    long long remaining_area = H * W;
    for (int i = 0; i < Y; ++i) {
        long long to_sink = 0;
        for (int x = 0; x < H; ++x) {
            for (int y = 0; y < W; ++y) {
                if (A[x][y] <= i && F[x + 1][y + 1] != -1) {
                    // This cell and its region will sink
                    to_sink += F[x + 1][y + 1];
                    A[x][y] = 0;
                    F[x + 1][y + 1] = -1; // No longer above sea level
                }
            }
        }
        remaining_area -= to_sink;
        cout << remaining_area << endl;
    }

    return 0;
}