#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Cell {
    int h, x, y;
    bool operator<(const Cell& c) const {
        return h < c.h;
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
    
    priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
    vector<vector<int>> visited(H, vector<int>(W, 0));

    // Initialize the priority queue with boundary cells
    for (int i = 0; i < W; ++i) {
        if (visited[0][i]) continue;
        pq.push({grid[0][i], 0, i});
        visited[0][i] = 1;

        if (visited[H-1][i]) continue;
        pq.push({grid[H-1][i], H-1, i});
        visited[H-1][i] = 1;
    }
    
    for (int i = 1; i < H-1; ++i) {
        if (visited[i][0]) continue;
        pq.push({grid[i][0], i, 0});
        visited[i][0] = 1;

        if (visited[i][W-1]) continue;
        pq.push({grid[i][W-1], i, W-1});
        visited[i][W-1] = 1;
    }

    int remainingArea = H * W;
    while (!pq.empty()) {
        Cell c = pq.top(); pq.pop();
        if (c.h < Y) {
            remainingArea--;
            int x = c.x, y = c.y;
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && grid[nx][ny] <= Y) {
                        pq.push({grid[nx][ny], nx, ny});
                        visited[nx][ny] = 1;
                    }
                }
            }
        }
    }

    cout << remainingArea << '\n';
    return 0;
}