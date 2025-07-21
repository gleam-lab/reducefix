#include <iostream>
#include <vector>
using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<int>> grid(h, vector<int>(w, 4)); // 4 walls initially

    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        r--; c--; // Convert to 0-based index

        if (grid[r][c] > 0) {
            // Bomb destroys a wall
            grid[r][c]--;
            // Check four directions
            if (r > 0 && grid[r - 1][c] == 4) grid[r - 1][c]--;
            if (r < h - 1 && grid[r + 1][c] == 4) grid[r + 1][c]--;
            if (c > 0 && grid[r][c - 1] == 4) grid[r][c - 1]--;
            if (c < w - 1 && grid[r][c + 1] == 4) grid[r][c + 1]--;
        }
    }

    int remaining_walls = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            remaining_walls += grid[i][j];
        }
    }

    cout << remaining_walls << endl;

    return 0;
}