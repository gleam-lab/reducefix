#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<int> size;
    UnionFind(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int findRoot(int x) {
        if (parent[x] != x) {
            parent[x] = findRoot(parent[x]);
        }
        return parent[x];
    }
    
    int getSize(int x) {
        x = findRoot(x);
        return size[x];
    }
    
    bool unite(int x, int y) {
        int rootX = findRoot(x);
        int rootY = findRoot(y);
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            return true;
        }
        return false;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            uf.unite(u - 1, v - 1);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            v--;
            int root = uf.findRoot(v);
            int componentsSize = uf.getSize(root);
            if (k > componentsSize) {
                cout << "-1\n";
            } else {
                set<int> connectedVertices;
                for (int i = 0; i < n; i++) {
                    if (uf.findRoot(i) == root) {
                        connectedVertices.insert(i);
                    }
                }
                // The set is sorted in ascending order
                for (int i = 0; i < k - 1; i++) {
                    connectedVertices.erase(connectedVertices.begin());
                }
                cout << *connectedVertices.rbegin() + 1 << "\n";
            }
        }
    }
    
    return 0;
}