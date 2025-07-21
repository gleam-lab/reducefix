#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using P = pair<int, int>;
using T = tuple<int, int, int>;

struct UnionFind {
    vector<int> parent, size;
    vector<vector<int>> components;

    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        components.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = -1;
            components[i].push_back(i);
        }
    }

    int root(int x) {
        if (parent[x] == -1) return x;
        return parent[x] = root(parent[x]);
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    void unite(int u, int v) {
        int x = root(u), y = root(v);
        if (x == y) return;

        // Merge smaller component into larger one
        if (size[x] < size[y]) swap(x, y);
        
        // Update the parent and size
        parent[y] = x;
        size[x] += size[y];

        // Move elements from y's component to x's component
        components[x].insert(components[x].end(), components[y].begin(), components[y].end());
        // Sort in descending order and keep top 10 elements only
        sort(components[x].rbegin(), components[x].rend());
        if (components[x].size() > 10) {
            components[x].resize(10);
        }

        // Clear y's component (not strictly necessary but helps with memory debugging)
        components[y].clear();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            uf.unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            --v;

            auto& comp = uf.components[uf.root(v)];
            if (k <= comp.size()) {
                cout << comp[k - 1] + 1 << "\n";
            } else {
                cout << "-1\n";
            }
        }
    }

    return 0;
}