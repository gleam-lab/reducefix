#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_H = 400010;
const int MAX_W = 69001;

vector<pair<int, int>> grid[MAX_H][MAX_W]; // grid[i][j] stores walls at row i and column j

bool removeWall(int row, int col) {
    if (grid[row][col].empty()) return false;

    // Check the walls in the current row to remove them if they are not blocked by other walls
    int left = upper_bound(grid[row][col].begin(), grid[row][col].end(), make_pair(col, INT_MAX)).index();
    int right = lower_bound(grid[row][col].begin(), grid[row][col].end(), make_pair(col, INT_MIN)).index();
    for (int i = left; i < right; ++i) {
        if (grid[row][col][i].first == col) {
            grid[row][col].erase(grid[row][col].begin() + i);
            return true;
        }
    }

    // Check the walls in the current column to remove them if they are not blocked by other walls
    left = upper_bound(grid[row][col].begin(), grid[row][col].end(), make_pair(INT_MAX, col)).index();
    right = lower_bound(grid[row][col].begin(), grid[row][col].end(), make_pair(INT_MIN, col)).index();
    for (int i = left; i < right; ++i) {
        if (grid[row][col][i].second == col) {
            grid[row][col].erase(grid[row][col].begin() + i);
            return true;
        }
    }
    return false;
}

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            grid[i][j].push_back({i, j});
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        if (!removeWall(r, c)) {
            // Remove walls in all four directions
            int rowStart = max(r - 1, 1);
            int rowEnd = min(r + 1, h);
            int colStart = max(c - 1, 1);
            int colEnd = min(c + 1, w);

            for (int i = rowStart; i <= rowEnd; ++i) {
                for (int j = colStart; j <= colEnd; ++j) {
                    removeWall(i, j);
                }
            }
        }
    }

    int remainingWalls = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            remainingWalls += grid[i][j].size();
        }
    }

    cout << remainingWalls << endl;

    return 0;
}