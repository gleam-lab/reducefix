#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 4e5 + 5;

vector<vector<int>> grid(MAXN, vector<int>(MAXN, 1)); // Initially, all cells have walls.

void destroyWalls(int r, int c) {
    // Check if there is a wall at (r, c)
    if (grid[r][c] == 0) return;

    // Mark the wall at (r, c) as destroyed
    grid[r][c] = 0;

    // Remove walls up to the next open cell
    for (int i = r - 1; i >= 0 && grid[i][c] == 0; --i) {
        grid[i][c] = 1;
    }

    // Remove walls down to the next open cell
    for (int i = r + 1; i < MAXN && grid[i][c] == 0; ++i) {
        grid[i][c] = 1;
    }

    // Remove walls left to the next open cell
    for (int j = c - 1; j >= 0 && grid[r][j] == 0; --j) {
        grid[r][j] = 1;
    }

    // Remove walls right to the next open cell
    for (int j = c + 1; j < MAXN && grid[r][j] == 0; ++j) {
        grid[r][j] = 1;
    }
}

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    for (int i = 0; i < Q; ++i) {
        int r, c;
        cin >> r >> c;
        destroyWalls(r - 1, c - 1); // Convert 1-based index to 0-based
    }

    // Count the number of remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            remainingWalls += grid[i][j];
        }
    }

    cout << remainingWalls << endl;

    return 0;
}