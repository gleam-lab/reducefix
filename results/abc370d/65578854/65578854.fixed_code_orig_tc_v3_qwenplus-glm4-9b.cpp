#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) x.begin(), x.end()

struct Wall {
    int row;
    int col;
};

struct Query {
    int r;
    int c;
    bool isQuery;
};

struct RangeQuery {
    int start;
    int end;
};

struct SegmentTree {
    vector<vector<RangeQuery>> tree;
    int n;
    int m;

    SegmentTree(int n, int m) : n(n), m(m), tree(4 * n, vector<RangeQuery>(4 * m)) {}

    void update(int x, int y, vector<Wall>& walls) {
        update(x, y, 1, 1, n, m, walls);
    }

    void update(int x, int y, int k, int l, int r, int s, int e, vector<Wall>& walls) {
        if (r <= l || s <= e) return;
        if (s == l && e == r) {
            if (walls[x - l].col > y) {
                tree[k] = {{s, x}, {x + 1, r}};
            } else if (walls[x - l].col < y) {
                tree[k] = {{x, r}, {s, x}};
            } else {
                tree[k] = {{s, x}, {x + 1, r}};
                tree[k].push_back({x, r});
            }
        } else {
            int mid = (l + r) / 2;
            int midS = (s + e) / 2;
            update(x, y, k * 2, l, mid, s, midS, walls);
            update(x, y, k * 2 + 1, mid + 1, r, midS + 1, e, walls);
            merge(k, k * 2, k * 2 + 1);
        }
    }

    void merge(int k, int a, int b) {
        sort(tree[k].begin(), tree[k].end(), [&](const RangeQuery& a, const RangeQuery& b) {
            return a.start < b.start;
        });
        tree[k].erase(unique(tree[k].begin(), tree[k].end()), tree[k].end());
    }

    void query(int l, int r, int s, int e, vector<Wall>& walls) {
        if (r <= l || s >= r || e <= s) return;
        if (s >= l && e <= r) {
            for (const auto& q : tree[k]) {
                if (q.start >= s && q.end <= e) {
                    if (q.start == s && q.end == e) {
                        walls[q.start - s].col = min(walls[q.start - s].col, q.col);
                    } else {
                        update(q.start, q.end, k * 2, l, r, s, e, walls);
                    }
                }
            }
        } else {
            int mid = (l + r) / 2;
            int midS = (s + e) / 2;
            query(l, r, s, mid, walls);
            query(l, r, mid + 1, e, walls);
        }
    }
};

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<Wall> walls(H);
    rep(i, H) rep(j, W) {
        walls[i].row = i + 1;
        walls[i].col = j + 1;
    }
    SegmentTree seg(H, W);
    rep(i, H) {
        seg.update(i + 1, W, walls);
    }
    while (Q--) {
        int R, C;
        cin >> R >> C;
        R--; C--;
        seg.query(1, H, C + 1, W + 1, walls);
        seg.update(R + 1, C + 1, walls);
    }
    ll ans = H * W;
    rep(i, H) {
        ans -= walls[i].col >= C + 1;
    }
    cout << ans << endl;
    return 0;
}