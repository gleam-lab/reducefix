#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
    vector<vector<int>> vertices;

    UnionFind(int n) : parent(n + 1), rank(n + 1, 0), size(n + 1, 1) {
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
                vertices[rootY].insert(vertices[rootY].end(), vertices[rootX].begin(), vertices[rootX].end());
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
                vertices[rootX].insert(vertices[rootX].end(), vertices[rootY].begin(), vertices[rootY].end());
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
                size[rootX] += size[rootY];
                vertices[rootX].insert(vertices[rootX].end(), vertices[rootY].begin(), vertices[rootY].end());
            }
        }
    }

    vector<int>& get_vertices(int x) {
        return vertices[find(x)];
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    UnionFind uf(n);

    for (int i = 0; i < q; ++i) {
        int type, v, k;
        cin >> type >> v >> k;

        if (type == 1) {
            int u;
            cin >> u;
            uf.unite(v, u);
        } else if (type == 2) {
            vector<int> component_vertices = uf.get_vertices(v);
            if (k > component_vertices.size()) {
                cout << -1 << '\n';
            } else {
                cout << component_vertices(component_vertices.size() - k) << '\n';
            }
        }
    }

    return 0;
}