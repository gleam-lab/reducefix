#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using P = pair<int, int>;
using T = tuple<int, int, int>;

struct Union_Find {
    vector<int> sz, par;
    vector<multiset<int, greater<>>> components;

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

        // Move all elements from y to x
        for (int val : components[y]) {
            components[x].insert(val);
        }
        // Clear y's set
        components[y].clear();

        sz[x] += sz[y];
        sz[y] = 0;
        par[y] = x;
    }

    multiset<int, greater<>>* get_component(int v) {
        int r = root(v);
        return &components[r];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    Union_Find uf(n);

    for (int i = 0; i < q; ++i) {
        int ty;
        cin >> ty;
        if (ty == 1) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            uf.merge(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            v--;

            auto comp = uf.get_component(v);
            if (k > comp->size()) {
                cout << -1 << endl;
            } else {
                auto it = comp->begin();
                advance(it, k - 1);
                cout << (*it) + 1 << endl;
            }
        }
    }

    return 0;
}