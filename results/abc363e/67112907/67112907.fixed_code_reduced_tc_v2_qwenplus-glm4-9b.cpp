#include <bits/stdc++.h>
using namespace std;

const int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> grid(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    // Use a 2D vector to keep track of visited cells
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    queue<pair<int, int>> q;

    // Initialize the queue with the cells that are initially underwater
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] <= 0) {
                visited[i][j] = true;
                q.push({i, j});
            }
        }
    }

    // Process the queue
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int nx = x + d[k][0], ny = y + d[k][1];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && grid[nx][ny] <= 0) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    // Calculate the remaining area
    int remaining_area = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!visited[i][j]) {
                remaining_area++;
            }
        }
    }

    // Output the remaining area for each year
    for (int year = 0; year < Y; year++) {
        cout << remaining_area << '\n';
    }

    return 0;
}