#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Wall {
    int row, col;
};

struct Query {
    int r, c;
};

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<set<Wall>>> grid(H, vector<set<Wall>>(W));
    vector<vector<bool>> destroyed(H, vector<bool>(W, false));

    // Initialize walls
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            grid[i][j].insert({i, j});
        }
    }

    vector<Query> queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i].r >> queries[i].c;
    }

    // Process queries
    for (const auto& query : queries) {
        int r = query.r - 1; // convert to 0-based index
        int c = query.c - 1; // convert to 0-based index

        // Check if there's a wall at the given cell
        if (grid[r][c].size() == 0) {
            continue; // no wall, nothing to destroy
        }

        // Mark the cell as destroyed
        destroyed[r][c] = true;

        // Search the cells in all four directions
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (const auto& dir : directions) {
            int nr = r + dir.first;
            int nc = c + dir.second;
            if (nr < 0 || nr >= H || nc < 0 || nc >= W || destroyed[nr][nc]) {
                continue; // out of bounds or already destroyed
            }

            // Find and destroy the first wall
            auto it = grid[nr][nc].lower_bound({nr, nc});
            if (it != grid[nr][nc].end() && !destroyed[it->row][it->col]) {
                destroyed[it->row][it->col] = true;
                grid[nr][nc].erase(it);
            }
        }
    }

    // Calculate the remaining number of walls
    long long remainingWalls = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            remainingWalls += grid[i][j].size();
        }
    }

    cout << remainingWalls << endl;

    return 0;
}