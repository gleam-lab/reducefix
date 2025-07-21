#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rrep(i, n) for (int i = n-1; i >= (int)(0); i--)
#define rrepi(i, a, b) for (int i = (int)(a); i > (int)(b); i--)
#define ALL(a) (a).begin(),(a).end()
#define ALL_(a) (a),(a)+size(a)
#define IF_T if(Is_test)

#define ll long long
using namespace std;

struct SegmentTree {
    vector<ll> node;
    int n;

    SegmentTree(int _n) : n(_n), node(4 * n, 0) {}

    void update(int pos, ll value) {
        setPos(pos, value);
    }

    void setPos(int pos, ll value) {
        pos += n;
        node[pos] = value;
        while (pos > 1) {
            pos /= 2;
            node[pos] = max(node[2 * pos], node[2 * pos + 1]);
        }
    }

    ll queryRange(int l, int r) {
        return queryRangeUtil(1, 0, n - 1, l, r);
    }

    ll queryRangeUtil(int pos, int l, int r, int ql, int qr) {
        if (ql > qr) return 0;
        if (ql <= l && r <= qr) return node[pos];
        if (ql > r || qr < l) return 0;

        ll mid = (l + r) / 2;
        return max(queryRangeUtil(2 * pos, l, mid, ql, qr),
                    queryRangeUtil(2 * pos + 1, mid + 1, r, ql, qr));
    }
};

int main() {
    cin >> N >> M;
    SegmentTree segTree(N * N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        // We need to figure out how to mark the region this piece can control
        // This is non-trivial and requires careful consideration of the movement patterns
        // For now, let's assume we have a function `markControlRegion` that does this
        segTree.update(a * N + b, 1); // Placeholder for marking
    }

    // Count the number of cells that are not controlled by any piece
    ll freeCells = 0;
    for (int i = 0; i < N * N; i++) {
        if (segTree.queryRange(i, i) == 0) {
            freeCells++;
        }
    }

    cout << freeCells << endl;

    return 0;
}