#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    // Use bits for efficient representation of walls
    bitset<4 * 100001> row_walls, col_walls;

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        // Convert 1-based index to 0-based
        r--; c--;
        if (row_walls[r * w + c]) {
            // If there's a wall at this position, just remove it
            row_walls[r * w + c] = 0;
            col_walls[c * h + r] = 0;
        } else {
            // If no wall at this position, remove walls from the column
            for (int i = 0; i < w; i++) {
                if (row_walls[i * w + r] && row_walls[i * w + r].count(i) == 0) {
                    row_walls[i * w + r] = 0;
                    col_walls[c * h + r] = 0;
                }
            }
            // Similarly, remove walls from the row
            for (int i = 0; i < h; i++) {
                if (col_walls[i * h + c] && col_walls[i * h + c].count(i) == 0) {
                    col_walls[i * h + c] = 0;
                    row_walls[r * w + c] = 0;
                }
            }
        }
    }

    // Count the remaining walls
    long long remaining_walls = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            remaining_walls += row_walls[i * w + j] + col_walls[j * h + i];
        }
    }

    cout << remaining_walls << endl;

    return 0;
}