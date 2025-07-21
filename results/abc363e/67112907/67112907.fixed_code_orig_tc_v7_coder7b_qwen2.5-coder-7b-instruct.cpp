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

    auto add_to_pq = [&](int x, int y, int h) {
        if (x < 0 || x >= H || y < 0 || y >= W || vis[x][y]) return;
        pq.emplace(h, x, y);
        vis[x][y] = true;
    };

    for (int i = 0; i < H; ++i) {
        add_to_pq(i, 0, A[i][0]);
        add_to_pq(i, W - 1, A[i][W - 1]);
    }
    for (int j = 0; j < W; ++j) {
        add_to_pq(0, j, A[0][j]);
        add_to_pq(H - 1, j, A[H - 1][j]);
    }

    while (!pq.empty()) {
        auto [h, x, y] = pq.top();
        pq.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = x + d[k][0], ny = y + d[k][1];
            add_to_pq(nx, ny, h);
        }
    }

    std::vector<int> areas(Y + 1, H * W);
    for (int t = 1; t <= Y; ++t) {
        while (!pq.empty() && pq.top()[0] <= t) {
            auto [h, x, y] = pq.top();
            pq.pop();
            areas[t]++;
            for (int k = 0; k < 4; ++k) {
                int nx = x + d[k][0], ny = y + d[k][1];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W || vis[nx][ny]) continue;
                vis[nx][ny] = true;
                if (A[nx][ny] <= t) {
                    pq.emplace(t, nx, ny);
                    areas[t]++;
                }
            }
        }
        std::cout << areas[t] << '\n';
    }

    return 0;
}