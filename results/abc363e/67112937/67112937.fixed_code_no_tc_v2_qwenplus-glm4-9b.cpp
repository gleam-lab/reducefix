#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Define the structure for the priority queue, which will store the elevation and coordinates
struct Node {
    int h, x, y;
    bool operator<(const Node& other) const {
        return h < other.h; // The priority queue will prioritize based on the elevation
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Priority queue to perform the BFS by elevation
    priority_queue<Node> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Initialize the priority queue with the borders of the island
    for (int i = 0; i < H; ++i) {
        pq.push({A[i][0], i, 0});
        pq.push({A[i][W - 1], i, W - 1});
        visited[i][0] = visited[i][W - 1] = true;
    }
    for (int j = 0; j < W; ++j) {
        pq.push({A[0][j], 0, j});
        pq.push({A[H - 1][j], H - 1, j});
        visited[0][j] = visited[H - 1][j] = true;
    }

    vector<int> level(H * W, 0); // To store the elevation of each cell
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            level[i * W + j] = A[i][j];
        }
    }

    // We will simulate the flood fill by elevation
    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        // Check all 4 neighbors
        for (int d = 0; d < 4; ++d) {
            int nx = current.x + (d == 0 ? 0 : (d == 1 ? -1 : (d == 2 ? 0 : 1)));
            int ny = current.y + (d == 3 ? 0 : (d == 0 ? 1 : (d == 1 ? 1 : -1)));
            if (nx < 0 || nx >= H || ny < 0 || ny >= W || visited[nx][ny]) continue;
            if (level[nx * W + ny] < current.h + 1) continue; // Only sink if the neighbor is lower

            visited[nx][ny] = true;
            pq.push({level[nx * W + ny], nx, ny});
        }
    }

    // Calculate the remaining area above the sea level after each year
    long long remaining_area = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!visited[i][j]) {
                remaining_area++;
            }
        }
    }

    // Output the remaining area for each year
    for (int year = 0; year < Y; ++year) {
        cout << remaining_area << '\n';
    }

    return 0;
}