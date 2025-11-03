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
    std::vector<int> result(Y);

    for (int year = 0; year < Y; year++) {
        int sea_level = year + 1;
        
        while (!pq.empty()) {
            auto [elevation, x, y] = pq.top();
            if (elevation > sea_level) break;
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