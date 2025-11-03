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

    std::vector A(H, std::vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> A[i][j];
        }
    }

    std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<std::array<int, 3>>> pq;
    std::vector vis(H, std::vector<char>(W));

    // Add all border cells to the priority queue
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                pq.push({A[i][j], i, j});
                vis[i][j] = 1;
            }
        }
    }

    int ans = H * W;
    std::vector<int> result(Y, 0);

    for (int year = 1; year <= Y; year++) {
        // Process all cells that sink at current sea level (year)
        while (!pq.empty()) {
            auto [elevation, x, y] = pq.top();
            if (elevation > year) break;
            pq.pop();
            ans--;
            
            // Check neighbors
            for (int k = 0; k < 4; k++) {
                int dx = x + d[k][0], dy = y + d[k][1];
                if (dx < 0 || dx >= H || dy < 0 || dy >= W) continue;
                if (vis[dx][dy]) continue;
                vis[dx][dy] = 1;
                pq.push({A[dx][dy], dx, dy});
            }
        }
        result[year-1] = ans;
    }

    // Output results for each year
    for (int i = 0; i < Y; i++) {
        std::cout << result[i] << "\n";
    }

    return 0;
}