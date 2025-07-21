#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<bool>> grid(h + 1, vector<bool>(w + 1, true)); // +1 for 1-based indexing

    while (q--) {
        int r, c;
        cin >> r >> c;
        if (!grid[r][c]) continue; // If there's no wall, skip

        grid[r][c] = false; // Place bomb here

        r = min(r, h); c = min(c, w);

        // Remove walls in 4 directions, up, down, left, right
        for (int i = 1; i < r; ++i) grid[i][c] = false;
        for (int i = r + 1; i <= h; ++i) grid[i][c] = false;
        for (int j = 1; j < c; ++j) grid[r][j] = false;
        for (int j = c + 1; j <= w; ++j) grid[r][j] = false;
    }

    // Count remaining walls
    int remaining = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (grid[i][j]) remaining++;
        }
    }

    cout << remaining << endl;

    return 0;
}