#include <vector>
#include <iostream>

using namespace std;

struct Grid {
    vector<vector<int>> walls;
    int remainingWalls;

    Grid(int H, int W) : walls(H, vector<int>(W, -1)), remainingWalls(H * W) {}

    // Place a bomb at a cell (r, c)
    void placeBomb(int r, int c, int H, int W) {
        if (walls[r][c] != -1) {
            remainingWalls--;
            walls[r][c] = -1;
        } else {
            // Remove walls above and below
            for (int i = max(r - 1, 0); i < min(r + 2, H); i++) {
                if (i != r && walls[i][c] != -1) {
                    remainingWalls--;
                    walls[i][c] = -1;
                }
            }
            // Remove walls left and right
            for (int j = max(c - 1, 0); j < min(c + 2, W); j++) {
                if (j != c && walls[r][j] != -1) {
                    remainingWalls--;
                    walls[r][j] = -1;
                }
            }
        }
    }
};

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    Grid grid(H, W);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int r, c;
            cin >> r >> c;
            grid.placeBomb(r - 1, c - 1, H, W);
        }
    }

    cout << grid.remainingWalls << endl;

    return 0;
}