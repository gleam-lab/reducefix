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

    std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<std::array<int, 3>>> pq;
    std::vector vis(H, std::vector<char>(W));

    // Initialize the border cells
    for (int i = 0; i < H; i++) {
        if (!vis[i][0]) {
            vis[i][0] = 1;
            pq.push({A[i][0], i, 0});
        }
        if (W > 1 && !vis[i][W-1]) {
            vis[i][W-1] = 1;
            pq.push({A[i][W-1], i, W-1});
        }
    }
    for (int j = 1; j < W-1; j++) {
        if (!vis[0][j]) {
            vis[0][j] = 1;
            pq.push({A[0][j], 0, j});
        }
        if (H > 1 && !vis[H-1][j]) {
            vis[H-1][j] = 1;
            pq.push({A[H-1][j], H-1, j});
        }
    }

    int ans = H * W;
    std::vector<int> result(Y);

    for (int year = 0; year < Y; year++) {
        while (!pq.empty()) {
            auto [elevation, x, y] = pq.top();
            if (elevation > year + 1) break; // sea level is year+1
            pq.pop();
            ans--;
            for (int k = 0; k < 4; k++) {
                int dx = x + d[k][0], dy = y + d[k][1];
                if (dx < 0 || dx >= H || dy < 0 || dy >= W || vis[dx][dy]) continue;
                vis[dx][dy] = 1;
                pq.push({A[dx][dy], dx, dy});
            }
        }
        result[year] = ans;
    }

    for (int i = 0; i < Y; i++) {
        std::cout << result[i] << "\n";
    }

    return 0;
}