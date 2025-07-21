#include <iostream>
using namespace std;

const int MAX_H = 50010;
const int MAX_W = 50010;

int H, W, Q;
int grid[MAX_H][MAX_W];

void destroyWalls(int r, int c, int dr, int dc) {
    while (r >= 0 && r < H && c >= 0 && c < W && grid[r][c] == 1) {
        grid[r][c] = 0;
        r += dr;
        c += dc;
    }
}

int main() {
    cin >> H >> W >> Q;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            grid[i][j] = 1;
        }
    }

    while (Q--) {
        int r, c;
        cin >> r >> c;
        --r; --c;
        
        if (grid[r][c] == 1) {
            grid[r][c] = 0;  // Bomb destroys the wall at (r, c)
        } else {
            // Destroy walls in all four directions
            destroyWalls(r - 1, c, -1, 0);  // Up
            destroyWalls(r + 1, c, 1, 0);   // Down
            destroyWalls(r, c - 1, 0, -1);  // Left
            destroyWalls(r, c + 1, 0, 1);   // Right
        }
    }

    int remainingWalls = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] == 1) {
                remainingWalls++;
            }
        }
    }

    cout << remainingWalls << endl;
    return 0;
}