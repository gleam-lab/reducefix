#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
#define x first
#define y second

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> has_wall(H + 2, vector<bool>(W + 2, true));
    vector<vector<int>> row_left(H + 2, vector<int>(W + 2));
    vector<vector<int>> row_right(H + 2, vector<int>(W + 2));
    vector<vector<int>> col_up(W + 2, vector<int>(H + 2));
    vector<vector<int>> col_down(W + 2, vector<int>(H + 2));

    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row_left[i][j] = j - 1;
            row_right[i][j] = j + 1;
        }
    }

    for (int j = 1; j <= W; ++j) {
        for (int i = 1; i <= H; ++i) {
            col_up[j][i] = i - 1;
            col_down[j][i] = i + 1;
        }
    }

    auto remove_wall = [&](int r, int c) {
        if (!has_wall[r][c]) return;
        has_wall[r][c] = false;

        // Update left and right pointers in the row
        int l = row_left[r][c];
        int rgt = row_right[r][c];

        if (l >= 1) row_right[r][l] = rgt;
        if (rgt <= W) row_left[r][rgt] = l;

        // Update up and down pointers in the column
        int u = col_up[c][r];
        int d = col_down[c][r];

        if (u >= 1) col_down[c][u] = d;
        if (d <= H) col_up[c][d] = u;
    };

    auto query = [&](int r, int c) {
        if (has_wall[r][c]) {
            remove_wall(r, c);
            return;
        }

        for (int dir = 0; dir < 4; ++dir) {
            int nr = r + dx[dir];
            int nc = c + dy[dir];

            while (1 <= nr && nr <= H && 1 <= nc && nc <= W) {
                if (has_wall[nr][nc]) {
                    remove_wall(nr, nc);
                    break;
                } else {
                    if (dir == 0) nr = col_up[nc][nr]; // move up
                    else if (dir == 1) nr = col_down[nc][nr]; // move down
                    else if (dir == 2) nc = row_left[nr][nc]; // move left
                    else if (dir == 3) nc = row_right[nr][nc]; // move right
                }
            }
        }
    };

    for (int _ = 0; _ < Q; ++_) {
        int r, c;
        cin >> r >> c;
        query(r, c);
    }

    long long ans = 0;
    for (int i = 1; i <= H; ++i)
        for (int j = 1; j <= W; ++j)
            ans += has_wall[i][j];

    cout << ans << endl;
}