#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<int>> grid(H, vector<int>(W, 1)); // 1 represents a wall

    for (int i = 0; i < Q; i++) {
        int R_q, C_q;
        cin >> R_q >> C_q;
        R_q--; C_q--;

        // Process horizontal walls
        int row = R_q;
        while (row >= 0 && grid[row][C_q] == 0) {
            grid[row][C_q] = 0;
            row--;
        }
        row = R_q;
        while (row < H && grid[row][C_q] == 0) {
            grid[row][C_q] = 0;
            row++;
        }

        // Process vertical walls
        int col = C_q;
        while (col >= 0 && grid[R_q][col] == 0) {
            grid[R_q][col] = 0;
            col--;
        }
        col = C_q;
        while (col < W && grid[R_q][col] == 0) {
            grid[R_q][col] = 0;
            col++;
        }
    }

    // Count remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if (grid[i][j] == 1)
                remainingWalls++;

    cout << remainingWalls << endl;

    return 0;
}