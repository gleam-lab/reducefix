#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Directions for adjacent cells
    const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // Priority queue to process cells by height
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Initialize the priority queue with the edges of the grid
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!visited[i][j]) {
                pq.push({A[i][j], {i, j}});
                visited[i][j] = true;
            }
        }
    }

    long long remaining_area = H * W;  // Start with the total area

    // Process the cells in increasing order of their height
    while (pq.size()) {
        auto [height, pos] = pq.top();
        pq.pop();

        // If the current height is less than the number of years Y, simulate the sinking
        if (height < Y) {
            remaining_area -= 1;  // This cell will sink
            for (const auto& dir : directions) {
                int nx = pos.first + dir.first;
                int ny = pos.second + dir.second;
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                    pq.push({A[nx][ny], {nx, ny}});
                    visited[nx][ny] = true;
                }
            }
        }
    }

    // Output the remaining area for each year
    for (int i = 0; i < Y; ++i) {
        cout << remaining_area << '\n';
    }

    return 0;
}