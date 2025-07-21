#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int x, y, h;
};

struct Compare {
    bool operator()(const Point& a, const Point& b) {
        return a.h > b.h;
    }
};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> grid(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    priority_queue<Point, vector<Point>, Compare> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Initialize the priority queue with the edges of the grid
    for (int j = 0; j < W; ++j) {
        pq.push({0, j, grid[0][j]});
        visited[0][j] = true;
    }
    for (int i = 0; i < H; ++i) {
        pq.push({0, i, grid[i][0]});
        visited[i][0] = true;
    }
    for (int j = 1; j < W; ++j) {
        pq.push({0, j, grid[0][j]});
        visited[0][j] = true;
    }
    for (int i = 1; i < H; ++i) {
        pq.push({0, i, grid[i][0]});
        visited[i][0] = true;
    }

    int remaining_area = H * W;
    while (!pq.empty()) {
        Point p = pq.top();
        pq.pop();
        if (p.h > Y) break;
        remaining_area -= grid[p.x][p.y];
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                int nx = p.x + dx, ny = p.y + dy;
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    pq.push({p.h + 1, nx, grid[nx][ny]});
                }
            }
        }
    }

    cout << remaining_area << "\n";
    return 0;
}