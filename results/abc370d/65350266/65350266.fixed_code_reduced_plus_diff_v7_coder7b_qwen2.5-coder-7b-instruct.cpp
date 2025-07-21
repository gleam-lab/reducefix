#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<int> tree;
    SegTree(int _n) : n(_n), tree(4 * _n, INT_MAX) {}

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = min(tree[node], val);
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(node * 2, start, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, end, idx, val);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (l > end || r < start) return INT_MAX;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return min(query(node * 2, start, mid, l, r), query(node * 2 + 1, mid + 1, end, l, r));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> grid(h, vector<int>(w, 1));

    vector<SegTree> seg_h(w), seg_w(h);
    for (int i = 0; i < w; ++i)
        seg_h[i] = SegTree(h);
    for (int i = 0; i < h; ++i)
        seg_w[i] = SegTree(w);

    while (q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;

        if (grid[r][c] == 0) continue;

        grid[r][c] = 0;
        for (int i = 0; i < w; ++i) {
            seg_h[i].update(1, 0, h - 1, r, 1);
        }
        for (int i = 0; i < h; ++i) {
            seg_w[i].update(1, 0, w - 1, c, 1);
        }

        for (int i = 0; i < w; ++i) {
            if (seg_h[i].query(1, 0, h - 1, 0, r - 1) == 0) {
                seg_h[i].update(1, 0, h - 1, r, 0);
            }
        }
        for (int i = 0; i < h; ++i) {
            if (seg_w[i].query(1, 0, w - 1, 0, c - 1) == 0) {
                seg_w[i].update(1, 0, w - 1, c, 0);
            }
        }
    }

    int count = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j]) count++;
        }
    }

    cout << count << endl;

    return 0;
}