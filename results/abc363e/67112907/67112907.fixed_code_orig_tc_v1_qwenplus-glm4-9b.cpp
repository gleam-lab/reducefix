#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> land(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> land[i][j];
        }
    }

    // Directions for the flood fill algorithm
    vector<Point> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // Queue for the flood fill
    queue<Point> q;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Initialize the queue with land sections that will sink immediately (sea level = 0)
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (land[i][j] == 0) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    // Simulate the sinking each year
    for (int year = 1; year <= Y; year++) {
        int area = 0;
        queue<Point> newQ;
        
        while (!q.empty()) {
            Point p = q.front();
            q.pop();
            area++;

            for (Point dir : directions) {
                int nx = p.x + dir.x;
                int ny = p.y + dir.y;

                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && land[nx][ny] == 0) {
                    visited[nx][ny] = true;
                    newQ.push({nx, ny});
                }
            }
        }

        q = newQ;
        cout << area << "\n";
    }

    return 0;
}