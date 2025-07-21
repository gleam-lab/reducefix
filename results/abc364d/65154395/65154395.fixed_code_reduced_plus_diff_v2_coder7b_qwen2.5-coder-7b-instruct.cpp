#include <bits/stdc++.h>

using namespace std;

vector<int> A, B;

struct Node {
    int l, r, m, cnt;
    vector<int> sum;
};

Node seg[1 << 18];

void build(int p, int tl, int tr) {
    seg[p].l = tl;
    seg[p].r = tr;
    seg[p].m = (tl + tr) / 2;
    seg[p].cnt = 0;
    if (tl == tr) {
        seg[p].sum.resize(1, 1);
        return;
    }
    build(ls(p), tl, seg[p].m);
    build(rs(p), seg[p].m + 1, tr);
    seg[p].sum.resize(seg[ls(p)].sum.size() + seg[rs(p)].sum.size());
    merge(seg[ls(p)].sum.begin(), seg[ls(p)].sum.end(), seg[rs(p)].sum.begin(), seg[rs(p)].sum.end(), seg[p].sum.begin());
}

void update(int p, int pos) {
    if (seg[p].l == seg[p].r) {
        ++seg[p].sum[pos];
        return;
    }
    int mid = seg[p].m;
    if (pos <= mid) update(ls(p), pos);
    else update(rs(p), pos - mid - 1);
    seg[p].sum.resize(seg[ls(p)].sum.size() + seg[rs(p)].sum.size());
    merge(seg[ls(p)].sum.begin(), seg[ls(p)].sum.end(), seg[rs(p)].sum.begin(), seg[rs(p)].sum.end(), seg[p].sum.begin());
}

int query(int p, int ql, int qr) {
    if (ql > qr) return 0;
    if (ql == seg[p].l && qr == seg[p].r) return seg[p].sum.back();
    int mid = seg[p].m;
    return query(ls(p), ql, min(qr, mid)) + query(rs(p), max(ql, mid + 1), qr);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q; cin >> n >> q;
    A.resize(n);
    B.resize(q);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < q; ++i) cin >> B[i];

    sort(A.begin(), A.end());

    build(1, 0, n - 1);

    for (int i = 0; i < q; ++i) {
        int b = B[i], k; cin >> k;
        --k;
        int idx = upper_bound(A.begin(), A.end(), b) - A.begin();
        int cnt = query(1, 0, idx - 1);
        int ans = b - A[idx - cnt - 1];
        cout << ans << '\n';
        update(1, idx - cnt - 1);
    }

    return 0;
}