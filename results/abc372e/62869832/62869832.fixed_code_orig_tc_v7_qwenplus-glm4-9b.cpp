#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define MAXV 20

int fa[MAXN], rank[MAXN], size[MAXN];

int root(int x) {
    if (x == fa[x]) return x;
    int r = root(fa[x]);
    rank[x] = min(rank[x], rank[fa[x]]);
    fa[x] = r;
    return r;
}

void unite(int x, int y) {
    int rx = root(x), ry = root(y);
    if (rx != ry) {
        if (rank[rx] > rank[ry]) {
            swap(rx, ry);
        }
        fa[rx] = ry;
        size[ry] += size[rx];
    }
}

int find_size(int x) {
    return size[root(x)];
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        rank[i] = 0;
        size[i] = 1;
    }
    while (q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            unite(u, v);
        } else if (op == 2) {
            if (find_size(v) < 10) {
                cout << -1 << '\n';
            } else {
                cout << v << '\n';
            }
        }
    }
    return 0;
}