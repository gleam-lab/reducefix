#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> has_wall(H, vector<bool>(W, true));

    // For each row, keep a sorted set of columns with walls
    vector<set<int>> row_walls(H);
    // For each column, keep a sorted set of rows with walls
    vector<set<int>> col_walls(W);

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }

    while (Q--) {
        int R, C;
        cin >> R >> C;
        --R;
        --C;

        if (!has_wall[R][C]) {
            // Already no wall here, so look in four directions

            // Left
            auto& cols_left = row_walls[R];
            auto it_l = cols_left.lower_bound(C);
            if (it_l != cols_left.begin()) {
                --it_l;
                int c2 = *it_l;
                cols_left.erase(it_l);
                col_walls[c2].erase(R);
                has_wall[R][c2] = false;
            }

            // Right
            auto it_r = cols_left.upper_bound(C);
            if (it_r != cols_left.end()) {
                int c2 = *it_r;
                cols_left.erase(it_r);
                col_walls[c2].erase(R);
                has_wall[R][c2] = false;
            }

            // Up
            auto& rows_up = col_walls[C];
            auto it_u = rows_up.lower_bound(R);
            if (it_u != rows_up.begin()) {
                --it_u;
                int r2 = *it_u;
                rows_up.erase(it_u);
                row_walls[r2].erase(C);
                has_wall[r2][C] = false;
            }

            // Down
            auto it_d = rows_up.upper_bound(R);
            if (it_d != rows_up.end()) {
                int r2 = *it_d;
                rows_up.erase(it_d);
                row_walls[r2].erase(C);
                has_wall[r2][C] = false;
            }

        } else {
            // Destroy the wall at (R, C)
            has_wall[R][C] = false;
            row_walls[R].erase(C);
            col_walls[C].erase(R);
        }
    }

    int count = 0;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            count += has_wall[i][j];

    cout << count << endl;

    return 0;
}