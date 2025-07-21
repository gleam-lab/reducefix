#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using P = pair<int, int>;
using T = tuple<int, int, int>;

struct Union_Find {
    vector<int> par, sz;
    vector<vector<int>> components;

    Union_Find(int n) {
        par.resize(n, -1);
        sz.resize(n, 1);
        components.resize(n);
        for (int i = 0; i < n; ++i) {
            components[i].push_back(i);
        }
    }

    int root(int x) {
        if (par[x] == -1) return x;
        return par[x] = root(par[x]);
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;

        // Always merge smaller into larger
        if (sz[x] < sz[y]) swap(x, y);
        
        // Merge components
        for (int node : components[y]) {
            components[x].push_back(node);
        }
        
        // Keep only the largest 10 elements
        if (components[x].size() > 10) {
            nth_element(components[x].begin(), components[x].begin() + 9, components[x].end(), greater<int>());
            components[x].resize(10);
        }

        // Update DSU structure
        sz[x] += sz[y];
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
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            uf.unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            --v;
            auto comp = uf.components[uf.root(v)];
            if (k <= comp.size()) {
                cout << comp[k - 1] + 1 << "\n"; // Convert to 1-based index
            } else {
                cout << -1 << "\n";
            }
        }
    }

    return 0;
}