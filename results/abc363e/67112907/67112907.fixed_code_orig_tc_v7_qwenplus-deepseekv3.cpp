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

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    vector<vector<bool>> vis(H, vector<bool>(W, false));

    // Push all border cells into the priority queue
    for (int i = 0; i < H; ++i) {
        if (!vis[i][0]) {
            pq.push({A[i][0], i, 0});
            vis[i][0] = true;
        }
        if (!vis[i][W - 1]) {
            pq.push({A[i][W - 1], i, W - 1});
            vis[i][W - 1] = true;
        }
    }
    for (int j = 1; j < W - 1; ++j) {
        if (!vis[0][j]) {
            pq.push({A[0][j], 0, j});
            vis[0][j] = true;
        }
        if (!vis[H - 1][j]) {
            pq.push({A[H - 1][j], H - 1, j});
            vis[H - 1][j] = true;
        }
    }

    int ans = H * W;
    for (int y = 1; y <= Y; ++y) {
        while (!pq.empty()) {
            auto [h, x, j] = pq.top();
            if (h > y) break;
            pq.pop();
            --ans;
            for (int k = 0; k < 4; ++k) {
                int nx = x + d[k][0];
                int ny = j + d[k][1];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if (vis[nx][ny]) continue;
                vis[nx][ny] = true;
                pq.push({A[nx][ny], nx, ny});
            }
        }
        cout << ans << '\n';
    }

    return 0;
}