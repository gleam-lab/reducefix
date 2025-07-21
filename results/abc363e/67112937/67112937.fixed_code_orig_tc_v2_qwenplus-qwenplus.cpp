#include <bits/stdc++.h>

using i64 = long long;

constexpr int dx[4] = {0, 0, 1, -1};
constexpr int dy[4] = {1, -1, 0, 0};

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

    // Compress years: only track when the area changes
    std::vector<int> queries(Y);
    for (int i = 0; i < Y; ++i) {
        queries[i] = i + 1;
    }

    // Create a map of all cell values and their positions
    std::map<int, std::vector<std::pair<int, int>>> heightMap;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            heightMap[A[i][j]].push_back({i, j});
        }
    }

    // Union-Find with perimeter tracking
    struct DSU {
        std::vector<int> parent, size;
        std::vector<std::array<int, 4>> edges;  // For each cell, count of each edge type
        std::vector<bool> is_sea;

        DSU(int n) : parent(n), size(n, 1), edges(n), is_sea(n, false) {
            std::iota(parent.begin(), parent.end(), 0);
        }

        int find(int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        }

        void unite(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) return;

            if (size[x] < size[y]) std::swap(x, y);
            parent[y] = x;
            size[x] += size[y];

            // Merge edge information
            for (int i = 0; i < 4; ++i) {
                edges[x][i] += edges[y][i];
            }
        }

        bool connected_to_sea(int x) {
            return is_sea[find(x)];
        }

        void mark_sea(int x) {
            x = find(x);
            is_sea[x] = true;
        }
    };

    // Grid to index mapping
    auto gridToIndex = [W](int x, int y) { return x * W + y; };

    DSU dsu(H * W);

    // Initialize edges for border cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            int idx = gridToIndex(i, j);
            for (int d = 0; d < 4; ++d) {
                int ni = i + dx[d], nj = j + dy[d];
                if (ni < 0 || ni >= H || nj < 0 || nj >= W) {
                    dsu.edges[idx][d] = 1;
                }
            }
        }
    }

    int total_area = H * W;

    // Process heights in increasing order
    std::vector<bool> cell_sunk(H * W, false);
    std::vector<int> ans(Y + 2);  // Add buffer to avoid off-by-one issues

    // Start with all queries being "active"
    std::set<int> active_years;
    for (int i = 1; i <= Y; ++i) {
        active_years.insert(i);
    }

    for (const auto &[height, cells] : heightMap) {
        // Check which years we should answer now
        std::vector<int> to_answer;
        for (int year : active_years) {
            if (height <= year) {
                to_answer.push_back(year);
            }
        }

        // If no answers needed at this step, skip processing these cells
        if (to_answer.empty()) continue;

        // Process cells of this height
        for (const auto &[x, y] : cells) {
            int idx = gridToIndex(x, y);
            if (cell_sunk[idx]) continue;

            cell_sunk[idx] = true;
            --total_area;

            // Try connecting to neighbors
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;

                int neighbor_idx = gridToIndex(nx, ny);
                if (!cell_sunk[neighbor_idx]) continue;

                dsu.unite(idx, neighbor_idx);
            }

            // Check if this cell connects to sea
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
                    dsu.mark_sea(idx);
                    break;
                }
            }

            // If this cell or its group is connected to sea, propagate that
            if (dsu.connected_to_sea(idx)) {
                dsu.mark_sea(idx);
            }
        }

        // Answer all relevant queries
        for (int year : to_answer) {
            ans[year] = total_area;
            active_years.erase(year);
        }
    }

    // For any remaining active years (where height > year), use last computed value
    while (!active_years.empty()) {
        int last_val = total_area;
        for (int year : active_years) {
            ans[year] = last_val;
        }
        break;  // All remaining years will have same value
    }

    // Output results
    for (int i = 1; i <= Y; ++i) {
        std::cout << ans[i] << "\n";
    }

    return 0;
}