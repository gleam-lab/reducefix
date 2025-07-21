#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> grid(H, vector<bool>(W, true)); // true indicates wall exists

    for (int i = 0; i < Q; ++i) {
        int R, C;
        cin >> R >> C;
        R--; C--; // Convert to 0-based index

        if (grid[R][C]) { // If wall exists at (R, C)
            grid[R][C] = false; // Destroy the wall
        } else { // If no wall exists at (R, C)
            // Destroy walls above and below
            for (int j = 0; j < H; ++j) {
                if (grid[j][C]) {
                    grid[j][C] = false;
                }
            }
            // Destroy walls left and right
            for (int k = 0; k < W; ++k) {
                if (grid[R][k]) {
                    grid[R][k] = false;
                }
            }
        }
    }

    // Count remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j]) {
                remainingWalls++;
            }
        }
    }

    cout << remainingWalls << endl;

    return 0;
}