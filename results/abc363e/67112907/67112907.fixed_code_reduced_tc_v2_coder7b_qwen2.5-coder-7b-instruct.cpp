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

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] <= 0) continue;
            pq.push({A[i][j], i, j});
            vis[i][j] = true;
        }
    }

    while (!pq.empty()) {
        auto [h, x, y] = pq.top();
        pq.pop();
        for (int j = 0; j < 4; j++) {
            int dx = x + d[j][0], dy = y + d[j][1];
            if (dx < 0 || dx >= H || dy < 0 || dy >= W) continue;
            if (vis[dx][dy] || A[dx][dy] <= h) continue;
            pq.push({A[dx][dy], dx, dy});
            vis[dx][dy] = true;
        }
    }

    for (int i = 1; i <= Y; i++) {
        int ans = 0;
        for (int j = 0; j < H; j++) {
            for (int k = 0; k < W; k++) {
                if (A[j][k] > i) ++ans;
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}