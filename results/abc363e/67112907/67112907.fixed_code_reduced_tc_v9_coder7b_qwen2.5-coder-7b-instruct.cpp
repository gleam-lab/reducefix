// Copyright (C) 2025 hanziwei
// All rights reserved

#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct Cell {
    int h, x, y;
    bool operator<(const Cell& other) const {
        return h > other.h;
    }
};

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

    std::priority_queue<Cell> pq;
    std::vector<std::vector<bool>> vis(H, std::vector<bool>(W));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.push({A[i][j], i, j});
                vis[i][j] = true;
            }
        }
    }

    int ans = H * W;
    for (int k = 0; k < Y; k++) {
        while (!pq.empty() && pq.top().h <= k) {
            auto [h, x, y] = pq.top();
            pq.pop();
            --ans;
            for (auto [dx, dy] : d) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    pq.push({A[nx][ny], nx, ny});
                }
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}