#include <iostream>
#include <vector>
using namespace std;

class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    int total = H * W;
    vector<vector<bool>> alive(H, vector<bool>(W, true));

    // 4 DSUs: row-left, row-right, col-up, col-down
    vector<DSU> dsu_row_left(H, DSU(W));
    vector<DSU> dsu_row_right(H, DSU(W));
    vector<DSU> dsu_col_up(W, DSU(H));
    vector<DSU> dsu_col_down(W, DSU(H));

    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j) {
            dsu_row_left[i].unite(j, j - 1);      // initially point to self
            dsu_row_right[i].unite(j, j + 1);
            dsu_col_up[j].unite(i, i - 1);
            dsu_col_down[j].unite(i, i + 1);
        }

    auto get_left = [&](int r, int c) {
        return dsu_row_left[r].find(c);
    };
    auto get_right = [&](int r, int c) {
        return dsu_row_right[r].find(c);
    };
    auto get_up = [&](int r, int c) {
        return dsu_col_up[c].find(r);
    };
    auto get_down = [&](int r, int c) {
        return dsu_col_down[c].find(r);
    };

    while (Q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (!alive[r][c]) {
            // Look in 4 directions

            // Left
            int l = get_left(r, c);
            if (l >= 0 && alive[r][l]) {
                alive[r][l] = false;
                dsu_row_left[r].unite(l, l - 1);
                dsu_row_right[r].unite(l, l);
                total--;
            }

            // Right
            int re = get_right(r, c);
            if (re < W && alive[r][re]) {
                alive[r][re] = false;
                dsu_row_right[r].unite(re, re + 1);
                dsu_row_left[r].unite(re, re);
                total--;
            }

            // Up
            int u = get_up(r, c);
            if (u >= 0 && alive[u][c]) {
                alive[u][c] = false;
                dsu_col_up[c].unite(u, u - 1);
                dsu_col_down[c].unite(u, u);
                total--;
            }

            // Down
            int d = get_down(r, c);
            if (d < H && alive[d][c]) {
                alive[d][c] = false;
                dsu_col_down[c].unite(d, d + 1);
                dsu_col_up[c].unite(d, d);
                total--;
            }

        } else {
            // Bomb here destroys current cell
            alive[r][c] = false;
            // Update DSUs
            dsu_row_left[r].unite(c, c - 1);
            dsu_row_right[r].unite(c, c + 1);
            dsu_col_up[c].unite(r, r - 1);
            dsu_col_down[c].unite(r, r + 1);
            total--;
        }
    }

    cout << total << endl;
}