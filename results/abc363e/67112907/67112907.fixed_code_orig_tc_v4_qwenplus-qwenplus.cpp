#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int dx[4] = {0, 1, 0, -1};
constexpr int dy[4] = {1, 0, -1, 0};

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

    // We will use a priority queue to simulate the island erosion process
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Mark all boundary cells and add them to the priority queue
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.emplace(A[i][j], i, j);
                visited[i][j] = true;
            }
        }
    }

    // Total area of the island
    int remaining = H * W;

    // Answer array to store results for each year
    vector<int> ans(Y + 1, 0);
    ans[0] = remaining;

    // Process in order of increasing elevation
    while (!pq.empty()) {
        auto [h, x, y] = pq.top();
        pq.pop();

        // h is the year when this cell gets submerged
        if (h > Y) continue;

        --remaining;
        ans[h] = remaining;

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                visited[nx][ny] = true;
                pq.emplace(A[nx][ny], nx, ny);
            }
        }
    }

    // For years where no change occurred, carry forward the previous value
    for (int i = 1; i <= Y; ++i) {
        if (ans[i] == 0) {
            ans[i] = ans[i - 1];
        }
    }

    // Output the result for each year
    for (int i = 1; i <= Y; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}