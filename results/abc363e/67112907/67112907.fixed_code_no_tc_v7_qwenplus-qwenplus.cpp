#include <bits/stdc++.h>

using namespace std;

constexpr int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

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

    // Create a grid to track whether a cell is submerged
    vector<vector<bool>> submerged(H, vector<bool>(W, false));

    // Priority queue to process cells in increasing order of elevation
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    // Mark boundary cells and push them into the priority queue
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.emplace(A[i][j], i, j);
                submerged[i][j] = true;
            }
        }
    }

    // Array to store the remaining area at each year
    vector<int> result(Y + 1, H * W); // Initialize with full area

    // Process the priority queue
    while (!pq.empty()) {
        int h, x, y;
        tie(h, x, y) = pq.top();
        pq.pop();

        // If this height is higher than current sea level, stop processing
        // We'll keep track of how many years have passed to update the answer
        // We use the fact that we process cells in increasing order of elevation
        if (h > Y) continue;

        // For all years from current sea level up to Y, decrease the area
        // But instead of updating every year, we can compute final state first
        // Then fill the result accordingly

        for (int k = 0; k < 4; ++k) {
            int nx = x + d[k][0];
            int ny = y + d[k][1];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !submerged[nx][ny]) {
                submerged[nx][ny] = true;
                pq.emplace(A[nx][ny], nx, ny);
            }
        }
    }

    // Count total submerged cells
    int submerged_cells = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (submerged[i][j]) {
                submerged_cells++;
            }
        }
    }

    // Compute the area above water for each year
    vector<int> year_area(Y + 1, H * W);
    for (int i = 1; i <= Y; ++i) {
        year_area[i] = max(0, H * W - submerged_cells);
    }

    // Print results
    for (int i = 1; i <= Y; ++i) {
        cout << year_area[i] << "\n";
    }

    return 0;
}