#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(int _n) : n(_n), tree(4 * n) {}

    void update(int idx, int val, int node = 1, int tl = 0, int tr = -1) {
        if (tr == -1) tr = n - 1;
        if (tl == tr) {
            tree[node] = val;
            return;
        }
        int tm = (tl + tr) / 2;
        if (idx <= tm)
            update(idx, val, 2 * node, tl, tm);
        else
            update(idx, val, 2 * node + 1, tm + 1, tr);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int l, int r, int node = 1, int tl = 0, int tr = -1) {
        if (tr == -1) tr = n - 1;
        if (l > r) return INT_MAX;
        if (l == tl && r == tr) return tree[node];
        int tm = (tl + tr) / 2;
        return min(query(l, min(r, tm), 2 * node, tl, tm),
                   query(max(l, tm + 1), r, 2 * node + 1, tm + 1, tr));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;
    SegmentTree row_tree(h), col_tree(w);

    while (q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;

        if (row_tree.query(r, r) == 1 || col_tree.query(c, c) == 1) {
            row_tree.update(r, 0);
            col_tree.update(c, 0);
        } else {
            row_tree.update(r, 1);
            col_tree.update(c, 1);
        }
    }

    int ans = 0;
    for (int i = 0; i < h; ++i) ans += row_tree.query(i, i);
    for (int j = 0; j < w; ++j) ans += col_tree.query(j, j);

    cout << ans << '\n';

    return 0;
}