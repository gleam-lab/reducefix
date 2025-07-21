#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h, w, y;
    cin >> h >> w >> y;

    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    // Create a list of all cells with their positions and heights
    vector<tuple<int, int, int>> cells;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cells.emplace_back(grid[i][j], i, j);
        }
    }

    // Sort cells by height
    sort(cells.begin(), cells.end());

    // Union-Find (Disjoint Set Union)
    vector<int> parent(h * w), is_boundary(h * w, 0), area(h * w, 1);
    iota(parent.begin(), parent.end(), 0);

    function<int(int)> find = [&](int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    };

    function<void(int, int)> unite = [&](int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (area[px] < area[py]) swap(px, py);
        parent[py] = px;
        area[px] += area[py];
    };

    // Map from height to list of indices
    map<int, vector<int>> height_map;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int idx = i * w + j;
            height_map[grid[i][j]].push_back(idx);
        }
    }

    // Mark boundary cells as connected to sea
    auto is_boundary_cell = [&](int r, int c) {
        return r == 0 || r == h - 1 || c == 0 || c == w - 1;
    };

    // Total number of initially connected-to-sea cells at each height
    map<int, int> destroyed_count;

    // Process in increasing order of height
    int processed = 0;
    int total_cells = h * w;
    vector<int> result(y + 2);  // For each year, how many destroyed cells

    // We'll keep track of which cells are connected to the sea
    vector<bool> connected_to_sea(h * w, false);

    // Precompute directions
    array<int, 4> dr = { -1, 1, 0, 0 };
    array<int, 4> dc = { 0, 0, -1, 1 };

    // For each cell, its index is r * w + c
    for (auto& [height, r, c] : cells) {
        int idx = r * w + c;
        bool is_bdry = is_boundary_cell(r, c);

        // Initially not connected to sea unless it's a boundary cell
        connected_to_sea[idx] = is_bdry;

        // Check neighbors
        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr >= 0 && nr < h && nc >= 0 && nc < w) {
                int n_idx = nr * w + nc;
                // If neighbor already processed and has same or lower height
                if (grid[nr][nc] <= height) {
                    unite(idx, n_idx);
                    // If any component part is connected to sea, mark this one too
                    if (connected_to_sea[find(n_idx)]) {
                        connected_to_sea[find(idx)] = true;
                    }
                }
            }
        }

        // If this cell is connected to sea directly (boundary), propagate
        if (is_bdry) {
            int root = find(idx);
            connected_to_sea[root] = true;
        }

        // Count how many new cells are connected to sea at this height
        int root = find(idx);
        if (connected_to_sea[root]) {
            // This cell is now connected to sea
            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr >= 0 && nr < h && nc >= 0 && nc < w) {
                    int n_idx = nr * w + nc;
                    if (grid[nr][nc] <= height) {
                        int root_n = find(n_idx);
                        if (!connected_to_sea[root_n]) {
                            connected_to_sea[root_n] = true;
                        }
                    }
                }
            }
        }
    }

    // Now compute cumulative destruction per year
    vector<int> sink_time(h * w);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int idx = i * w + j;
            sink_time[idx] = grid[i][j];
        }
    }

    vector<int> count(y + 2, 0);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int val = grid[i][j];
            if (val <= y) {
                count[val]++;
            }
        }
    }

    // Cumulative sum
    for (int i = 1; i <= y; ++i) {
        count[i] += count[i - 1];
    }

    // Output results
    for (int i = 1; i <= y; ++i) {
        cout << total_cells - count[i] << "\n";
    }

    return 0;
}