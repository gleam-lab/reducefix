#include <iostream>
#include <vector>
using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<int>> grid(H, vector<int>(W, 1)); // Initialize grid with walls

    for (int q = 0; q < Q; q++) {
        int R, C;
        cin >> R >> C;
        R--; C--; // Convert to 0-based index

        if (grid[R][C] == 1) {
            grid[R][C] = 0; // Destroy the wall at (R, C)
        } else {
            // Find and destroy walls in all four directions
            // UP
            for (int i = R - 1; i >= 0 && grid[i][C] == 1; i--) {
                grid[i][C] = 0;
            }
            // DOWN
            for (int i = R + 1; i < H && grid[i][C] == 1; i++) {
                grid[i][C] = 0;
            }
            // LEFT
            for (int j = C - 1; j >= 0 && grid[R][j] == 1; j--) {
                grid[R][j] = 0;
            }
            // RIGHT
            for (int j = C + 1; j < W && grid[R][j] == 1; j++) {
                grid[R][j] = 0;
            }
        }
    }

    // Count remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            remainingWalls += grid[i][j];
        }
    }

    cout << remainingWalls << endl;
    return 0;
}