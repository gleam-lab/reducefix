#include <iostream>
#include <vector>
using namespace std;

const int MAX_H = 50000;
const int MAX_W = 50000;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<vector<bool>> grid(H, vector<bool>(W, true)); // true means wall exists
    int totalWalls = H * W;

    for (int q = 0; q < Q; q++) {
        int R, C;
        cin >> R >> C;
        R--; C--; // Convert to 0-indexed

        if (grid[R][C]) {
            grid[R][C] = false;
            totalWalls--;
        } else {
            // Find the next wall in each direction (up, down, left, right)
            // and destroy them
            // This is a simplified example; you may need to handle edge cases
            for (int i = R - 1; i >= 0; i--) {
                if (grid[i][C]) {
                    grid[i][C] = false;
                    totalWalls--;
                } else break;
            }

            for (int i = R + 1; i < H; i++) {
                if (grid[i][C]) {
                    grid[i][C] = false;
                    totalWalls--;
                } else break;
            }

            for (int j = C - 1; j >= 0; j--) {
                if (grid[R][j]) {
                    grid[R][j] = false;
                    totalWalls--;
                } else break;
            }

            for (int j = C + 1; j < W; j++) {
                if (grid[R][j]) {
                    grid[R][j] = false;
                    totalWalls--;
                } else break;
            }
        }
    }

    cout << totalWalls << endl;
    return 0;
}