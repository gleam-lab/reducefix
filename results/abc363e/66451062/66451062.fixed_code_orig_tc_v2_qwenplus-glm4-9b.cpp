#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Point {
    int x, y, height;
};

int main() {
    int h, w, y;
    cin >> h >> w >> y;

    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    priority_queue<Point, vector<Point>, greater<Point>> pq;
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    // Initialize the priority queue with all the edges and their heights
    for (int i = 0; i < h; ++i) {
        pq.push({i, 0, grid[i][0]});
        pq.push({i, w - 1, grid[i][w - 1]});
        visited[i][0] = visited[i][w - 1] = true;
    }
    for (int j = 1; j < w - 1; ++j) {
        pq.push({0, j, grid[0][j]});
        pq.push({h - 1, j, grid[h - 1][j]});
        visited[0][j] = visited[h - 1][j] = true;
    }

    int area_above_sea_level = h * w;
    int sea_level = 1;

    while (pq.size() > 0 && sea_level <= y) {
        area_above_sea_level = 0; // Reset the area for each year
        while (!pq.empty() && pq.top().height <= sea_level) {
            Point p = pq.top(); pq.pop();
            // Calculate the area for this point
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    int nx = p.x + i, ny = p.y + j;
                    if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && grid[nx][ny] > sea_level) {
                        visited[nx][ny] = true;
                        pq.push({nx, ny, grid[nx][ny]});
                    }
                }
            }
        }
        sea_level++; // Increase the sea level after processing the sinking
        cout << area_above_sea_level << endl;
    }

    return 0;
}