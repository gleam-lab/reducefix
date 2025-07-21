// Copyright (C) 2025 hanziwei
// All rights reserved

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

    // Initialize the priority queue with all border cells
    for (int i = 0; i < H; ++i) {
        if (i == 0 || i == H - 1) {
            for (int j = 0; j < W; ++j) {
                pq.emplace(A[i][j], i, j);
                vis[i][j] = true;
            }
        } else {
            pq.emplace(A[i][0], i, 0);
            pq.emplace(A[i][W - 1], i, W - 1);
            vis[i][0] = true;
            vis[i][W - 1] = true;
        }
    }

    int ans = H * W;
    for (int i = 0; i < Y; ++i) {
        while (!pq.empty()) {
            auto [h, x, y] = pq.top();
            if (h > i) { break; }
            pq.pop(); --ans;
            for (int k = 0; k < 4; ++k) {
                int nx = x + d[k][0], ny = y + d[k][1];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if (vis[nx][ny]) continue;
                vis[nx][ny] = true;
                pq.emplace(A[nx][ny], nx, ny);
            }
        }
        std::cout << ans << "\n";
    }

    return 0;
}