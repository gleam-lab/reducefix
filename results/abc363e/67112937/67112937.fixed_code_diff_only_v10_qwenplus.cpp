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
    std::vector vis(H, std::vector<char>(W, 0));
    int ans = H * W;

    // Add all border cells to the priority queue
    for (int j = 0; j < W; j++) {
        if (!vis[0][j]) {
            vis[0][j] = 1;
            pq.push({A[0][j], 0, j});
        }
        if (H > 1 && !vis[H-1][j]) {
            vis[H-1][j] = 1;
            pq.push({A[H-1][j], H-1, j});
        }
    }
    for (int i = 1; i < H-1; i++) {
        if (!vis[i][0]) {
            vis[i][0] = 1;
            pq.push({A[i][0], i, 0});
        }
        if (W > 1 && !vis[i][W-1]) {
            vis[i][W-1] = 1;
            pq.push({A[i][W-1], i, W-1});
        }
    }

    // For each year, simulate sea level rise
    for (int year = 1; year <= Y; year++) {
        // Process all cells that sink at current sea level (<= year)
        while (!pq.empty()) {
            auto [elevation, x, y] = pq.top();
            if (elevation > year) break;
            pq.pop();
            ans--;

            // Check neighbors
            for (int k = 0; k < 4; k++) {
                int nx = x + d[k][0], ny = y + d[k][1];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    pq.push({A[nx][ny], nx, ny});
                }
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}