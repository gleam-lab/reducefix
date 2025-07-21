#include <vector>
#include <iostream>
using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> grid(H, vector<bool>(W, true));
    int remainingWalls = H * W; // Initially, all walls are present

    for (int q = 0; q < Q; ++q) {
        int r, c;
        cin >> r >> c;
        --r; --c; // Convert to 0-based index

        if (grid[r][c]) {
            // Bomb destroys the wall at (r, c)
            grid[r][c] = false;
            remainingWalls--;
        } else {
            // Bomb destroys the walls around (r, c)
            // Look up
            for (int i = r - 1; i >= 0 && grid[i][c]; --i) {
                grid[i][c] = false;
                remainingWalls--;
            }
            // Look down
            for (int i = r + 1; i < H && grid[i][c]; ++i) {
                grid[i][c] = false;
                remainingWalls--;
            }
            // Look left
            for (int j = c - 1; j >= 0 && grid[r][j]; --j) {
                grid[r][j] = false;
                remainingWalls--;
            }
            // Look right
            for (int j = c + 1; j < W && grid[r][j]; ++j) {
                grid[r][j] = false;
                remainingWalls--;
            }
        }
    }

    cout << remainingWalls << endl;

    return 0;
}