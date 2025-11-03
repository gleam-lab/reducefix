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

    // We simulate rising sea level from year 1 to Y
    // Instead of starting from ocean edges and using a priority queue,
    // we need to consider that flooding happens in waves per year.
    
    // We'll use a multi-step BFS approach:
    // At each year i, any cell with elevation <= i gets flooded if connected to the sea.
    // But note: once a cell is flooded, it becomes part of the "sea" for future propagation.

    std::vector<std::vector<bool>> flooded(H, std::vector<bool>(W, false));
    std::queue<std::array<int, 2>> q;

    // Initially, all border cells that are at elevation <= current sea level (year) will flood
    // But we simulate year by year, adding newly vulnerable cells

    // First, precompute events: for each elevation, which cells become "floodable" at that sea level
    std::vector<std::vector<std::pair<int, int>>> by_elevation(100001); // max elevation up to 10^5

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            by_elevation[A[i][j]].emplace_back(i, j);
        }
    }

    // Also start by marking immediate border connections as potential entry points
    auto add_if_valid = [&](int x, int y) {
        if (x >= 0 && x < H && y >= 0 && y < W && !flooded[x][y]) {
            q.push({x, y});
            flooded[x][y] = true;
        }
    };

    // Initialize: enqueue all border cells that can be flooded at their respective levels
    // But instead, we do year-by-year simulation

    int remaining = H * W;

    for (int year = 1; year <= Y; year++) {
        // Add all cells with elevation == year that are on the border or adjacent to already flooded region?
        // Actually, we need to consider connectivity: only cells connected to the sea (via flooded path) get flooded
        // So we maintain a frontier of flooded cells and expand when new low-elevation cells appear?

        // Better idea: process all cells with elevation <= 'year' that are reachable from outside
        // But we want efficiency: we cannot run full BFS every year.

        // Revised plan:
        // Use a priority queue (min-heap) of cells sorted by elevation
        // Start from all border cells, and flood inward based on elevation threshold increasing over years

        // Actually, let's go back to Dijkstra-like method but fix logic:

        // Priority queue: (elevation, x, y)
        static std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> pq;
        static bool initialized = false;

        if (!initialized) {
            initialized = true;
            // Push all border cells
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                        pq.push({A[i][j], i, j});
                    }
                }
            }
        }

        // Process all cells that can be flooded at this year (elevation <= year)
        while (!pq.empty()) {
            auto [elev, x, y] = pq.top();
            if (elev > year) break;
            pq.pop();

            if (flooded[x][y]) continue;
            flooded[x][y] = true;
            remaining--;

            // Propagate to neighbors
            for (int k = 0; k < 4; k++) {
                int nx = x + d[k][0], ny = y + d[k][1];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !flooded[nx][ny]) {
                    pq.push({A[nx][ny], nx, ny});
                }
            }
        }

        std::cout << remaining << '\n';
    }

    return 0;
}