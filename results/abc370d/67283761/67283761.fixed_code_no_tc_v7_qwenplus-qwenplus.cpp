#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    // We'll use a single 2D grid to track if a wall exists
    vector<vector<bool>> has_wall(H, vector<bool>(W, true));

    // For each direction: Up, Down, Left, Right
    // We maintain the next available wall in each direction for each cell
    vector<vector<int>> up(H, vector<int>(W));
    vector<vector<int>> down(H, vector<int>(W));
    vector<vector<int>> left(H, vector<int>(W));
    vector<vector<int>> right(H, vector<int>(W));

    // Initialize the direction maps
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            up[i][j] = i - 1;
            down[i][j] = i + 1;
            left[i][j] = j - 1;
            right[i][j] = j + 1;
        }
    }

    auto valid = [&](int r, int c) {
        return r >= 0 && r < H && c >= 0 && c < W;
    };

    while (Q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (has_wall[r][c]) {
            // Case 1: Bomb destroys the wall at (r, c)
            has_wall[r][c] = false;

            // Update the direction maps
            if (valid(r-1, c)) down[r-1][c] = down[r][c];
            if (valid(r+1, c)) up[r+1][c] = up[r][c];
            if (valid(r, c-1)) right[r][c-1] = right[r][c];
            if (valid(r, c+1)) left[r][c+1] = left[r][c];
        } else {
            // Case 2: Bomb destroys first walls in each of the 4 directions
            vector<tuple<int, int, int, int>> dirs = {
                {-1, 0, up[r][c], c},    // Up
                {1, 0, down[r][c], c},   // Down
                {0, -1, r, left[r][c]},  // Left
                {0, 1, r, right[r][c]}   // Right
            };

            for (const auto& [dr, dc, nr, nc] : dirs) {
                if (valid(nr, nc) && has_wall[nr][nc]) {
                    has_wall[nr][nc] = false;

                    // Update direction maps for the neighbors of the destroyed cell
                    if (valid(nr-1, nc)) down[nr-1][nc] = down[nr][nc];
                    if (valid(nr+1, nc)) up[nr+1][nc] = up[nr][nc];
                    if (valid(nr, nc-1)) right[nr][nc-1] = right[nr][nc];
                    if (valid(nr, nc+1)) left[nr][nc+1] = left[nr][nc];
                }
            }
        }
    }

    // Count remaining walls
    int count = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (has_wall[i][j]) count++;
        }
    }

    cout << count << endl;

    return 0;
}