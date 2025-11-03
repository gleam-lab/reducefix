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

    std::vector<std::vector<int>> A(H, std::vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> A[i][j];
        }
    }

    // We'll process cells in increasing order of elevation
    std::vector<std::array<int, 3>> cells;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cells.push_back({A[i][j], i, j});
        }
    }
    std::sort(cells.begin(), cells.end());

    std::vector<std::vector<bool>> submerged(H, std::vector<bool>(W, false));
    int remaining = H * W;

    // Directions for flood fill
    auto is_boundary = [&](int x, int y) {
        return x == 0 || x == H-1 || y == 0 || y == W-1;
    };

    std::queue<std::array<int, 2>> q;
    
    int idx = 0;
    for (int year = 1; year <= Y; year++) {
        // Add all cells with elevation <= year that haven't been processed
        while (idx < cells.size() && cells[idx][0] <= year) {
            int h = cells[idx][0];
            int x = cells[idx][1];
            int y = cells[idx][2];
            if (!submerged[x][y]) {
                // If this cell is on the boundary or adjacent to a submerged cell, it will sink
                bool sinks = is_boundary(x, y);
                if (!sinks) {
                    for (int k = 0; k < 4; k++) {
                        int nx = x + d[k][0], ny = y + d[k][1];
                        if (nx >= 0 && nx < H && ny >= 0 && ny < W && submerged[nx][ny]) {
                            sinks = true;
                            break;
                        }
                    }
                }
                if (sinks) {
                    submerged[x][y] = true;
                    q.push({x, y});
                    remaining--;
                }
            }
            idx++;
        }

        // Propagate the sinking effect
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int k = 0; k < 4; k++) {
                int nx = x + d[k][0], ny = y + d[k][1];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !submerged[nx][ny] && A[nx][ny] <= year) {
                    submerged[nx][ny] = true;
                    q.push({nx, ny});
                    remaining--;
                }
            }
        }

        std::cout << remaining << "\n";
    }

    return 0;
}