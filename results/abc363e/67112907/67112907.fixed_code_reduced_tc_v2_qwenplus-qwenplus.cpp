#include <bits/stdc++.h>

using i64 = long long;

constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {1, 0, -1, 0};

int main() {
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

    // Initialize visited matrix
    std::vector<std::vector<bool>> vis(H, std::vector<bool>(W, false));

    // Priority queue to process cells by elevation
    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<>> pq;

    // Mark boundary cells and add to priority queue
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                vis[i][j] = true;
                pq.emplace(A[i][j], i, j);
            }
        }
    }

    int remaining = H * W;
    std::vector<int> ans(Y + 1);  // Store answers for years 0 to Y

    // Process the priority queue
    while (!pq.empty()) {
        auto [h, x, y] = pq.top();
        pq.pop();

        // For all years up to h, this cell is submerged
        // So we record that the area decreases for those years
        static int max_year = 0;
        max_year = std::max(max_year, h);

        for (int ny = h; ny <= Y; ++ny) {
            ans[ny]--;
        }

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
                vis[nx][ny] = true;
                pq.emplace(A[nx][ny], nx, ny);
            }
        }
    }

    // Fill in year 0
    ans[0] = H * W;

    // Print results for each year from 1 to Y
    for (int i = 1; i <= Y; ++i) {
        std::cout << ans[i] << "\n";
    }

    return 0;
}