#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(int _n) : n(_n), tree(4 * n) {}

    void update(int p, int l, int r, int pos) {
        if (l == r) {
            tree[p] = !tree[p];
            return;
        }

        int mid = (l + r) / 2;
        if (pos <= mid) {
            update(p * 2, l, mid, pos);
        } else {
            update(p * 2 + 1, mid + 1, r, pos);
        }

        tree[p] = tree[p * 2] | tree[p * 2 + 1];
    }

    bool query(int p, int l, int r, int ql, int qr) {
        if (ql > qr || l > r) return false;
        if (ql <= l && r <= qr) return tree[p];

        int mid = (l + r) / 2;
        return query(p * 2, l, mid, ql, qr) | query(p * 2 + 1, mid + 1, r, ql, qr);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    vector<SegmentTree> seg_h(h, SegmentTree(w)), seg_w(w, SegmentTree(h));

    while (q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;

        if (!seg_h[r].query(1, 0, w - 1, c, c)) {
            seg_h[r].update(1, 0, w - 1, c);
            seg_w[c].update(1, 0, h - 1, r);
        } else {
            bool flag = true;
            for (int i = 0; i < r && flag; ++i) {
                if (!seg_w[c].query(1, 0, h - 1, i, i)) {
                    seg_h[r].update(1, 0, w - 1, c);
                    seg_w[c].update(1, 0, h - 1, r);
                    flag = false;
                }
            }
            for (int i = r + 1; i < h && flag; ++i) {
                if (!seg_w[c].query(1, 0, h - 1, i, i)) {
                    seg_h[r].update(1, 0, w - 1, c);
                    seg_w[c].update(1, 0, h - 1, r);
                    flag = false;
                }
            }
            for (int i = 0; i < c && flag; ++i) {
                if (!seg_h[r].query(1, 0, w - 1, i, i)) {
                    seg_h[r].update(1, 0, w - 1, c);
                    seg_w[c].update(1, 0, h - 1, r);
                    flag = false;
                }
            }
            for (int i = c + 1; i < w && flag; ++i) {
                if (!seg_h[r].query(1, 0, w - 1, i, i)) {
                    seg_h[r].update(1, 0, w - 1, c);
                    seg_w[c].update(1, 0, h - 1, r);
                    flag = false;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < h; ++i) {
        ans += seg_h[i].query(1, 0, w - 1, 0, w - 1);
    }

    cout << ans << '\n';

    return 0;
}