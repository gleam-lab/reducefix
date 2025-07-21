#include <iostream>
#include <vector>

using namespace std;

const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<int>> grid(h, vector<int>(w));
    vector<vector<bool>> destroyed(h, vector<bool>(w, false));

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            grid[i][j] = 1; // Assume all cells have walls initially
        }
    }

    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        --r; --c; // Convert to 0-indexed

        if (!destroyed[r][c]) {
            // Place bomb and destroy the wall
            grid[r][c] = 0;
            destroyed[r][c] = true;

            // Destroy walls in all four directions
            for (int d = 0; d < 4; ++d) {
                int nx = r + dir[d][0];
                int ny = c + dir[d][1];

                while (nx >= 0 && nx < h && ny >= 0 && ny < w && !destroyed[nx][ny]) {
                    grid[nx][ny] = 0;
                    destroyed[nx][ny] = true;
                    nx += dir[d][0];
                    ny += dir[d][1];
                }
            }
        }
    }

    int remaining_walls = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            remaining_walls += grid[i][j];
        }
    }

    cout << remaining_walls << endl;
}