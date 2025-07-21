#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int x, y, level;
    bool operator>(const Point& other) const {
        return level > other.level;
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
    
    priority_queue<Point, vector<Point>, greater<Point>> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    
    // Initialize the queue with boundary points
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || j == 0 || i == H - 1 || j == W - 1) {
                pq.push({i, j, grid[i][j]});
                visited[i][j] = true;
            }
        }
    }
    
    // Process each year
    while (Y--) {
        int remainingArea = H * W;
        while (!pq.empty()) {
            Point current = pq.top();
            pq.pop();
            remainingArea -= 1; // Current cell sinks
            
            for (auto& dir : directions) {
                int ni = current.x + dir[0], nj = current.y + dir[1];
                if (ni < 0 || ni >= H || nj < 0 || nj >= W || visited[ni][nj]) continue;
                if (grid[ni][nj] <= current.level) {
                    pq.push({ni, nj, grid[ni][nj]});
                    visited[ni][nj] = true;
                }
            }
        }
        cout << remainingArea << "\n";
    }
    
    return 0;
}