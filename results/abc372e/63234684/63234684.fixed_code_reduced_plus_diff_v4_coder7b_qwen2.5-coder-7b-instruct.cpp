#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i,n) for(int i = 0; i < n; ++i)

struct UnionFind {
    vector<int> par;
    vector<set<int>> conns;

    UnionFind(int n) : par(n, -1), conns(n) {}

    int root(int v) {
        if (par[v] == -1) return v;
        else return par[v] = root(par[v]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    void merge(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return;
        if (conns[y].size() > conns[x].size()) swap(x, y);

        for (int v : conns[y]) {
            conns[x].insert(v);
        }
        conns[y].clear();

        par[y] = x;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    UnionFind uf(n);

    rep(i, q) {
        int ty, a, b;
        cin >> ty >> a >> b;
        a--; b--;

        if (ty == 1) {
            uf.merge(a, b);
        } else {
            auto& s = uf.conns[uf.root(a)];
            if (s.size() < b) {
                cout << -1 << '\n';
            } else {
                cout << *next(s.rbegin(), b - 1) + 1 << '\n';
            }
        }
    }

    return 0;
}