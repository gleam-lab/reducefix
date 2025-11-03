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

    // We'll use a priority queue to simulate the rising sea level
    // Elements are (elevation, x, y)
    std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<std::array<int, 3>>> pq;
    std::vector vis(H, std::vector<char>(W, 0));

    // Initialize the border cells as starting points since they're adjacent to the sea
    for (int i = 0; i < H; i++) {
        pq.push({A[i][0], i, 0});
        vis[i][0] = 1;
        if (W > 1) {
            pq.push({A[i][W-1], i, W-1});
            vis[i][W-1] = 1;
        }
    }
    for (int j = 1; j < W - 1; j++) {
        pq.push({A[0][j], 0, j});
        vis[0][j] = 1;
        if (H > 1) {
            pq.push({A[H-1][j], H-1, j});
            vis[H-1][j] = 1;
        }
    }

    int remaining = H * W;
    std::vector<int> result;

    // Process each year from 1 to Y
    for (int year = 1; year <= Y; year++) {
        // Remove all cells that are submerged at this sea level (sea level = year)
        while (!pq.empty()) {
            auto [elev, x, y] = pq.top();
            if (elev > year) break; // This cell and others in pq haven't been submerged yet
            pq.pop();
            remaining--;

            // Check neighbors to see if they become connected to the sea
            for (int k = 0; k < 4; k++) {
                int nx = x + d[k][0];
                int ny = y + d[k][1];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    pq.push({A[nx][ny], nx, ny});
                }
            }
        }
        result.push_back(remaining);
    }

    // Output results for each year
    for (int i = 0; i < Y; i++) {
        std::cout << result[i] << '\n';
    }

    return 0;
}