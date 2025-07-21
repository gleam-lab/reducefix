#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int INF = 2e9;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    // Initialize the grid with walls
    vector<vector<bool>> grid(H, vector<bool>(W, true));
    int totalWalls = 2 * H * W - 4;

    // Process each query
    for (int i = 0; i < Q; i++) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        // Check and destroy the wall at (R, C) if it exists
        if (grid[R][C]) {
            grid[R][C] = false;
            totalWalls--;
        } else {
            // Destroy walls in all four directions
            int r, c;
            // Up
            r = max(0, R - 1);
            while (r >= 0 && !grid[r][C]) r--;
            while (r >= 0) {
                grid[r][C] = false;
                totalWalls--;
                r--;
            }
            // Down
            r = min(H - 1, R + 1);
            while (r < H && !grid[r][C]) r++;
            while (r < H) {
                grid[r][C] = false;
                totalWalls--;
                r++;
            }
            // Left
            c = max(0, C - 1);
            while (c >= 0 && !grid[R][c]) c--;
            while (c >= 0) {
                grid[R][c] = false;
                totalWalls--;
                c--;
            }
            // Right
            c = min(W - 1, C + 1);
            while (c < W && !grid[R][c]) c++;
            while (c < W) {
                grid[R][c] = false;
                totalWalls--;
                c++;
            }
        }
    }

    // Output the number of remaining walls
    cout << totalWalls << endl;

    return 0;
}