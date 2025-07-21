#include <bits/stdc++.h>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> grid(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    // Directions for the 4 possible neighbors
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    queue<pair<int, int>> q;

    // Initialize the queue with all the edges of the grid
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    // Perform BFS to simulate the sinking process
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= H || ny < 0 || ny >= W || visited[nx][ny] || grid[nx][ny] <= Y - 1) continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    // Calculate the remaining area
    int remainingArea = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!visited[i][j]) {
                remainingArea++;
            }
        }
    }

    cout << remainingArea << endl;

    return 0;
}