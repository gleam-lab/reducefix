#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair<int, int>;

struct UnionFind {
    vector<int> parent;
    vector<vector<P>> adj; // Adjacency list to store vertex value and its index

    UnionFind(int n) : parent(n, -1) {}

    int root(int v) {
        if (parent[v] == -1) return v;
        return parent[v] = root(parent[v]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    void merge(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return;

        // Union by size
        if (adj[y].size() < adj[x].size()) swap(x, y);
        parent[x] = y;

        // Append all nodes from y to x
        for (auto &p : adj[y]) adj[x].emplace_back(p.first, adj[x].size());
        sort(adj[x].rbegin(), adj[x].rend()); // Keep the list sorted

        adj[y].clear(); // Clear the y's adjacency list
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);

    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        u--, v--;

        if (t == 1) {
            uf.merge(u, v);
        } else {
            if (uf.issame(u, v)) { // Only consider queries within the same connected component
                if (uf.adj[uf.root(v)].size() < v) {
                    cout << -1 << endl;
                } else {
                    cout << uf.adj[uf.root(v)][v].first + 1 << endl; // Output the 1-based index
                }
            }
        }
    }

    return 0;
}