#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<int>> grid(H + 1, vector<int>(W + 1, 1)); // +1 for 1-based indexing

    while (Q--) {
        int R, C;
        cin >> R >> C;
        if (grid[R][C] == 1) { // If there's a wall at (R, C)
            grid[R][C] = 0; // Destroy it
        } else {
            // No wall at (R, C), destroy walls upwards, downwards, left and right
            // Destroy walls upwards
            for (int i = R - 1; i > 0 && grid[i][C] == 1; --i) {
                grid[i][C] = 0;
            }
            // Destroy walls downwards
            for (int i = R + 1; i <= H && grid[i][C] == 1; ++i) {
                grid[i][C] = 0;
            }
            // Destroy walls to the left
            for (int j = C - 1; j > 0 && grid[R][j] == 1; --j) {
                grid[R][j] = 0;
            }
            // Destroy walls to the right
            for (int j = C + 1; j <= W && grid[R][j] == 1; ++j) {
                grid[R][j] = 0;
            }
        }
    }

    int remainingWalls = 0;
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            remainingWalls += grid[i][j];
        }
    }

    cout << remainingWalls << endl;
    return 0;
}