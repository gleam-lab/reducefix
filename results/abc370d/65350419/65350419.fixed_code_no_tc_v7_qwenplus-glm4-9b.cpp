#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> grid(h, vector<int>(w, 1)); // Initialize grid with all walls.

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--; // Convert to 0-based index.

        if (grid[r][c] == 1) { // If there is a wall at (r, c)
            grid[r][c] = 0; // Remove the wall.
        } else { // If there is no wall at (r, c)
            // Check and remove vertical walls
            int startV = 0, endV = h;
            while (startV < h && grid[startV][c] == 0) startV++; // Find the first wall from top
            while (endV > 0 && grid[endV-1][c] == 0) endV--; // Find the last wall from bottom

            int startH = 0, endH = w;
            while (startH < w && grid[r][startH] == 0) startH++; // Find the first wall from left
            while (endH > 0 && grid[r][endH-1] == 0) endH--; // Find the last wall from right

            // Remove the walls in the range found
            for (int i = startV; i < endV; i++) grid[i][c] = 0;
            for (int j = startH; j < endH; j++) grid[r][j] = 0;
        }
    }

    // Calculate the number of remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            remainingWalls += grid[i][j];
        }
    }

    cout << remainingWalls << endl;
    return 0;
}