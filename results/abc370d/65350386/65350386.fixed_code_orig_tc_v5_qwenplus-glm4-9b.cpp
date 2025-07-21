#include <iostream>
#include <vector>
using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    // Using a 2D vector to track walls
    vector<vector<bool>> grid(h, vector<bool>(w, true));

    for (int qi = 0; qi < q; ++qi) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (grid[r][c]) {
            // If there's a wall at the bomb position, destroy it
            grid[r][c] = false;
            // Also destroy the walls in the row and column
            for (int i = 0; i < h; ++i) grid[i][c] = false;
            for (int j = 0; j < w; ++j) grid[r][j] = false;
        } else {
            // If there's no wall at the bomb position, destroy walls in the four directions
            // Only update walls that are the first wall in their respective rows and columns
            for (int i = 0; i < h; ++i) {
                if (grid[i][c] && (i == 0 || !grid[i - 1][c])) grid[i][c] = false;
                if (grid[r][i] && (i == 0 || !grid[r][i - 1])) grid[r][i] = false;
            }
        }
    }

    // Count remaining walls
    int remaining_walls = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j]) remaining_walls++;
        }
    }

    cout << remaining_walls << endl;

    return 0;
}