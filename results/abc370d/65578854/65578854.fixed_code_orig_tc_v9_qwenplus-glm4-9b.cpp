#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAX_SIZE = 50010;

bool grid[MAX_SIZE][MAX_SIZE];

void removeWalls(int h, int w) {
    // Remove wall directly below
    if (h + 1 < MAX_SIZE && grid[h + 1][w]) {
        grid[h + 1][w] = false;
        removeWalls(h + 1, w);
    }
    // Remove wall directly above
    if (h - 1 >= 0 && grid[h - 1][w]) {
        grid[h - 1][w] = false;
        removeWalls(h - 1, w);
    }
    // Remove wall to the right
    if (w + 1 < MAX_SIZE && grid[h][w + 1]) {
        grid[h][w + 1] = false;
        removeWalls(h, w + 1);
    }
    // Remove wall to the left
    if (w - 1 >= 0 && grid[h][w - 1]) {
        grid[h][w - 1] = false;
        removeWalls(h, w - 1);
    }
}

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    // Initialize the grid with walls
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            grid[i][j] = true;
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        // Place a bomb and remove walls
        if (grid[r][c]) {
            grid[r][c] = false;
            removeWalls(r, c);
        }
    }

    // Count remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j]) {
                remainingWalls++;
            }
        }
    }

    cout << remainingWalls << endl;
    return 0;
}