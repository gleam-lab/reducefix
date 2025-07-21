#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    // Grid to keep track of walls
    vector<vector<bool>> grid(h, vector<bool>(w, true));

    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (!grid[r][c]) continue; // No wall to remove

        grid[r][c] = false; // Remove the wall at (r, c)

        // Remove walls in all four directions
        for (int j = r - 1; j >= 0; --j) if (grid[j][c]) grid[j][c] = false;
        for (int j = r + 1; j < h; ++j) if (grid[j][c]) grid[j][c] = false;
        for (int j = c - 1; j >= 0; --j) if (grid[r][j]) grid[r][j] = false;
        for (int j = c + 1; j < w; ++j) if (grid[r][j]) grid[r][j] = false;
    }

    // Count remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j]) ++remainingWalls;
        }
    }

    cout << remainingWalls << endl;

    return 0;
}