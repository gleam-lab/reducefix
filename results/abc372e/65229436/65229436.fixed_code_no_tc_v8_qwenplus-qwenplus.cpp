#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<set<int>> components;

    UnionFind(int n) : parent(n) {
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
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) return;

        // Merge smaller component into larger one
        if (components[rx].size() < components[ry].size()) {
            swap(rx, ry);
        }

        components[rx].merge(components[ry], less<int>());
        parent[ry] = rx;
    }

    const set<int>& getComponent(int x) {
        return components[find(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            uf.unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            --v;

            const set<int>& comp = uf.getComponent(v);
            if ((int)comp.size() < k) {
                cout << -1 << "\n";
            } else {
                auto it = comp.rbegin();
                advance(it, k - 1);
                cout << (*it + 1) << "\n"; // Convert 0-based to 1-based
            }
        }
    }

    return 0;
}