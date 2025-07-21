#include <bits/stdc++.h>

using namespace std;

struct Cell {
    int h, x, y;
    bool operator<(const Cell& other) const {
        return h > other.h;
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

    priority_queue<Cell> pq;
    vector<vector<bool>> vis(H, vector<bool>(W, false));

    // Initialize the priority queue with all cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            pq.emplace(A[i][j], i, j);
        }
    }

    while (!pq.empty()) {
        auto [h, x, y] = pq.top();
        if (vis[x][y]) {
            pq.pop();
            continue;
        }
        vis[x][y] = true;

        // Check neighbors and push them to the queue if they can be reached
        for (int k = 0; k < 4; ++k) {
            int nx = x + d[k][0], ny = y + d[k][1];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
                continue;
            }
            if (vis[nx][ny]) {
                continue;
            }
            pq.emplace(A[nx][ny], nx, ny);
        }
    }

    int ans = H * W;
    cout << ans << '\n';

    for (int i = 1; i <= Y; ++i) {
        int level = i;
        while (!pq.empty() && pq.top().h <= level) {
            auto [h, x, y] = pq.top();
            pq.pop();
            ans--;
        }
        cout << ans << '\n';
    }

    return 0;
}