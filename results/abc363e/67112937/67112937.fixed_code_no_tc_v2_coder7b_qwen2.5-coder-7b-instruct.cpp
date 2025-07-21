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
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            std::cin >> A[i][j];
        }
    }

    std::vector<std::vector<bool>> visited(H, std::vector<bool>(W));
    auto sink = [&](int sea_level) {
        std::queue<std::pair<int, int>> q;
        for (int i = 0; i < H; ++i) {
            if (A[i][0] <= sea_level) q.emplace(i, 0), visited[i][0] = true;
            if (A[i][W - 1] <= sea_level) q.emplace(i, W - 1), visited[i][W - 1] = true;
        }
        for (int j = 0; j < W; ++j) {
            if (A[0][j] <= sea_level) q.emplace(0, j), visited[0][j] = true;
            if (A[H - 1][j] <= sea_level) q.emplace(H - 1, j), visited[H - 1][j] = true;
        }
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int k = 0; k < 4; ++k) {
                int nx = x + d[k][0], ny = y + d[k][1];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if (visited[nx][ny] || A[nx][ny] > sea_level) continue;
                visited[nx][ny] = true;
                q.emplace(nx, ny);
            }
        }
    };

    for (int i = 0; i < Y; ++i) {
        sink(i);
        int count = 0;
        for (int j = 0; j < H; ++j) {
            for (int k = 0; k < W; ++k) {
                if (!visited[j][k]) ++count;
            }
        }
        std::cout << count << '\n';
    }

    return 0;
}