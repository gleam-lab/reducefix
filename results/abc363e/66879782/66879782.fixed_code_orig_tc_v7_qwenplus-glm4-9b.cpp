#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int h, w, y;
    cin >> h >> w >> y;

    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(h, vector<bool>(w, false));

    // Function to perform BFS and mark the cells to be submerged
    auto bfs = [&](int r, int c) {
        queue<pair<int, int>> q;
        q.push({r, c});
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (visited[x][y]) continue;
            visited[x][y] = true;
            for (int dr = -1; dr <= 1; ++dr) {
                for (int dc = -1; dc <= 1; ++dc) {
                    int nx = x + dr, ny = y + dc;
                    if (nx >= 0 && nx < h && ny >= 0 && ny < w && grid[nx][ny] <= y && !visited[nx][ny]) {
                        q.push({nx, ny});
                    }
                }
            }
        }
    };

    // Simulate the rising sea level
    for (int year = 0; year < y; ++year) {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (grid[i][j] <= year && !visited[i][j]) {
                    bfs(i, j);
                }
            }
        }
    }

    // Calculate the remaining area
    long long remaining_area = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!visited[i][j]) {
                remaining_area++;
            }
        }
    }

    // Output the results for each year
    for (int year = 0; year < y; ++year) {
        cout << remaining_area - (h * w - remaining_area) << '\n';
    }

    return 0;
}