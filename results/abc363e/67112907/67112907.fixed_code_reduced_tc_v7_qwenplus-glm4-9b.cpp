#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    int h, w, y;
    cin >> h >> w >> y;

    vector<vector<int>> heights(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> heights[i][j];
        }
    }

    for (int year = 0; year < y; ++year) {
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        queue<Point> q;
        int remainingArea = 0;

        // Initialize the queue with all points above the current sea level
        int seaLevel = year;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (heights[i][j] > seaLevel && !visited[i][j]) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        // Perform BFS
        while (!q.empty()) {
            Point p = q.front();
            q.pop();

            for (auto& dir : {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
                int ni = p.x + dir[0], nj = p.y + dir[1];
                if (ni >= 0 && ni < h && nj >= 0 && nj < w && !visited[ni][nj] && heights[ni][nj] > seaLevel) {
                    q.push({ni, nj});
                    visited[ni][nj] = true;
                }
            }
        }

        // Count remaining area
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (visited[i][j]) {
                    remainingArea++;
                }
            }
        }

        cout << remainingArea << '\n';
    }

    return 0;
}