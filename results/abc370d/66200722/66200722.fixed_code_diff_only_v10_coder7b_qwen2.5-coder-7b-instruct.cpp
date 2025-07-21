#include <bits/stdc++.h>

using namespace std;

const int MAXN = 400005;

int h, w, q;
vector<bool> grid[MAXN];

void add_wall(int r, int c) {
    if (!grid[r][c]) {
        grid[r][c] = true;
        q++;
    }
}

void remove_wall(int r, int c) {
    if (grid[r][c]) {
        grid[r][c] = false;
        q--;
    }
}

bool has_up_wall(int r, int c) {
    while (r > 0 && !grid[--r][c]);
    return r > 0;
}

bool has_down_wall(int r, int c) {
    while (r < h - 1 && !grid[++r][c]);
    return r < h - 1;
}

bool has_left_wall(int r, int c) {
    while (c > 0 && !grid[r][--c]);
    return c > 0;
}

bool has_right_wall(int r, int c) {
    while (c < w - 1 && !grid[r][++c]);
    return c < w - 1;
}

int main() {
    cin >> h >> w >> q;
    grid.resize(h, vector<bool>(w, false));

    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (grid[r][c]) {
            remove_wall(r, c);
        } else {
            if (has_up_wall(r, c)) {
                remove_wall(r, c);
            } else if (has_down_wall(r, c)) {
                remove_wall(r, c);
            } else if (has_left_wall(r, c)) {
                remove_wall(r, c);
            } else if (has_right_wall(r, c)) {
                remove_wall(r, c);
            } else {
                add_wall(r, c);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j]) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}