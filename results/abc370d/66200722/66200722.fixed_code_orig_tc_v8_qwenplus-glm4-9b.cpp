#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<int>> grid(h, vector<int>(w));
    vector<vector<bool>> destroyed(h, vector<bool>(w, false));

    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        --r; --c; // Convert to 0-based index

        if (!destroyed[r][c]) { // If there's a wall at (r, c)
            grid[r][c] = 1; // Bomb destroys the wall
            destroyed[r][c] = true;
        } else { // If there's no wall at (r, c)
            // Destroy horizontal walls
            int left = c;
            while (left >= 0 && !destroyed[r][left]) {
                grid[r][left] = 1;
                destroyed[r][left] = true;
                --left;
            }

            int right = c;
            while (right < w && !destroyed[r][right]) {
                grid[r][right] = 1;
                destroyed[r][right] = true;
                ++right;
            }

            // Destroy vertical walls
            int top = r;
            while (top >= 0 && !destroyed[top][c]) {
                grid[top][c] = 1;
                destroyed[top][c] = true;
                --top;
            }

            int bottom = r;
            while (bottom < h && !destroyed[bottom][c]) {
                grid[bottom][c] = 1;
                destroyed[bottom][c] = true;
                ++bottom;
            }
        }
    }

    // Calculate the number of remaining walls
    long long remaining_walls = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!destroyed[i][j]) {
                remaining_walls++;
            }
        }
    }

    cout << remaining_walls << endl;

    return 0;
}