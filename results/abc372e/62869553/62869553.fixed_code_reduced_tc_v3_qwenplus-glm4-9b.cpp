#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<int> rank;
    int n;

    UnionFind(int n) : n(n), parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
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

    for (int i = 0; i < q; i++) {
        int op, u, v;
        cin >> op >> u >> v;

        if (op == 1) {
            uf.unite(u - 1, v - 1);
        } else if (op == 2) {
            int root = uf.find(v - 1);
            vector<int> components;
            for (int i = 0; i < n; i++) {
                if (uf.find(i) == root) {
                    components.push_back(i);
                }
            }

            sort(components.begin(), components.end(), greater<int>());

            int k;
            cin >> k;

            if (k > components.size()) {
                cout << -1 << endl;
            } else {
                cout << components[k - 1] + 1 << endl;
            }
        }
    }

    return 0;
}