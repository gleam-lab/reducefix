#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
using Set = multiset<int, greater<int>>;

struct UnionFind {
    vector<int> parent, rank;
    vector<Set> components;
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            components[i] = {i}; // Each node starts as its own component
        }
    }
    int findRoot(int x) {
        if (parent[x] != x) {
            parent[x] = findRoot(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y) {
        int rootX = findRoot(x);
        int rootY = findRoot(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                components[rootX].insert(components[rootY].begin(), components[rootY].end());
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                components[rootY].insert(components[rootX].begin(), components[rootX].end());
            } else {
                parent[rootY] = rootX;
                components[rootX].insert(components[rootY].begin(), components[rootY].end());
                rank[rootX]++;
            }
        }
    }
    Set& componentOf(int x) {
        return components[findRoot(x)];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    while (q--) {
        int com, v, k;
        cin >> com >> v >> k;
        --v; // Convert to zero-indexed
        if (com == 1) {
            int u;
            cin >> u;
            --u; // Convert to zero-indexed
            uf.unite(u, v);
        } else {
            Set& component = uf.componentOf(v);
            if (k > component.size()) {
                cout << -1 << endl;
            } else {
                cout << *(next(component.begin(), k - 1)) + 1 << endl;
            }
        }
    }
    return 0;
}