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

    // Priority queue to process cells in increasing order of elevation
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Initialize the border cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.emplace(A[i][j], i, j);
                visited[i][j] = true;
            }
        }
    }

    int remaining = H * W;
    vector<int> result(Y + 1, 0);  // result[i] will store area at year i

    // Process using BFS with priority queue
    while (!pq.empty()) {
        auto [height, x, y] = pq.top();
        pq.pop();

        // The cell disappears when sea level reaches its height
        --remaining;

        for (auto [dx, dy] : d) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                visited[nx][ny] = true;
                pq.emplace(A[nx][ny], nx, ny);
            }
        }
    }

    // All areas start sinking from borders, so we calculate survival by subtracting sunk cells
    // We'll track how many cells have been removed at each year
    vector<int> sinkCount(Y + 2, 0);  // Count of cells sunk at exact year i

    // Reset visited and reprocess to track when each cell sinks
    visited.assign(H, vector<bool>(W, false));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq2;

    // Re-initialize the border cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq2.emplace(A[i][j], i, j);
                visited[i][j] = true;
            }
        }
    }

    while (!pq2.empty()) {
        auto [height, x, y] = pq2.top();
        pq2.pop();

        if (height <= Y) {
            sinkCount[height]++;
        }

        for (auto [dx, dy] : d) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                visited[nx][ny] = true;
                pq2.emplace(A[nx][ny], nx, ny);
            }
        }
    }

    // Build prefix sum of sink counts
    vector<int> prefixSink(Y + 1, 0);
    for (int i = 1; i <= Y; ++i) {
        prefixSink[i] = prefixSink[i - 1] + sinkCount[i];
    }

    // Output results using prefix sums
    for (int i = 1; i <= Y; ++i) {
        cout << H * W - prefixSink[i] << "\n";
    }

    return 0;
}