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
    for (int i = 0; i < H * W; ++i) {
        std::cin >> A[i];
    }

    std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> pq;
    std::vector<bool> vis(H * W);
    for (int i = 0; i < W; ++i) { pq.push({A[i], 0, i}); vis[i] = true; }
    for (int i = 0; i < H - 1; ++i) { pq.push({A[W * i], i, W * i}); vis[W * i] = true; }
    for (int i = 0; i < W; ++i) { pq.push({A[W * (H - 1) + i], H - 1, W * (H - 1) + i}); vis[W * (H - 1) + i] = true; }
    for (int i = 0; i < H - 1; ++i) { pq.push({A[W * i + W - 1], i, W * i + W - 1}); vis[W * i + W - 1] = true; }

    int ans = H * W;
    for (int i = 0; i < Y; ++i) {
        for (; !pq.empty();) {
            auto [h, x, y] = pq.top();
            if (h > i) { break; }
            pq.pop(); --ans;
            for (int j = 0; j < 4; ++j) {
                int dx = x / W + d[j][0], dy = x % W + d[j][1];
                if (dx < 0 || dx >= H || dy < 0 || dy >= W) {
                    continue;
                }
                int idx = dx * W + dy;
                if (vis[idx]) {
                    continue;
                }
                vis[idx] = true;
                pq.push({A[idx], dx, dy});
            }
        }
        std::cout << ans << "\n";
    }

    return 0;
}