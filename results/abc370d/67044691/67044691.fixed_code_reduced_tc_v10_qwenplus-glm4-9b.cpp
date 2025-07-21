#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, q; cin >> h >> w >> q;
    vector<vector<int>> grid(h, vector<int>(w, 1)); // All cells have walls initially
    vector<pair<int, int>> queries(q);

    for (int i = 0; i < q; ++i) {
        int r, c; cin >> r >> c;
        queries[i] = {r - 1, c - 1}; // Convert to 0-based index
    }

    // Sort queries by row and column to process them in order
    sort(queries.begin(), queries.end());

    for (auto& query : queries) {
        int r = query.first, c = query.second;
        if (grid[r][c] == 0) continue; // No wall is destroyed if there is no wall at (r, c)

        // Destroy the wall at (r, c)
        grid[r][c] = 0;

        // Check the four directions and destroy the closest walls
        // Up
        for (int i = r - 1; i >= 0; --i) {
            if (grid[i][c] == 1) {
                grid[i][c] = 0;
                break;
            }
        }
        // Down
        for (int i = r + 1; i < h; ++i) {
            if (grid[i][c] == 1) {
                grid[i][c] = 0;
                break;
            }
        }
        // Left
        for (int j = c - 1; j >= 0; --j) {
            if (grid[r][j] == 1) {
                grid[r][j] = 0;
                break;
            }
        }
        // Right
        for (int j = c + 1; j < w; ++j) {
            if (grid[r][j] == 1) {
                grid[r][j] = 0;
                break;
            }
        }
    }

    // Count the number of remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            remainingWalls += grid[i][j];
        }
    }

    cout << remainingWalls << endl;
}