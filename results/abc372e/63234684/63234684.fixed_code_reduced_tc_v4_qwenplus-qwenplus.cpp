#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using P = pair<int, int>;
using T = tuple<int, int, int>;

struct Union_Find {
    vector<int> sz, par;
    vector<set<int>> components;

    Union_Find(int n) {
        sz.resize(n, 1);
        par.resize(n, -1);
        components.resize(n);
        for (int i = 0; i < n; ++i) {
            components[i].insert(i);
        }
    }

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
        // Always merge smaller into larger
        if (components[x].size() < components[y].size()) swap(x, y);
        // Move elements from y to x
        for (int val : components[y]) {
            components[x].insert(val);
        }
        components[y].clear();
        sz[x] += sz[y];
        sz[y] = 0;
        par[y] = x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    Union_Find uf(N);

    while (Q--) {
        int ty, a, b;
        cin >> ty >> a >> b;
        a--, b--;
        if (ty == 1) {
            uf.merge(a, b);
        } else {
            int rt = uf.root(a);
            if ((int)uf.components[rt].size() <= b) {
                cout << -1 << endl;
            } else {
                auto it = uf.components[rt].rbegin(); // reverse iterator
                advance(it, b);
                cout << (*it + 1) << endl;
            }
        }
    }

    return 0;
}