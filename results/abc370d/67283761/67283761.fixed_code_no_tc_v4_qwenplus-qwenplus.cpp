#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> has_wall(H, vector<bool>(W, true));

    // For each cell and direction, keep track of the next wall in that direction
    vector<vector<int>> left(H, vector<int>(W, -1));
    vector<vector<int>>(right)(H, vector<int>(W, -1));
    vector<vector<int>>(up)(H, vector<int>(W, -1));
    vector<vector<int>>(down)(H, vector<int>(W, -1));

    // Initialize directional pointers
    for (int i = 0; i < H; ++i) {
        int last = -1;
        for (int j = 0; j < W; ++j) {
            left[i][j] = last;
            if (has_wall[i][j]) last = j;
        }
        last = -1;
        for (int j = W - 1; j >= 0; --j) {
            right[i][j] = last;
            if (has_wall[i][j]) last = j;
        }
    }

    for (int j = 0; j < W; ++j) {
        int last = -1;
        for (int i = 0; i < H; ++i) {
            up[i][j] = last;
            if (has_wall[i][j]) last = i;
        }
        last = -1;
        for (int i = H - 1; i >= 0; --i) {
            down[i][j] = last;
            if (has_wall[i][j]) last = i;
        }
    }

    auto break_wall = [&](int r, int c) {
        if (!has_wall[r][c]) return;
        has_wall[r][c] = false;

        // Update neighbors' pointers
        // Left/Right
        int l = left[r][c];
        int ri = right[r][c];
        if (l != -1) right[r][l] = ri;
        if (ri != -1) left[r][ri] = l;

        // Up/Down
        int u = up[r][c];
        int d = down[r][c];
        if (u != -1) down[u][c] = d;
        if (d != -1) up[d][c] = u;
    };

    auto detonate = [&](int r, int c) {
        vector<pair<int, int>> to_break;

        // Left
        int j = c;
        while (j != -1 && !has_wall[r][j]) j = left[r][j];
        if (j != -1) to_break.emplace_back(r, j);

        // Right
        j = c;
        while (j != -1 && !has_wall[r][j]) j = right[r][j];
        if (j != -1) to_break.emplace_back(r, j);

        // Up
        int i = r;
        while (i != -1 && !has_wall[i][c]) i = up[i][c];
        if (i != -1) to_break.emplace_back(i, c);

        // Down
        i = r;
        while (i != -1 && !has_wall[i][c]) i = down[i][c];
        if (i != -1) to_break.emplace_back(i, c);

        for (auto [x, y] : to_break) break_wall(x, y);
    };

    for (int _ = 0; _ < Q; ++_) {
        int R, C;
        cin >> R >> C;
        int r = R - 1, c = C - 1;

        if (has_wall[r][c]) {
            break_wall(r, c);
        } else {
            detonate(r, c);
        }
    }

    int remaining = 0;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            remaining += has_wall[i][j];

    cout << remaining << endl;

    return 0;
}