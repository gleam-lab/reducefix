#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> grid(h, vector<int>(w, 1));
    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        if (grid[r][c] == 1) {
            grid[r][c] = 0;
        } else {
            // Find and remove walls above
            for (int i = r - 1; i >= 0 && grid[i][c] == 1; --i) {
                grid[i][c] = 0;
            }
            // Remove wall at the row if it is completely destroyed
            int destroyed_row = 1;
            for (int j = 0; j < w; ++j) {
                if (grid[r][j] == 1) {
                    destroyed_row = 0;
                    break;
                }
            }
            if (destroyed_row) {
                grid[r] = vector<int>(w, 0);
            }
            // Find and remove walls below
            for (int i = r + 1; i < h && grid[i][c] == 1; ++i) {
                grid[i][c] = 0;
            }
            // Remove wall at the row if it is completely destroyed
            destroyed_row = 1;
            for (int j = 0; j < w; ++j) {
                if (grid[r][j] == 1) {
                    destroyed_row = 0;
                    break;
                }
            }
            if (destroyed_row) {
                grid[r] = vector<int>(w, 0);
            }
            // Find and remove walls to the left
            for (int j = c - 1; j >= 0 && grid[r][j] == 1; --j) {
                grid[r][j] = 0;
            }
            // Remove wall at the column if it is completely destroyed
            int destroyed_col = 1;
            for (int i = 0; i < h; ++i) {
                if (grid[i][c] == 1) {
                    destroyed_col = 0;
                    break;
                }
            }
            if (destroyed_col) {
                for (int i = 0; i < h; ++i) {
                    grid[i][c] = 0;
                }
            }
            // Find and remove walls to the right
            for (int j = c + 1; j < w && grid[r][j] == 1; ++j) {
                grid[r][j] = 0;
            }
            // Remove wall at the column if it is completely destroyed
            destroyed_col = 1;
            for (int i = 0; i < h; ++i) {
                if (grid[i][c] == 1) {
                    destroyed_col = 0;
                    break;
                }
            }
            if (destroyed_col) {
                for (int i = 0; i < h; ++i) {
                    grid[i][c] = 0;
                }
            }
        }
    }
    // Calculate the remaining number of walls
    int remaining_walls = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            remaining_walls += grid[i][j];
        }
    }
    cout << remaining_walls << "\n";
    return 0;
}