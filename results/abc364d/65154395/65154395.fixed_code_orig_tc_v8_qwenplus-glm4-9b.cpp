#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;

struct SegmentTree {
    vector<int> tree;
    vector<int> lazy;
    vector<int> index;

    SegmentTree(int n) {
        tree.resize(4 * n, INF);
        lazy.resize(4 * n);
        index.resize(4 * n);
    }

    void updateRange(int node, int l, int r, int tl, int tr, int val, int ind) {
        if (r < tl || tr < l) return;
        if (tl <= l && r <= tr) {
            tree[node] = val;
            index[node] = ind;
            return;
        }
        int tm = (l + r) / 2;
        if (!lazy[node]) {
            lazy[node] = tree[node];
            index[node] = index[node / 2];
        }
        updateRange(node * 2, l, tm, tl, tr, val, ind);
        updateRange(node * 2 + 1, tm + 1, r, tl, tr, val, ind);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
        index[node] = min(index[node * 2], index[node * 2 + 1]);
    }

    int queryRange(int node, int l, int r, int tl, int tr) {
        if (r < tl || tr < l) return INF;
        if (tl <= l && r <= tr) {
            return tree[node];
        }
        int tm = (l + r) / 2;
        if (!lazy[node]) {
            lazy[node] = tree[node];
        }
        int left = queryRange(node * 2, l, tm, tl, tr);
        int right = queryRange(node * 2 + 1, tm + 1, r, tl, tr);
        tree[node] = min(left, right);
        index[node] = min(index[node * 2], index[node * 2 + 1]);
        lazy[node] = INF;
        return tree[node];
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    SegmentTree seg(4 * n);
    for (int i = 0; i < n; i++) {
        seg.updateRange(1, 0, 3 * n - 1, 0, 3 * n - 1, a[i], i);
    }
    while (q--) {
        int b, k;
        cin >> b >> k;
        int result = seg.queryRange(1, 0, 3 * n - 1, 0, 3 * n - 1);
        cout << abs(result - b) << endl;
    }
    return 0;
}