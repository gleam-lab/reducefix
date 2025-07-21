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

    // Directions for flood fill (up, down, left, right)
    const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    // Initialize the queue with all cells at sea level
    for (int i = 0; i < h; ++i) {
        q.push({i, 0});
        visited[i][0] = true;
        q.push({i, w - 1});
        visited[i][w - 1] = true;
    }
    for (int i = 1; i < w - 1; ++i) {
        q.push({0, i});
        visited[0][i] = true;
        q.push({h - 1, i});
        visited[h - 1][i] = true;
    }

    // Total area of land initially
    int totalLand = h * w;

    // Process the queue for Y years
    for (int year = 0; year < y; ++year) {
        int currentYearLand = totalLand;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            int level = grid[x][y];
            for (auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
                    if (!visited[nx][ny] && grid[nx][ny] < level) {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        // Output the remaining land area
        cout << totalLand - currentYearLand << endl;
    }

    return 0;
}