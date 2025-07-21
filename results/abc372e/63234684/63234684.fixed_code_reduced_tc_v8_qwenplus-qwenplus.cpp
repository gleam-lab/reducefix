#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent, size;
    vector<vector<int>> top_nodes;

    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        top_nodes.resize(n);
        for (int i = 0; i < n; ++i) {
            top_nodes[i].push_back(i);
        }
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr == yr) return;

        // Always merge smaller into larger
        if (size[xr] < size[yr]) swap(xr, yr);

        // Merge yr into xr
        parent[yr] = xr;
        size[xr] += size[yr];

        // Merge top nodes and keep top 10
        vector<int> merged;
        merged.insert(merged.end(), top_nodes[xr].begin(), top_nodes[xr].end());
        merged.insert(merged.end(), top_nodes[yr].begin(), top_nodes[yr].end());
        sort(merged.rbegin(), merged.rend());
        if (merged.size() > 10)
            merged.resize(10);
        top_nodes[xr] = merged;
    }

    int query_kth(int v, int k) {
        int root = find(v);
        if ((int)top_nodes[root].size() < k) return -1;
        return top_nodes[root][k - 1] + 1; // Convert 0-based index to 1-based node number
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
            uf.unite(u - 1, v - 1);
        } else {
            int v, k;
            cin >> v >> k;
            cout << uf.query_kth(v - 1, k) << '\n';
        }
    }

    return 0;
}