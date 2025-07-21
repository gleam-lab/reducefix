#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

struct Point {
    int x, y;
    bool operator < (const Point& other) const {
        return y > other.y;  // We use y-coordinate for priority queue
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
    
    // Push the cells on the first and last rows/columns into the priority queue
    for (int i = 0; i < H; ++i) {
        pq.push({i, 0});
        pq.push({i, W - 1});
    }
    for (int j = 0; j < W; ++j) {
        pq.push({0, j});
        pq.push({H - 1, j});
    }
    
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    
    int years = 0;
    while (years < Y && !pq.empty()) {
        int remaining = 0;
        while (!pq.empty() && pq.top().y <= years) {
            Point p = pq.top();
            pq.pop();
            if (!visited[p.x][p.y]) {
                visited[p.x][p.y] = true;
                remaining++;
                // Check all 4 adjacent cells
                for (int k = 0; k < 4; ++k) {
                    int nx = p.x + dx[k];
                    int ny = p.y + dy[k];
                    if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && grid[nx][ny] > years) {
                        pq.push({nx, ny});
                    }
                }
            }
        }
        cout << remaining << '\n';
        years++;
    }
    
    return 0;
}