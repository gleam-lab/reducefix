#include <iostream>
#include <vector>
#include <set>
#include <functional>

using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<int> size;
    vector<set<int>> components;

    UnionFind(int n) : parent(n), size(n, 1), components(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            components[i] = {i};
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
                components[rootY].insert(components[rootX].begin(), components[rootX].end());
                components[rootX].clear();
            } else {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
                components[rootX].insert(components[rootY].begin(), components[rootY].end());
                components[rootY].clear();
            }
        }
    }

    set<int> getComponent(int x) {
        return components[find(x)];
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    UnionFind uf(n);

    while (q--) {
        int type, u, v, k;
        cin >> type >> u >> v;
        if (type == 1) {
            uf.unite(u, v);
        } else if (type == 2) {
            set<int> component = uf.getComponent(v);
            if (component.size() < k) {
                cout << -1 << endl;
            } else {
                cout << *next(component.lower_bound(u - 1)) << endl;
            }
        }
    }

    return 0;
}