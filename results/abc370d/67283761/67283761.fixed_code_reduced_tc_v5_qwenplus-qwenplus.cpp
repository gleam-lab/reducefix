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

    auto update_row = [&](int r) {
        int prev = -1;
        for (int c = 0; c < W; ++c) {
            if (has_wall[r][c]) {
                if (prev != -1) {
                    right[prev][r] = c;
                    left[c][r] = prev;
                }
                prev = c;
            }
        }
    };

    auto update_col = [&]((int c) {
        int prev = -1;
        for (int r = 0; r < H; ++r) {
            if (has_wall[r][c]) {
                if (prev != -1) {
                    down[prev][c] = r;
                    up[r][c] = prev;
                }
                prev = r;
            }
        }
    };

    // Initialize linked structure
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            if (!has_wall[r][c]) continue;
            if (c > 0 && has_wall[r][c-1]) left[c][r] = c-1;
            if (c < W-1 && has_wall[r][c+1]) right[c][r] = c+1;
            if (r > 0 && has_wall[r-1][c]) up[r][c] = r-1;
            if (r < H-1 && has_wall[r+1][c]) down[r][c] = r+1;
        }
    }

    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;
        --R; --C;

        if (has_wall[R][C]) {
            has_wall[R][C] = false;
            
            // Update neighbors in all four directions
            if (left[C][R] != -1) right[C][left[C][R]] = right[C][R];
            if (right[C][R] != -1) left[right[C][R]][R] = left[C][R];

            if (up[R][C] != -1) down[up[R][C]][C] = down[R][C];
            if (down[R][C] != -1) up[down[R][C]][C] = up[R][C];

            // Update pointers for current cell
            left[C][R] = right[C][R] = -1;
            up[R][C] = down[R][C] = -1;
        } else {
            // Look up
            if (up[R][C] == -1) {
                int r = R - 1;
                while (r >= 0 && !has_wall[r][C]) --r;
                if (r >= 0) {
                    has_wall[r][C] = false;
                    // Update neighbors
                    int below = r + 1;
                    while (below < R && !has_wall[below][C]) ++below;
                    if (below < R) {
                        up[below][C] = r;
                        down[r][C] = below;
                    } else {
                        down[r][C] = -1;
                    }
                }
            }

            // Look down
            if (down[R][C] == -1) {
                int r = R + 1;
                while (r < H && !has_wall[r][C]) ++r;
                if (r < H) {
                    has_wall[r][C] = false;
                    // Update neighbors
                    int above = r - 1;
                    while (above > R && !has_wall[above][C]) --above;
                    if (above > R) {
                        down[above][C] = r;
                        up[r][C] = above;
                    } else {
                        up[r][C] = -1;
                    }
                }
            }

            // Look left
            if (left[C][R] == -1) {
                int c = C - 1;
                while (c >= 0 && !has_wall[R][c]) --c;
                if (c >= 0) {
                    has_wall[R][c] = false;
                    // Update neighbors
                    int right_c = c + 1;
                    while (right_c < C && !has_wall[R][right_c]) ++right_c;
                    if (right_c < C) {
                        left[right_c][R] = c;
                        right[c][R] = right_c;
                    } else {
                        right[c][R] = -1;
                    }
                }
            }

            // Look right
            if (right[C][R] == -1) {
                int c = C + 1;
                while (c < W && !has_wall[R][c]) ++c;
                if (c < W) {
                    has_wall[R][c] = false;
                    // Update neighbors
                    int left_c = c - 1;
                    while (left_c > C && !has_wall[R][left_c]) --left_c;
                    if (left_c > C) {
                        right[left_c][R] = c;
                        left[c][R] = left_c;
                    } else {
                        left[c][R] = -1;
                    }
                }
            }
        }
    }

    int count = 0;
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            if (has_wall[r][c]) ++count;
        }
    }

    cout << count << endl;
    return 0;
}