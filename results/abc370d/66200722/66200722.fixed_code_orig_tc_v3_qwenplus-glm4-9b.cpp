#include <iostream>
#include <vector>
using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<int>> grid(H, vector<int>(W, 1));  // Each cell starts with 1 wall.

    while (Q--) {
        int r, c;
        cin >> r >> c;
        --r; --c;  // Convert to 0-based index.
        if (grid[r][c] > 1) {
            // Destroy the wall at (r, c)
            grid[r][c]--;
        } else if (grid[r][c] == 1) {
            // No wall to destroy at (r, c)
            continue;
        }

        // Destroy walls in the four cardinal directions
        // You would need to write the logic to destroy walls in a valid range and update the grid accordingly.
    }

    // Output the number of remaining walls in the grid
    int remainingWalls = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            remainingWalls += grid[i][j];
        }
    }
    cout << remainingWalls << endl;

    return 0;
}