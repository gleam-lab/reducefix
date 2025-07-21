#include <bits/stdc++.h>

using namespace std;

struct Cell {
    int h, x, y;
    bool operator<(const Cell &other) const {
        return h > other.h;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
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
    for (int i = 0; i < H; ++i) {
        pq.emplace(A[i][0], i, 0); vis[i][0] = true;
    }
    for (int i = 1; i < W; ++i) {
        pq.emplace(A[0][i], 0, i); vis[0][i] = true;
    }
    for (int i = 1; i < H; ++i) {
        pq.emplace(A[i][W - 1], i, W - 1); vis[i][W - 1] = true;
    }
    for (int i = 0; i < W - 1; ++i) {
        pq.emplace(A[H - 1][i], H - 1, i); vis[H - 1][i] = true;
    }

    while (!pq.empty()) {
        auto [h, x, y] = pq.top(); pq.pop();
        if (h == Y) break;

        for (int k = 0; k < 4; ++k) {
            int dx = x + d[k][0], dy = y + d[k][1];
            if (dx < 0 || dx >= H || dy < 0 || dy >= W) continue;
            if (vis[dx][dy]) continue;
            vis[dx][dy] = true;
            pq.emplace(A[dx][dy], dx, dy);
        }
    }

    int ans = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!vis[i][j]) ++ans;
        }
    }

    cout << ans << '\n';

    return 0;
}