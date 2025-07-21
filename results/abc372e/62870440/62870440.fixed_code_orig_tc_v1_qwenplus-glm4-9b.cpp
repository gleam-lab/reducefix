#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<int> rank;

    UnionFind(int size) : parent(size + 1), rank(size + 1, 0) {
        for (int i = 0; i <= size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    vector<vector<int>> adj(N + 1);
    vector<vector<int>> sorted_adj(N + 1);

    for (int i = 0; i < Q; ++i) {
        int op, u, v, k;
        cin >> op >> u >> v;

        if (op == 1) {
            uf.unionSets(u, v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else {
            int root_v = uf.find(v);
            sorted_adj[root_v] = adj[v];
            sort(sorted_adj[root_v].rbegin(), sorted_adj[root_v].rend());
            if (k > sorted_adj[root_v].size()) {
                cout << "-1\n";
            } else {
                cout << sorted_adj[root_v][k - 1] << "\n";
            }
        }
    }

    return 0;
}