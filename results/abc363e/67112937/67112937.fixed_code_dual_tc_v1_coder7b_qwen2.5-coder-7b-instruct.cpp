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

    std::vector<int> A(H * W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> A[i * W + j]; --A[i * W + j];
        }
    }

    std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> pq;
    std::vector<std::vector<char>> vis(H, std::vector<char>(W));
    for (int i = 0; i < W - 1; i++) { pq.push({A[i], 0, i}); vis[0][i] = 1; }
    for (int i = 1; i < H; i++) { pq.push({A[i * W], i, 0}); vis[i][0] = 1; }
    for (int i = 0; i < H - 1; i++) { pq.push({A[(H - 1) * W + i], H - 1, i}); vis[H - 1][i] = 1; }
    for (int i = 1; i < W; i++) { pq.push({A[W - 1 + i], H - 1, i}); vis[H - 1][i] = 1; }

    int ans = H * W;
    for (int i = 0; i < Y; i++) {
        while (!pq.empty()) {
            auto [h, x, y] = pq.top();
            if (h <= i) { pq.pop(); --ans; }
            else { break; }
            for (int j = 0; j < 4; j++) {
                int dx = x + d[j][0], dy = y + d[j][1];
                if (dx < 0 || dx >= H || dy < 0 || dy >= W) {
                    continue;
                }
                if (vis[dx][dy]) {
                    continue;
                }
                vis[dx][dy] = 1;
                pq.push({A[dx * W + dy], dx, dy});
            }
        }
        std::cout << ans << "\n";
    }

    return 0;
}