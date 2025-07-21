#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> has_wall(H, vector<bool>(W, true));
    vector<set<int>> row_left(H), row_right(H);
    vector<set<int, greater<int>>> col_up(W), col_down(W);

    // Initialize the sets with all cells having walls
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            row_right[r].insert(c);
            col_down[c].insert(r);
        }
    }

    for (int r = 0; r < H; ++r) {
        for (int c = W - 1; c >= 0; --c) {
            row_left[r].insert(c);
        }
    }

    for (int c = 0; c < W; ++c) {
        for (int r = H - 1; r >= 0; --r) {
            col_up[c].insert(r);
        }
    }

    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        if (has_wall[R][C]) {
            // Destroy the wall at (R,C)
            has_wall[R][C] = false;

            row_left[R].erase(C);
            row_right[R].erase(C);
            col_up[C].erase(R);
            col_down[C].erase(R);
        } else {
            // Look in all 4 directions: Up, Down, Left, Right

            // Up
            if (!col_up[C].empty()) {
                auto it = col_up[C].lower_bound(R);
                if (it != col_up[C].end()) {
                    int x = *it;
                    if (x < R && has_wall[x][C]) {
                        has_wall[x][C] = false;
                        row_left[x].erase(C);
                        row_right[x].erase(C);
                        col_up[C].erase(x);
                        col_down[C].erase(x);
                    }
                }
            }

            // Down
            if (!col_down[C].empty()) {
                auto it = col_down[C].upper_bound(R);
                if (it != col_down[C].end()) {
                    int x = *it;
                    if (x > R && has_wall[x][C]) {
                        has_wall[x][C] = false;
                        row_left[x].erase(C);
                        row_right[x].erase(C);
                        col_up[C].erase(x);
                        col_down[C].erase(x);
                    }
                }
            }

            // Left
            if (!row_left[R].empty()) {
                auto it = row_left[R].lower_bound(C);
                if (it != row_left[R].end()) {
                    int y = *it;
                    if (y < C && has_wall[R][y]) {
                        has_wall[R][y] = false;
                        row_left[R].erase(y);
                        row_right[R].erase(y);
                        col_up[y].erase(R);
                        col_down[y].erase(R);
                    }
                }
            }

            // Right
            if (!row_right[R].empty()) {
                auto it = row_right[R].upper_bound(C);
                if (it != row_right[R].end()) {
                    int y = *it;
                    if (y > C && has_wall[R][y]) {
                        has_wall[R][y] = false;
                        row_left[R].erase(y);
                        row_right[R].erase(y);
                        col_up[y].erase(R);
                        col_down[y].erase(R);
                    }
                }
            }
        }
    }

    // Count remaining walls
    long long count = 0;
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            if (has_wall[r][c]) count++;
        }
    }

    cout << count << endl;
}