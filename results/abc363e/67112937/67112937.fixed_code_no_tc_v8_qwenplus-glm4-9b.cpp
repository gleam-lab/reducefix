#include <bits/stdc++.h>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    // Priority queue to process cells that will sink each year
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    // Vector to mark cells that have been visited
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Initialize the priority queue with the edges of the island
    for (int i = 0; i < H; i++) {
        pq.push({A[i][0], {i, 0}});
        pq.push({A[i][W - 1], {i, W - 1}});
        visited[i][0] = visited[i][W - 1] = true;
    }
    for (int j = 0; j < W; j++) {
        pq.push({A[0][j], {0, j}});
        pq.push({A[H - 1][j], {H - 1, j}});
        visited[0][j] = visited[H - 1][j] = true;
    }

    // Variable to keep track of the remaining area above sea level
    int remaining_area = H * W;

    // Process the cells that will sink each year
    for (int year = 0; year < Y; year++) {
        while (!pq.empty()) {
            auto [h, pos] = pq.top();
            pq.pop();
            int x = pos.first, y = pos.second;

            // Check adjacent cells and add them to the queue if they will also sink
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int nx = x + dx, ny = y + dy;
                    if (nx < 0 || nx >= H || ny < 0 || ny >= W || A[nx][ny] > h || visited[nx][ny]) continue;
                    visited[nx][ny] = true;
                    pq.push({A[nx][ny], {nx, ny}});
                }
            }
        }

        // Calculate the new remaining area
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (!visited[i][j]) {
                    remaining_area--;
                }
            }
        }

        // Output the remaining area for the current year
        cout << remaining_area << '\n';
    }

    return 0;
}