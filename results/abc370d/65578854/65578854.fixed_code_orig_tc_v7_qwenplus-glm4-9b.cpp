#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 4e5 + 10;

int H, W, Q;
vector<vector<bool>> grid;

void destroyWalls(int r, int c) {
    // Remove the wall at the given position
    grid[r][c] = false;

    // Destroy the walls in all four directions
    for (int i = r - 1; i >= 0 && grid[i][c]; i--) grid[i][c] = false;
    for (int i = r + 1; i < H && grid[i][c]; i++) grid[i][c] = false;
    for (int j = c - 1; j >= 0 && grid[r][j]; j--) grid[r][j] = false;
    for (int j = c + 1; j < W && grid[r][j]; j++) grid[r][j] = false;
}

int main() {
    cin >> H >> W >> Q;
    grid.resize(H, vector<bool>(W, true)); // Initialize the grid with walls

    int r, c;
    int remainingWalls = H * W; // Start with all walls

    while (Q--) {
        cin >> r >> c;
        if (grid[r - 1][c - 1]) {
            destroyWalls(r - 1, c - 1);
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j]) remainingWalls--; // Count remaining walls
        }
    }

    cout << remainingWalls << endl;
    return 0;
}