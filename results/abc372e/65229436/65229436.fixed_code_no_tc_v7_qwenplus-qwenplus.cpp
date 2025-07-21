#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<multiset<int, greater<int>>> components;

    UnionFind(int n) : parent(n), components(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            components[i].insert(i);
        }
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;

        // Always merge smaller set into larger one
        if (components[rx].size() < components[ry].size())
            swap(rx, ry);

        // Move all elements from ry to rx
        for (int val : components[ry])
            components[rx].insert(val);

        // Clear the set that was merged
        components[ry].clear();
        parent[ry] = rx;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;

    UnionFind uf(n);

    vector<int> ans;

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            uf.unite(u, v);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            v--;

            int root = uf.find(v);
            auto& comp = uf.components[root];

            if (comp.size() < (size_t)k) {
                ans.push_back(-1);
            } else {
                auto it = comp.begin();
                advance(it, k - 1);
                ans.push_back(*it + 1);
            }
        }
    }

    for (int x : ans)
        cout << x << "\n";

    return 0;
}