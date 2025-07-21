#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define all(v) v.begin(), v.end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;

// Function to process the queries and return the remaining number of walls
int process_queries(int H, int W, const vector<pair<int, int>>& queries) {
    // Initialize the grid with walls
    vb grid(H + 1, vb(W + 1, true));

    // Process each query
    for (const auto& query : queries) {
        int r = query.first;
        int c = query.second;

        // Check if there is a wall at the given position and remove it
        if (grid[r][c]) {
            grid[r][c] = false;
            continue;
        }

        // Find the first wall to destroy in each direction
        // Vertical lines
        int up = upper_bound(all(grid[r]), [](const bool& b) { return b; }) - grid[r].begin() - 1;
        int down = lower_bound(all(grid[r]), [](const bool& b) { return b; }) - grid[r].begin();

        // Horizontal lines
        int left = upper_bound(all(grid), [c](const vb& row) { return row[c]; }) - grid.begin() - 1;
        int right = lower_bound(all(grid), [c](const vb& row) { return row[c]; }) - grid.begin();

        // Remove walls in each direction
        for (int i = up; i <= down; i++) {
            grid[i][c] = false;
        }
        for (int j = left; j <= right; j++) {
            grid[r][j] = false;
        }
    }

    // Count the remaining walls
    int remaining_walls = 0;
    rep(i, H) rep(j, W) remaining_walls += grid[i + 1][j + 1];

    return remaining_walls;
}

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<pair<int, int>> queries(Q);
    rep(i, Q) {
        int r, c;
        cin >> r >> c;
        queries[i] = {r, c};
    }

    int remaining_walls = process_queries(H, W, queries);
    cout << remaining_walls << endl;

    return 0;
}