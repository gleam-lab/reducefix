#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> has_wall(H, vector<bool>(W, true));
    vector<vector<int>> left(W, vector<int>(H, -1));
    vector<vector<int>> right(W, vector<int>(H, -1));
    vector<vector<int>> up(H, vector<int>(W, -1));
    vector<vector<int>> down(H, vector<int>(W, -1));

    // Initialize neighbor pointers
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            left[j][i] = j - 1;
            right[j][i] = j + 1;
            up[i][j] = i - 1;
            down[i][j] = i + 1;
        }
    }

    auto move_pointers = [&](int r, int c) {
        // Left direction
        for (int j = c - 1; j >= 0; --j) {
            if (has_wall[r][j]) {
                left[c][r] = left[j][r];
                break;
            }
        }
        // Right direction
        for (int j = c + 1; j < W; ++j) {
            if (has_wall[r][j]) {
                right[c][r] = right[j][r];
                break;
            }
        }
        // Up direction
        for (int i = r - 1; i >= 0; --i) {
            if (has_wall[i][c]) {
                up[r][c] = up[i][c];
                break;
            }
        }
        // Down direction
        for (int i = r + 1; i < H; ++i) {
            if (has_wall[i][c]) {
                down[r][c] = down[i][c];
                break;
            }
        }
    };

    while (Q--) {
        int R, C;
        cin >> R >> C;
        int r = R - 1, c = C - 1;

        if (has_wall[r][c]) {
            has_wall[r][c] = false;
            move_pointers(r, c);
        } else {
            // Destroy the first wall in each direction
            // Left
            int l = left[c][r];
            if (l >= 0 && has_wall[r][l]) {
                has_wall[r][l] = false;
                move_pointers(r, l);
            }

            // Right
            int ri = right[c][r];
            if (ri < W && has_wall[r][ri]) {
                has_wall[r][ri] = false;
                move_pointers(r, ri);
            }

            // Up
            int u = up[r][c];
            if (u >= 0 && has_wall[u][c]) {
                has_wall[u][c] = false;
                move_pointers(u, c);
            }

            // Down
            int d = down[r][c];
            if (d < H && has_wall[d][c]) {
                has_wall[d][c] = false;
                move_pointers(d, c);
            }
        }
    }

    int remaining = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (has_wall[i][j]) remaining++;
        }
    }

    cout << remaining << endl;
    return 0;
}