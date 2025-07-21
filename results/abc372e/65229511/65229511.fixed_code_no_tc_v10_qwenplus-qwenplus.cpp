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

    int findRoot(int x) {
        if (parent[x] != x)
            parent[x] = findRoot(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rx = findRoot(x), ry = findRoot(y);
        if (rx == ry) return;

        // Always merge smaller set into larger one
        if (components[rx].size() < components[ry].size())
            swap(rx, ry);

        // Merge ry's component into rx's component
        for (int node : components[ry]) {
            components[rx].insert(node);
            parent[node] = rx;
        }
        components[ry].clear();
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
        int com;
        cin >> com;
        if (com == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            uf.unite(u, v);
        } else if (com == 2) {
            int v, k;
            cin >> v >> k;
            v--;
            int root = uf.findRoot(v);
            const set<int>& comp = uf.components[root];
            
            if ((int)comp.size() < k) {
                ans.push_back(-1);
            } else {
                auto it = comp.rbegin();
                advance(it, k - 1);
                ans.push_back(*it + 1); // Convert 0-based to 1-based
            }
        }
    }

    for (auto x : ans) cout << x << endl;
    return 0;
}