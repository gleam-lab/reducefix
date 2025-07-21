#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> grid(h, vector<int>(w));
    
    // Read the elevation grid
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    // Queue to process cells that will sink
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    // Initialize the queue with boundary cells and cells at the boundary elevation
    for (int i = 0; i < h; ++i) {
        if (!visited[i][0]) q.push({i, 0});
        if (!visited[i][w - 1]) q.push({i, w - 1});
        visited[i][0] = visited[i][w - 1] = true;
    }
    for (int j = 1; j < w - 1; ++j) {
        if (!visited[0][j]) q.push({0, j});
        if (!visited[h - 1][j]) q.push({h - 1, j});
        visited[0][j] = visited[h - 1][j] = true;
    }

    // Process the queue for each year
    for (int year = 0; year < y; ++year) {
        int remaining_area = 0;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            // Check all 4 possible directions
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && grid[nx][ny] < grid[x][y] + 1) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                        remaining_area++;
                    }
                }
            }
        }
        cout << remaining_area << endl;
    }

    return 0;
}