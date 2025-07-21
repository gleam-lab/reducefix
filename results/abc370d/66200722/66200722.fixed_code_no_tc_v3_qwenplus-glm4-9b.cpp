#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 4e5;

int h, w, q;
vector<vector<int>> grid[MAXN + 1];

void solve() {
    for (int i = 0; i < h; ++i) {
        grid[i].resize(w + 1);
    }

    for (int i = 1; i <= q; ++i) {
        int r, c;
        cin >> r >> c;
        --r; --c; // Convert to 0-indexed

        if (grid[r][c] == 0) {
            grid[r][c] = 1; // Mark the cell as visited
        } else {
            // Find and mark the walls to be destroyed
            int rMin = r, rMax = r, cMin = c, cMax = c;

            for (int j = r + 1; j <= h && grid[j][c] == 0; ++j) {
                rMax = max(rMax, j);
            }
            for (int j = r - 1; j >= 0 && grid[j][c] == 0; --j) {
                rMin = min(rMin, j);
            }
            for (int j = c + 1; j <= w && grid[r][j] == 0; ++j) {
                cMax = max(cMax, j);
            }
            for (int j = c - 1; j >= 0 && grid[r][j] == 0; --j) {
                cMin = min(cMin, j);
            }

            for (int j = rMin; j <= rMax; ++j) {
                grid[j][c] = 1;
            }
            for (int j = cMin; j <= cMax; ++j) {
                grid[r][j] = 1;
            }
        }
    }

    // Calculate the remaining number of walls
    int remainingWalls = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            remainingWalls += grid[i][j];
        }
    }

    cout << remainingWalls << endl;
}

int main() {
    cin >> h >> w >> q;
    solve();
    return 0;
}