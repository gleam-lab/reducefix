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
        // Move all elements from y to x
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

    int n, q;
    cin >> n >> q;
    Union_Find uf(n);

    while (q--) {
        int ty, a, b;
        cin >> ty >> a >> b;
        a--;
        if (ty == 1) {
            b--;
            uf.merge(a, b);
        } else {
            // Type 2 query: get k-th largest
            int v = a;
            int k = b;
            int rt = uf.root(v);
            const auto& comp = uf.components[rt];
            if ((int)comp.size() < k) {
                cout << -1 << '\n';
            } else {
                // Traverse set in reverse to find k-th largest
                auto it = comp.rbegin();
                for (int i = 0; i < k - 1; ++it, ++i);
                cout << (*it + 1) << '\n';
            }
        }
    }

    return 0;
}