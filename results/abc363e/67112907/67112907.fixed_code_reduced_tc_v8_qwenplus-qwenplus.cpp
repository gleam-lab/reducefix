#include <bits/stdc++.h>
using namespace std;

constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {1, 0, -1, 0};

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

    // Initialize visited matrix
    vector<vector<bool>> vis(H, vector<bool>(W, false));

    // Priority queue to process cells by elevation
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    // Push boundary cells into the priority queue
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                vis[i][j] = true;
                pq.emplace(A[i][j], i, j);
            }
        }
    }

    int remaining = H * W;

    // Array to store results for each year
    vector<int> result(Y);

    // Process years in reverse using events
    vector<vector<int>> elevation_events(Y + 2);  // Store which years cause a drop in elevation

    while (!pq.empty()) {
        auto [h, x, y] = pq.top();
        pq.pop();

        // Record this cell sinking at its height h
        if (h <= Y) {
            elevation_events[h].push_back(1);
        }

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
                vis[nx][ny] = true;
                pq.emplace(max(h, A[nx][ny]), nx, ny);  // Propagate with max of current and neighbor
            }
        }
    }

    // Build prefix sum of changes
    vector<int> change(Y + 2, 0);
    for (int y = 1; y <= Y; ++y) {
        for (auto &delta : elevation_events[y]) {
            change[y] += delta;
        }
    }

    // Apply changes over years
    for (int y = 1; y <= Y; ++y) {
        remaining -= change[y];
        cout << remaining << '\n';
    }

    return 0;
}