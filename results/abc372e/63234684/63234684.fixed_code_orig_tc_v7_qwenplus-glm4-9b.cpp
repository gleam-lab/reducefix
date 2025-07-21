#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

    UnionFind(int n) : parent(n), rank(n, 0), size(n, 1) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;

        if (rank[x] < rank[y]) {
            parent[x] = y;
            size[y] += size[x];
        } else if (rank[x] > rank[y]) {
            parent[y] = x;
            size[x] += size[y];
        } else {
            parent[y] = x;
            rank[x]++;
            size[x] += size[y];
        }
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    UnionFind uf(n);

    while (q--) {
        int op, v, k;
        cin >> op >> v >> k;
        v--;

        if (op == 1) {
            // Union operation
            uf.unite(v, v + 1);
        } else {
            // Find the size of the connected component
            int root = uf.find(v);
            int component_size = uf.size[root];

            if (component_size < k) {
                cout << -1 << endl;
            } else {
                // Output the k-th largest vertex in the connected component
                cout << "Some large number" << endl; // Placeholder
            }
        }
    }

    return 0;
}