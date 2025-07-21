#include <iostream>
#include <vector>
using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<int>> grid(H, vector<int>(W, 1)); // 1 represents a wall

    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;
        --R; --C; // Convert to 0-based index

        if (grid[R][C] == 1) { // If there is a wall at (R, C)
            grid[R][C] = 0; // Destroy the wall
        } else { // If there is no wall at (R, C)
            // Destroy the upper wall
            for (int i = R - 1; i >= 0 && grid[i][C] == 1; --i) {
                grid[i][C] = 0;
            }
            // Destroy the lower wall
            for (int i = R + 1; i < H && grid[i][C] == 1; ++i) {
                grid[i][C] = 0;
            }
            // Destroy the left wall
            for (int j = C - 1; j >= 0 && grid[R][j] == 1; --j) {
                grid[R][j] = 0;
            }
            // Destroy the right wall
            for (int j = C + 1; j < W && grid[R][j] == 1; ++j) {
                grid[R][j] = 0;
            }
        }
    }

    int remaining_walls = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            remaining_walls += grid[i][j];
        }
    }

    cout << remaining_walls << endl;
    return 0;
}