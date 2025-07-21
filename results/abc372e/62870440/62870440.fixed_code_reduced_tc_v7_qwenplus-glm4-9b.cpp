#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<int> rank;

    UnionFind(int size) : parent(size), rank(size, 0) {
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
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
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);

    for (int i = 0; i < q; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int u, v;
            cin >> u >> v;
            uf.unionSets(u, v - 1);
        } else if (op == 2) {
            int v, k;
            cin >> v >> k;
            int root = uf.find(v - 1);
            int connected_count = 0;
            for (int i = 0; i < n; ++i) {
                if (uf.find(i) == root) {
                    connected_count++;
                    if (connected_count == k) {
                        cout << i + 1 << endl;
                        break;
                    }
                }
            }
            if (connected_count < k) {
                cout << "-1" << endl;
            }
        }
    }

    return 0;
}