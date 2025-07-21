#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

struct Init {
    Init() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout << fixed << setprecision(12);
    }
} init;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (auto& row : A) {
        for (auto& val : row) {
            cin >> val;
        }
    }

    // We'll use a visited matrix to mark which cells are submerged
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    using Cell = tuple<int, int, int>;  // height, x, y

    priority_queue<Cell, vector<Cell>, greater<Cell>> pq;

    // Initialize the queue with the border cells
    for (int i = 0; i < H; ++i) {
        for (int j : {0, W - 1}) {
            if (!visited[i][j]) {
                visited[i][j] = true;
                pq.emplace(A[i][j], i, j);
            }
        }
    }

    for (int j = 1; j < W - 1; ++j) {
        for (int i : {0, H - 1}) {
            if (!visited[i][j]) {
                visited[i][j] = true;
                pq.emplace(A[i][j], i, j);
            }
        }
    }

    int remaining = H * W;
    vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<int> ans(Y + 1, 0);  // Store answers for each year

    // Process the PQ only once and record when each year's area is known
    while (!pq.empty()) {
        auto [height, x, y] = pq.top();
        pq.pop();

        // If the sea level is already at or above this cell's height,
        // it means the island shrinks this year
        int year = min(height, Y);
        ans[year] = remaining;

        // This cell gets submerged, decrease remaining count
        remaining--;

        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                visited[nx][ny] = true;
                pq.emplace(A[nx][ny], nx, ny);
            }
        }
    }

    // Fill in any missing years using previous values (because some years may not change)
    for (int i = 1; i <= Y; ++i) {
        if (ans[i] == 0) ans[i] = ans[i - 1];
    }

    // Output the result for each year from 1 to Y
    for (int i = 1; i <= Y; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}