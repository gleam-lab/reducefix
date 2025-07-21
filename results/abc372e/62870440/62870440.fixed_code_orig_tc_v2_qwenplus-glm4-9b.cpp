#include<bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent, size;
    vector<vector<int>> elements; // Storing elements in a set-like structure

    UnionFind(int n) : parent(n + 1), size(n + 1, 1), elements(n + 1) {
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); // Path compression
        }
        return parent[u];
    }

    void unite(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);

        if (root_u != root_v) {
            if (size[root_u] < size[root_v]) {
                swap(root_u, root_v);
            }
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
            elements[root_u].insert(elements[root_u].end(), elements[root_v].begin(), elements[root_v].end());
            sort(elements[root_u].rbegin(), elements[root_u].rend()); // Keep the elements sorted
        }
    }

    vector<int> query(int v, int k) {
        int root_v = find(v);
        if (size[root_v] < k) return {-1};
        return {elements[root_v][k - 1]};
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);

    for (int i = 0; i < q; ++i) {
        int op, u, v, k;
        cin >> op >> u >> v;
        if (op == 1) {
            uf.unite(u, v);
        } else {
            vector<int> result = uf.query(v, k);
            if (result.empty()) {
                cout << -1 << endl;
            } else {
                cout << result[0] << endl;
            }
        }
    }

    return 0;
}