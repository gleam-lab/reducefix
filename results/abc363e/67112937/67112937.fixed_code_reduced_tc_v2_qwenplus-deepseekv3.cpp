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

    // Add all boundary cells to the priority queue
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                pq.push({A[i][j], i, j});
                vis[i][j] = 1;
            }
        }
    }

    int ans = H * W;
    for (int i = 0; i < Y; i++) {
        while (!pq.empty() && pq.top()[0] <= i) {
            auto [h, x, y] = pq.top();
            pq.pop();
            ans--;
            for (int j = 0; j < 4; j++) {
                int dx = x + d[j][0], dy = y + d[j][1];
                if (dx >= 0 && dx < H && dy >= 0 && dy < W && !vis[dx][dy]) {
                    vis[dx][dy] = 1;
                    pq.push({A[dx][dy], dx, dy});
                }
            }
        }
        std::cout << ans << "\n";
    }

    return 0;
}