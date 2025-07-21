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

    // Initialize the border cells (sea level starts at 0)
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.emplace(A[i][j], i, j);
                visited[i][j] = true;
            }
        }
    }

    // Total land area
    int remaining = H * W;

    // Events: store how many cells get submerged at each year
    vector<int> submerge_events(Y + 2, 0); // up to Y+1 to avoid overflow

    while (!pq.empty()) {
        auto [height, x, y] = pq.top();
        pq.pop();

        // If this height is beyond our max year, no more processing needed
        if (height > Y) continue;

        // Count this cell as submerged
        submerge_events[height]++;

        // Flood fill to adjacent non-visited cells
        for (auto [dx, dy] : d) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                visited[nx][ny] = true;
                pq.emplace(A[nx][ny], nx, ny);
            }
        }
    }

    // Compute and output results
    vector<int> result(Y);
    int total_submerged = 0;
    for (int i = 1; i <= Y; ++i) {
        total_submerged += submerge_events[i];
        result[i - 1] = remaining - total_submerged;
    }

    for (int i = 0; i < Y; ++i) {
        cout << result[i] << '\n';
    }

    return 0;
}