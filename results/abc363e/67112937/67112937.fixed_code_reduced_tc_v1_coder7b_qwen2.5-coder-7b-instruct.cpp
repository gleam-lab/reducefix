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

    std::vector<std::vector<bool>> visited(H, std::vector<bool>(W, false));

    auto bfs = [&](int sea_level) {
        std::queue<std::pair<int, int>> q;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j] && A[i][j] > sea_level) {
                    q.emplace(i, j);
                    visited[i][j] = true;
                }
            }
        }
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int nx = x + d[k][0], ny = y + d[k][1];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] > sea_level) {
                    q.emplace(nx, ny);
                    visited[nx][ny] = true;
                }
            }
        }
    };

    for (int i = 0; i <= Y; ++i) {
        std::fill(visited.begin(), visited.end(), false);
        bfs(i);
        int remaining_area = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j]) {
                    ++remaining_area;
                }
            }
        }
        std::cout << remaining_area << '\n';
    }

    return 0;
}