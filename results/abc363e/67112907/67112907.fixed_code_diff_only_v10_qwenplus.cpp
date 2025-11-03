// Copyright (C) 2025 hanziwei
// All rights reserved

#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int H, W, Y;
    std::cin >> H >> W >> Y;

    std::vector A(H, std::vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> A[i][j];
        }
    }

    // We'll use a priority queue to simulate rising sea level.
    // The idea is to process cells in increasing order of elevation.
    std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<std::array<int, 3>>> pq;
    std::vector vis(H, std::vector<char>(W, 0));

    // Initially add all border cells since they are adjacent to the sea
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                pq.push({A[i][j], i, j});
                vis[i][j] = 1;
            }
        }
    }

    int remaining = H * W;
    std::vector<int> result(Y + 1); // Store result for each year

    for (int year = 1; year <= Y; year++) {
        // Process all cells that sink at this or earlier sea levels
        while (!pq.empty()) {
            auto [elev, x, y] = pq.top();
            if (elev > year) break; // This cell won't sink yet
            pq.pop();
            remaining--;

            // Check neighbors
            for (int k = 0; k < 4; k++) {
                int nx = x + d[k][0], ny = y + d[k][1];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if (vis[nx][ny]) continue;
                vis[nx][ny] = 1;
                pq.push({A[nx][ny], nx, ny});
            }
        }
        result[year] = remaining;
    }

    // Output results for each year from 1 to Y
    for (int i = 1; i <= Y; i++) {
        std::cout << result[i] << '\n';
    }

    return 0;
}