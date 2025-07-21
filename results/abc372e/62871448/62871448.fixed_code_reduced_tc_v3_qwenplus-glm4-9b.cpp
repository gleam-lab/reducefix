#include<bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<int> rank;
    vector<vector<int>> as; // Store the k largest vertices for each component

    int n;
    UnionFind(int n) : n(n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        as.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            as[i].push_back(i); // Initially, each vertex is its own largest vertex
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu != pv) {
            // Merge the components
            if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
                // Update the as array
                for (int i = 0; i < size(pu); ++i) {
                    auto& largest = as[pu][i];
                    if (largest > pv) {
                        as[pv].insert(as[pv].begin(), largest);
                    }
                }
                as[pu].clear();
                rank[pv] += rank[pu];
            } else {
                parent[pv] = pu;
                // Update the as array
                for (int i = 0; i < size(pv); ++i) {
                    auto& largest = as[pv][i];
                    if (largest > pu) {
                        as[pu].insert(as[pu].begin(), largest);
                    }
                }
                as[pv].clear();
                rank[pu] += rank[pv];
            }
        }
    }

    size_t size(int x) {
        return rank[find(x)];
    }

    int kth_largest(int v, int k) {
        int root = find(v);
        size_t sz = size(root);
        if (k > sz) {
            return -1; // Not enough vertices in the connected component
        }
        // Return the k-th largest vertex
        return as[root][sz - k];
    }
};

UnionFind uf;

int main() {
    int n, q;
    cin >> n >> q;
    while (q--) {
        int op, u, v, k;
        cin >> op >> u >> v;
        if (op == 1) {
            uf.merge(u, v);
        } else {
            cin >> k;
            int ans = uf.kth_largest(v, k);
            cout << ans << endl;
        }
    }
    return 0;
}