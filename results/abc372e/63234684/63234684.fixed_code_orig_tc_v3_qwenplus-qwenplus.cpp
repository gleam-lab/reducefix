#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    int n;
    vector<int> parent;
    vector<vector<int>> top_nodes; // Each set keeps top 10 largest nodes

    UnionFind(int _n) : n(_n), parent(_n, -1) {
        top_nodes.resize(n);
        for (int i = 0; i < n; ++i)
            top_nodes[i] = {i};
    }

    int find(int x) {
        if (parent[x] == -1) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v) {
        int x = find(u), y = find(v);
        if (x == y) return;

        // Always merge smaller into larger
        if (top_nodes[x].size() < top_nodes[y].size())
            swap(x, y);

        // Merge y's top nodes into x's
        for (int val : top_nodes[y])
            top_nodes[x].push_back(val);

        // Sort in descending order and keep top 10
        sort(top_nodes[x].rbegin(), top_nodes[x].rend());
        if (top_nodes[x].size() > 10)
            top_nodes[x].resize(10);

        parent[y] = x;
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
            uf.unite(u - 1, v - 1);
        } else {
            int v, k;
            cin >> v >> k;
            auto& group = uf.top_nodes[uf.find(v - 1)];
            if ((int)group.size() < k)
                cout << "-1\n";
            else
                cout << group[k - 1] + 1 << "\n"; // Convert back to 1-based
        }
    }

    return 0;
}