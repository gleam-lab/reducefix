#include <iostream>
#include <vector>
#include <queue>
#include <limits>

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

    // Directions for the 4 possible movements (right, left, down, up)
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    // Priority queue to store the cells to be processed
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    // Visited array to keep track of visited cells
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Initialize the queue with the cells on the border of the island
    for (int i = 0; i < H; i++) {
        pq.push({A[i][0], {i, 0}});
        visited[i][0] = true;
        pq.push({A[i][W - 1], {i, W - 1}});
        visited[i][W - 1] = true;
    }
    for (int j = 0; j < W; j++) {
        pq.push({A[0][j], {0, j}});
        visited[0][j] = true;
        pq.push({A[H - 1][j], {H - 1, j}});
        visited[H - 1][j] = true;
    }

    // Function to make sure the coordinates are within bounds
    auto isValid = [&](int x, int y) {
        return x >= 0 && x < H && y >= 0 && y < W;
    };

    // Process the queue
    while (!pq.empty()) {
        auto [height, pos] = pq.top();
        pq.pop();
        int x = pos.first, y = pos.second;

        // Check all adjacent cells
        for (auto& dir : directions) {
            int nx = x + dir.first, ny = y + dir.second;
            if (!isValid(nx, ny)) continue;
            if (visited[nx][ny]) continue;
            if (A[nx][ny] <= height + 1) {
                visited[nx][ny] = true;
                pq.push({A[nx][ny], {nx, ny}});
            }
        }
    }

    // Calculate and output the remaining area
    int remainingArea = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (!visited[i][j]) {
                remainingArea += 1;
            }
        }
    }
    for (int year = 0; year < Y; year++) {
        cout << remainingArea << '\n';
    }

    return 0;
}