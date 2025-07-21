#include <bits/stdc++.h>
using namespace std;

constexpr int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    vector<vector<bool>> vis(H, vector<bool>(W, false));

    // Mark the boundary cells and push into priority queue
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                vis[i][j] = true;
                pq.emplace(A[i][j], i, j);
            }
        }
    }

    int ans = H * W;
    vector<int> res(Y + 1); // Store result for each year

    while (!pq.empty()) {
        auto [h, x, y] = pq.top();
        pq.pop();

        // If the current height is <= sea level in future years, decrement area
        while (Y >= h && res[h] == 0) {
            res[h] = ans;
            h--;
        }

        ans--;
        for (int k = 0; k < 4; ++k) {
            int dx = x + d[k][0];
            int dy = y + d[k][1];
            if (dx < 0 || dx >= H || dy < 0 || dy >= W || vis[dx][dy]) continue;
            vis[dx][dy] = true;
            pq.emplace(A[dx][dy], dx, dy);
        }
    }

    // For any remaining years not covered, island size doesn't change
    int curr = ans;
    for (int i = 1; i <= Y; ++i) {
        if (res[i] == 0) {
            res[i] = curr;
        }
    }

    // Output results
    for (int i = 1; i <= Y; ++i) {
        cout << res[i] << '\n';
    }

    return 0;
}