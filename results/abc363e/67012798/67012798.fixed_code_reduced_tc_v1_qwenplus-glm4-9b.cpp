#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> grid(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> flooded(H, vector<bool>(W, false));
    queue<pair<int, int>> q;

    // Initialize the queue with boundary cells
    for (int i = 0; i < H; i++) {
        q.push({i, 0});
        q.push({i, W - 1});
        flooded[i][0] = true;
        flooded[i][W - 1] = true;
    }
    for (int j = 1; j < W - 1; j++) {
        q.push({0, j});
        q.push({H - 1, j});
        flooded[0][j] = true;
        flooded[H - 1][j] = true;
    }

    // Perform BFS to mark flooded cells
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= H || ny < 0 || ny >= W || flooded[nx][ny] || grid[nx][ny] <= grid[x][y] + 1) continue;

            q.push({nx, ny});
            flooded[nx][ny] = true;
        }
    }

    // Count remaining land cells
    int remainingLand = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (!flooded[i][j]) {
                remainingLand++;
            }
        }
    }

    // Output the results for each year
    for (int i = 1; i <= Y; i++) {
        cout << remainingLand << endl;
    }

    return 0;
}