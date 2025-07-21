#include <iostream>
#include <vector>
using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> gridWalls(h, vector<bool>(w, true)); // Initialize the grid with walls

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--; // Convert to 0-based index

        if (gridWalls[r][c]) {
            // Bomb destroys the wall at (r, c)
            gridWalls[r][c] = false;
        } else {
            // Bomb destroys surrounding walls
            for (int i = max(r - 1, 0); i <= min(r + 1, h - 1); ++i) {
                if (gridWalls[i][c] && i != r) {
                    gridWalls[i][c] = false; // Destroy wall in the row
                }
            }
            for (int j = max(c - 1, 0); j <= min(c + 1, w - 1); ++j) {
                if (gridWalls[r][j] && j != c) {
                    gridWalls[r][j] = false; // Destroy wall in the column
                }
            }
        }
    }

    // Count remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (gridWalls[i][j]) {
                remainingWalls++;
            }
        }
    }

    cout << remainingWalls << endl;
    return 0;
}