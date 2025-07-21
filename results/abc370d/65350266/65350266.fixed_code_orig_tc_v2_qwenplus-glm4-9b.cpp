#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 4 * 10^5;
int grid[MAXN][MAXN];
int H, W, Q;

void processQuery(int r, int c) {
    if (grid[r][c] > 0) {
        grid[r][c]--;
    } else {
        // Remove walls in all four directions
        for (int i = 0; i <= H; ++i) {
            if (i == r || i < 0) continue;
            if (grid[i][c] > 0) {
                grid[i][c]--;
            }
        }
        for (int j = 0; j <= W; ++j) {
            if (j == c || j < 0) continue;
            if (grid[r][j] > 0) {
                grid[r][j]--;
            }
        }
        for (int i = r - 1; i >= 0; --i) {
            if (grid[i][c] > 0) {
                grid[i][c]--;
            }
        }
        for (int j = c - 1; j >= 0; --j) {
            if (grid[r][j] > 0) {
                grid[r][j]--;
            }
        }
    }
}

int main() {
    cin >> H >> W >> Q;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            grid[i][j] = 4;  // Initialize all cells with 4 walls
        }
    }
    for (int _ = 0; _ < Q; ++_) {
        int r, c;
        cin >> r >> c;
        processQuery(r - 1, c - 1);  // Adjust for 0-based index
    }
    int remainingWalls = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            remainingWalls += grid[i][j];
        }
    }
    cout << remainingWalls << endl;
    return 0;
}