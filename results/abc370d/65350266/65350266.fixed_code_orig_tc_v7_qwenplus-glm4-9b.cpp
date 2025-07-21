#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> walls(h, vector<int>(w, 1)); // 1 means there is a wall

    while (q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        if (walls[r][c] == 1) {
            walls[r][c] = 0; // Destroy the wall
        } else {
            // Destroy the first wall in each direction
            // Vertical walls
            for (int i = 0; i < h && walls[i][c] == 1; ++i) {
                walls[i][c] = 0;
            }
            for (int i = r; i >= 0 && walls[i][c] == 1; --i) {
                walls[i][c] = 0;
            }
            // Horizontal walls
            for (int j = 0; j < w && walls[r][j] == 1; ++j) {
                walls[r][j] = 0;
            }
            for (int j = c; j >= 0 && walls[r][j] == 1; --j) {
                walls[r][j] = 0;
            }
        }
    }

    int remaining_walls = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            remaining_walls += walls[i][j];
        }
    }

    cout << remaining_walls << endl;
    return 0;
}