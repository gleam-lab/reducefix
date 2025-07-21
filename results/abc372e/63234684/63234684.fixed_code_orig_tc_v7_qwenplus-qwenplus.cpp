#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

struct DSU {
    vi parent, size;
    vector<vi> top_nodes;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
        top_nodes.resize(n);
        for (int i = 0; i < n; ++i) {
            top_nodes[i].push_back(i);
        }
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr == yr) return;

        // Merge smaller set into larger set
        if (size[xr] < size[yr]) swap(xr, yr);
        parent[yr] = xr;
        size[xr] += size[yr];

        // Merge top nodes
        auto& large = top_nodes[xr];
        auto& small = top_nodes[yr];

        large.insert(large.end(), small.begin(), small.end());
        sort(large.rbegin(), large.rend());

        // Keep only top 10
        if (large.size() > 10) {
            large.resize(10);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    DSU dsu(N);

    while (Q--) {
        int type, u, v;
        cin >> type >> u >> v;
        u--; v--;

        if (type == 1) {
            dsu.unite(u, v);
        } else {
            int root = dsu.find(u);
            const auto& nodes = dsu.top_nodes[root];
            if (v >= (int)nodes.size()) {
                cout << -1 << '\n';
            } else {
                cout << nodes[v] + 1 << '\n'; // Convert from 0-indexed to 1-indexed
            }
        }
    }

    return 0;
}