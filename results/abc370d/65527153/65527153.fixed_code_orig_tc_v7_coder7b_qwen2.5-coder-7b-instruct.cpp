#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    set<int> row, col;
    Node(int v): val(v), row({v}), col({v}) {}
};

class SegTree {
public:
    SegTree(int n): tree(n << 2) {}

    void update(int idx, int l, int r, int pos, int v) {
        if (l == r) {
            tree[idx] = {v};
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(idx << 1, l, mid, pos, v);
        else
            update(idx << 1 | 1, mid + 1, r, pos, v);
        merge(tree[idx], tree[idx << 1], tree[idx << 1 | 1]);
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return tree[idx].val;
        int mid = (l + r) / 2, res = INT_MAX;
        if (ql <= mid)
            res = min(res, query(idx << 1, l, mid, ql, qr));
        if (qr > mid)
            res = min(res, query(idx << 1 | 1, mid + 1, r, ql, qr));
        return res;
    }

private:
    void merge(Node &parent, const Node &left, const Node &right) {
        parent.val = min(left.val, right.val);
        parent.row.insert(left.row.begin(), left.row.end());
        parent.row.insert(right.row.begin(), right.row.end());
        parent.col.insert(left.col.begin(), left.col.end());
        parent.col.insert(right.col.begin(), right.col.end());
    }

    vector<Node> tree;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    SegTree row_tree(h), col_tree(w);

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            row_tree.update(i, 0, h - 1, i, j + 1);
            col_tree.update(j, 0, w - 1, j, i + 1);
        }
    }

    for (int qi = 0; qi < q; ++qi) {
        int r, c;
        cin >> r >> c;

        --r, --c;

        int val = row_tree.query(r, 0, h - 1, r, r);
        if (val == c + 1) {
            row_tree.update(r, 0, h - 1, r, INT_MAX);
            col_tree.update(c, 0, w - 1, c, INT_MAX);
        } else {
            row_tree.update(r, 0, h - 1, r, val - 1);
            col_tree.update(c, 0, w - 1, c, val - 1);
        }
    }

    int cnt = 0;
    for (int i = 0; i < h; ++i) {
        cnt += row_tree.query(i, 0, h - 1, i, i) == INT_MAX ? 0 : 1;
    }

    cout << cnt << '\n';

    return 0;
}