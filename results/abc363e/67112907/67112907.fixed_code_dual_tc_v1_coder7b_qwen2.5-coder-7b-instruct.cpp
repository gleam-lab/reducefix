#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int H, W, Y;
    std::cin >> H >> W >> Y;

    std::vector<std::vector<int>> A(H, std::vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> A[i][j];
        }
    }

    std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> pq;
    std::vector<std::vector<bool>> vis(H, std::vector<bool>(W));

    // Initialize the priority queue with all boundary cells
    for (int i = 0; i < H; i++) {
        if (!vis[i][0]) pq.push({A[i][0], i, 0}), vis[i][0] = true;
        if (!vis[i][W - 1]) pq.push({A[i][W - 1], i, W - 1}), vis[i][W - 1] = true;
    }
    for (int j = 1; j < W - 1; j++) {
        if (!vis[0][j]) pq.push({A[0][j], 0, j}), vis[0][j] = true;
        if (!vis[H - 1][j]) pq.push({A[H - 1][j], H - 1, j}), vis[H - 1][j] = true;
    }

    int ans = H * W;
    while (Y--) {
        while (!pq.empty()) {
            auto [h, x, y] = pq.top();
            if (h <= Y) { // Corrected condition to check if the cell is below the rising sea level
                pq.pop();
                --ans;
                for (int k = 0; k < 4; k++) {
                    int nx = x + d[k][0], ny = y + d[k][1];
                    if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                    if (vis[nx][ny]) continue;
                    vis[nx][ny] = true;
                    pq.push({A[nx][ny], nx, ny});
                }
            } else {
                break;
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}