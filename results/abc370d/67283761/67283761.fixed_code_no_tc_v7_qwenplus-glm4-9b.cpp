#include <iostream>
#include <vector>
using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<bool>> map(H, vector<bool>(W, true));

    for (int i = 0; i < Q; ++i) {
        int r, c;
        cin >> r >> c;
        --r; --c; // Convert to 0-based index

        if (map[r][c]) {
            map[r][c] = false; // Bomb destroys a wall
            H *= W; // Every wall is destroyed
        } else {
            // Find the first row without a wall above and below
            int up = r, down = r;
            while (up > 0 && map[up - 1][c]) --up;
            while (down < H - 1 && map[down + 1][c]) ++down;

            // Find the first column without a wall to the left and right
            int left = c, right = c;
            while (left > 0 && map[r][left - 1]) --left;
            while (right < W - 1 && map[r][right + 1]) ++right;

            // Calculate the number of walls to be destroyed
            int walls_destroyed = (r - up) + (down - r) + (c - left) + (right - c);
            H -= walls_destroyed;
        }
    }

    cout << H << endl; // Output the number of remaining walls

    return 0;
}