#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq; // (height, row, col)

    // Initialize the priority queue with the edges of the grid
    for (int j = 0; j < W; j++) {
        if (!visited[0][j]) pq.push({A[0][j], 0, j});
        if (!visited[H-1][j]) pq.push({A[H-1][j], H-1, j});
    }
    for (int i = 0; i < H; i++) {
        if (!visited[i][0]) pq.push({A[i][0], i, 0});
        if (!visited[i][W-1]) pq.push({A[i][W-1], i, W-1});
    }

    int total_area = H * W;
    while (!pq.empty()) {
        auto [h, x, y] = pq.top();
        pq.pop();
        if (h > Y) break; // Only need to process heights less than or equal to Y

        if (visited[x][y]) continue;
        visited[x][y] = true;
        total_area--;

        // Check all adjacent cells
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= H || ny < 0 || ny >= W || visited[nx][ny]) continue;
                if (A[nx][ny] <= h) pq.push({A[nx][ny], nx, ny});
            }
        }
    }

    for (int year = 1; year <= Y; year++) {
        cout << total_area << '\n';
        while (!pq.empty()) {
            auto [h, x, y] = pq.top();
            pq.pop();
            // Check all adjacent cells
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int nx = x + dx, ny = y + dy;
                    if (nx < 0 || nx >= H || ny < 0 || ny >= W || visited[nx][ny]) continue;
                    if (A[nx][ny] <= h) pq.push({A[nx][ny], nx, ny});
                }
            }
        }
    }

    return 0;
}