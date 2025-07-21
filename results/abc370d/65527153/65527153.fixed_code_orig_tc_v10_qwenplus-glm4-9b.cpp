#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> grid(H + 1, vector<bool>(W + 1, true)); // Using grid[H+1][W+1] to avoid boundary issues

    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;
        --R; --C; // Convert to 0-based index
        if (grid[R][C]) {
            // There is a wall, destroy it
            grid[R][C] = false;
        } else {
            // There is no wall, destroy walls in the four directions
            for (int i = 1; i <= H; ++i) {
                if (grid[i][C]) grid[i][C] = false;
            }
            for (int j = 1; j <= W; ++j) {
                if (grid[R][j]) grid[R][j] = false;
            }
        }
    }

    int remainingWalls = 0;
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (grid[i][j]) {
                ++remainingWalls;
            }
        }
    }

    cout << remainingWalls << endl;

    return 0;
}