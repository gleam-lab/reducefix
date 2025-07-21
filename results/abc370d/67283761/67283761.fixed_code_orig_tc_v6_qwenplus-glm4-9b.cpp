#include <iostream>
using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<int>> grid(H, vector<int>(W, 1)); // Initialize with 1s for walls.

    for (int i = 0; i < Q; ++i) {
        int R_q, C_q;
        cin >> R_q >> C_q;
        --R_q; --C_q; // Convert 1-based index to 0-based.
        
        if (grid[R_q][C_q] == 1) { // If there's a wall at the given position.
            grid[R_q][C_q] = 0;
            cout << (--H * W) << endl; // Decrement wall count and output.
        } else {
            // Search for walls in all four directions and destroy them.
            int remainingWalls = 0;
            for (int j = 0; j < H; ++j) {
                remainingWalls += grid[j][C_q];
            }
            for (int i = 0; i < W; ++i) {
                remainingWalls += grid[R_q][i];
            }
            remainingWalls -= (H * W) - remainingWalls; // Subtract total walls with remaining walls.
            cout << remainingWalls << endl; // Output remaining walls.
        }
    }

    return 0;
}