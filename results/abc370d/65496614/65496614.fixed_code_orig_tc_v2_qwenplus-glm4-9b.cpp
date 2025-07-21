#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<int>> grid(h + 1, vector<int>(w + 1, 4)); // 4 walls initially

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            grid[i][j] = 4; // Set the initial number of walls to 4
        }
    }

    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;

        if (grid[r][c] > 1) {
            // Remove one wall
            grid[r][c]--;
        } else {
            // Remove all walls
            for (int i = 1; i <= h; i++) {
                grid[i][c]--;
            }
            for (int j = 1; j <= w; j++) {
                grid[r][j]--;
            }
            grid[r][c] = 0; // No walls left in this cell
        }
    }

    int remainingWalls = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            remainingWalls += grid[i][j];
        }
    }

    cout << remainingWalls << endl;

    return 0;
}