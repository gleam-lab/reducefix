#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<int>> grid(h, vector<int>(w, 1)); // 1 represents walls

    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        r--; c--; // Convert to 0-indexed

        // Check if there's a wall at (r, c)
        if (grid[r][c] == 1) {
            grid[r][c] = 0; // Destroy the wall
        } else {
            // No wall at (r, c), so destroy all walls around it
            // Look vertically up and down
            for (int i = 0; i < h; i++) {
                if (i != r && grid[i][c] == 1) {
                    grid[i][c] = 0; // Destroy the wall
                }
            }
            // Look horizontally left and right
            for (int j = 0; j < w; j++) {
                if (j != c && grid[r][j] == 1) {
                    grid[r][j] = 0; // Destroy the wall
                }
            }
        }
    }

    // Count the remaining walls
    int remaining_walls = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == 1) {
                remaining_walls++;
            }
        }
    }

    cout << remaining_walls << endl;

    return 0;
}