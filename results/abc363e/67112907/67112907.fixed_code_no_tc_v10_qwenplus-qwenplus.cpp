#include <bits/stdc++.h>

using namespace std;

constexpr int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

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

    // Build a map of elevation to list of coordinates
    std::map<int, vector<pair<int, int>>> elevMap;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            elevMap[A[i][j]].push_back({i, j});
        }
    }

    // Initialize the grid to track if a cell is submerged
    std::vector<std::vector<bool>> submerged(H, std::vector<bool>(W, false));

    // Count of remaining land cells
    int remaining = H * W;

    // Answer array
    std::vector<int> ans(Y + 1);
    ans[0] = remaining;

    // Process from lowest elevation up
    std::queue<pair<int, int>> q;

    for (auto& [height, cells] : elevMap) {
        // First mark all current cells at this height as potentially submerged
        vector<pair<int, int>> toCheck;
        for (auto [x, y] : cells) {
            bool neighborSubmerged = false;
            for (int i = 0; i < 4; ++i) {
                int nx = x + d[i][0];
                int ny = y + d[i][1];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && submerged[nx][ny]) {
                    neighborSubmerged = true;
                    break;
                }
            }
            if (neighborSubmerged) {
                submerged[x][y] = true;
                --remaining;
                q.emplace(x, y);
            } else {
                toCheck.push_back({x, y});
            }
        }

        // BFS to flood fill adjacent areas
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = x + d[i][0];
                int ny = y + d[i][1];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !submerged[nx][ny] && A[nx][ny] <= height) {
                    submerged[nx][ny] = true;
                    --remaining;
                    q.emplace(nx, ny);
                }
            }
        }

        // Now process the cells we skipped earlier
        for (auto [x, y] : toCheck) {
            bool neighborSubmerged = false;
            for (int i = 0; i < 4; ++i) {
                int nx = x + d[i][0];
                int ny = y + d[i][1];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && submerged[nx][ny]) {
                    neighborSubmerged = true;
                    break;
                }
            }
            if (neighborSubmerged) {
                submerged[x][y] = true;
                --remaining;
                q.emplace(x, y);
                // BFS again from these cells
                while (!q.empty()) {
                    auto [x2, y2] = q.front();
                    q.pop();

                    for (int i = 0; i < 4; ++i) {
                        int nx = x2 + d[i][0];
                        int ny = y2 + d[i][1];
                        if (nx >= 0 && nx < H && ny >= 0 && ny < W && !submerged[nx][ny] && A[nx][ny] <= height) {
                            submerged[nx][ny] = true;
                            --remaining;
                            q.emplace(nx, ny);
                        }
                    }
                }
            }
        }

        // Store result for year = height
        if (height <= Y) {
            ans[height] = remaining;
        }
    }

    // Fill in any missing values (for years where no new submersion happened)
    for (int i = 1; i <= Y; ++i) {
        if (ans[i] == 0) {
            ans[i] = ans[i-1];
        }
        cout << ans[i] << "\n";
    }

    return 0;
}