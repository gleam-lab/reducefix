#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

void solve() {
    int H, W, Q;
    cin >> H >> W >> Q;

    // For each row and column, keep track of the leftmost and rightmost destroyed positions
    vector<int> row_left(W, 0), row_right(W, W - 1);
    vector<int> col_top(H, 0), col_bottom(H, H - 1);

    // Whether a cell is bombed already
    vector<vector<bool>> bombed(H, vector<bool>(W, false));

    while (Q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (bombed[r][c]) {
            // Bomb in all four directions
            // Up
            if (col_top[c] < r) {
                for (int i = col_top[c]; i < r; ++i) {
                    if (!bombed[i][c]) {
                        bombed[i][c] = true;
                        break;
                    }
                }
                col_top[c] = max(col_top[c], r + 1); // Cells above this won't be affected
            }

            // Down
            if (col_bottom[c] > r) {
                for (int i = col_bottom[c]; i > r; --i) {
                    if (!bombed[i][c]) {
                        bombed[i][c] = true;
                        break;
                    }
                }
                col_bottom[c] = min(col_bottom[c], r - 1);
            }

            // Left
            if (row_left[r] < c) {
                for (int j = row_left[r]; j < c; ++j) {
                    if (!bombed[r][j]) {
                        bombed[r][j] = true;
                        break;
                    }
                }
                row_left[r] = max(row_left[r], c + 1);
            }

            // Right
            if (row_right[r] > c) {
                for (int j = row_right[r]; j > c; --j) {
                    if (!bombed[r][j]) {
                        bombed[r][j] = true;
                        break;
                    }
                }
                row_right[r] = min(row_right[r], c - 1);
            }
        } else {
            // Single bomb at current cell
            bombed[r][c] = true;
        }
    }

    // Count remaining walls
    int count = 0;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            if (!bombed[i][j])
                count++;

    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}