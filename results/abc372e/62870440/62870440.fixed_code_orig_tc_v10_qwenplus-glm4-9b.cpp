#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<int> size;

    UnionFind(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) {
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
            if (size[rootX] < size[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            } else {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
        }
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    UnionFind uf(n);
    vector<vector<int>> connected(n + 1);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            uf.unite(u, v);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;

            int rootV = uf.find(v);
            vector<int> &vertices = connected[rootV];

            // Initialize the connected vertices list
            vertices.clear();
            for (int i = 1; i <= n; ++i) {
                if (uf.find(i) == rootV) {
                    vertices.push_back(i);
                }
            }

            // Sort the list in descending order
            sort(vertices.begin(), vertices.end(), greater<int>());

            if (k <= vertices.size()) {
                cout << vertices[k - 1] << endl;
            } else {
                cout << "-1" << endl;
            }
        }
    }

    return 0;
}