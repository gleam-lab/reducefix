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
        pq.push({A[i][0], i, 0});
        pq.push({A[i][W-1], i, W-1});
        vis[i][0] = true;
        vis[i][W-1] = true;
    }
    for (int j = 0; j < W; ++j) {
        pq.push({A[0][j], 0, j});
        pq.push({A[H-1][j], H-1, j});
        vis[0][j] = true;
        vis[H-1][j] = true;
    }

    int ans = H * W;
    for (int i = 0; i < Y; i++) {
        while (!pq.empty()) {
            auto [h, x, y] = pq.top();
            if (h <= i) {
                pq.pop();
                --ans;
                for (int j = 0; j < 4; j++) {
                    int dx = x + d[j][0], dy = y + d[j][1];
                    if (dx >= 0 && dx < H && dy >= 0 && dy < W && !vis[dx][dy] && A[dx][dy] <= i) {
                        vis[dx][dy] = true;
                        pq.push({A[dx][dy], dx, dy});
                    }
                }
            } else {
                break;
            }
        }
        std::cout << ans << "\n";
    }

    return 0;
}