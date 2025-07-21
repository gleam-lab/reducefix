#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent, rank;

    UnionFind(int size) : parent(size), rank(size, 0) {
        for (int i = 0; i < size; ++i) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]); // path compression
        return parent[u];
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

vector<priority_queue<int>> kthLargest;
UnionFind uf;

void addEdge(int u, int v) {
    uf.unite(u, v);
}

int getKthLargest(int v, int k) {
    v = uf.find(v);
    if (kthLargest[v].size() < k) {
        return -1;
    }
    return kthLargest[v][k - 1];
}

int main() {
    int n, q;
    cin >> n >> q;
    uf = UnionFind(n);
    kthLargest.resize(n);

    int op, u, v, k;
    while (q--) {
        cin >> op >> u >> v;
        if (op == 1) {
            addEdge(u, v);
        } else if (op == 2) {
            cin >> k;
            cout << getKthLargest(v, k) << endl;
        }
    }
    return 0;
}