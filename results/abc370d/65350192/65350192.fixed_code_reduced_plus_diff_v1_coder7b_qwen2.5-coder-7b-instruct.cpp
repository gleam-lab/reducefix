#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

struct SegmentTree {
    int n;
    vector<bool> tree;
    SegmentTree(int size) : n(size), tree(4 * size, true) {}

    void update(int pos, int l, int r, int idx) {
        if (l == r) {
            tree[idx] = false;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            update(pos, l, mid, 2 * idx + 1);
        } else {
            update(pos, mid + 1, r, 2 * idx + 2);
        }
        tree[idx] = tree[2 * idx + 1] && tree[2 * idx + 2];
    }

    bool query(int ql, int qr, int l, int r, int idx) {
        if (ql > r || qr < l) return true;
        if (ql <= l && qr >= r) return tree[idx];
        int mid = (l + r) / 2;
        return query(ql, qr, l, mid, 2 * idx + 1) && query(ql, qr, mid + 1, r, 2 * idx + 2);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;
    vector<SegmentTree> cols(w), rows(h);

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--, c--;

        if (!cols[c].query(r, r, 0, h - 1, 0)) {
            cols[c].update(r, 0, h - 1, 0);
            rows[r].update(c, 0, w - 1, 0);
        } else {
            int lr = cols[c].query(0, r - 1, 0, h - 1, 0) ? -1 : cols[c].query(r + 1, h - 1, 0, h - 1, 0);
            int lc = rows[r].query(0, c - 1, 0, w - 1, 0) ? -1 : rows[r].query(c + 1, w - 1, 0, w - 1, 0);

            if (lr != -1) {
                cols[c].update(lr, 0, h - 1, 0);
            }
            if (lc != -1) {
                rows[r].update(lc, 0, w - 1, 0);
            }
        }
    }

    int ans = 0;
    rep(i, w) {
        if (cols[i].query(0, h - 1, 0, h - 1, 0)) {
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}