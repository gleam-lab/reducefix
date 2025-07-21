#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> vis(H, vector<bool>(W, false));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Priority queue to store cells with their elevation and coordinates
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, less<>> pq;
    // Initialize the queue with the edges of the island
    for (int i = 0; i < H; ++i) {
        pq.emplace(A[i][0], make_pair(i, 0));
        pq.emplace(A[i][W - 1], make_pair(i, W - 1));
        vis[i][0] = vis[i][W - 1] = true;
    }
    for (int j = 1; j < W; ++j) {
        pq.emplace(A[0][j], make_pair(0, j));
        pq.emplace(A[H - 1][j], make_pair(H - 1, j));
        vis[0][j] = vis[H - 1][j] = true;
    }

    // Process the queue
    while (!pq.empty()) {
        auto [h, pos] = pq.top();
        pq.pop();

        int x = pos.first;
        int y = pos.second;
        // If the current elevation is less than or equal to the sea level, it will sink
        if (h <= 0) {
            // Check all 4 adjacent cells
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx < 0 || nx >= H || ny < 0 || ny >= W || vis[nx][ny]) continue;
                    // If adjacent cell is not visited, it can sink
                    if (A[nx][ny] <= 0) {
                        vis[nx][ny] = true;
                        pq.emplace(-A[nx][ny], make_pair(nx, ny));
                    }
                }
            }
        }
    }

    // Count the cells that are not visited (remain above sea level)
    int remainingArea = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!vis[i][j]) {
                remainingArea++;
            }
        }
    }

    // Output the result for each year
    for (int i = 0; i < Y; ++i) {
        cout << remainingArea << '\n';
    }

    return 0;
}