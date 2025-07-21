#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int size) : parent(size), rank(size, 0) {
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int findRoot(int x) {
        if (parent[x] != x) {
            parent[x] = findRoot(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = findRoot(x);
        int rootY = findRoot(y);

        if (rootX == rootY) {
            return false;
        }

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }

    int getSize(int x) {
        int root = findRoot(x);
        int size = 1;
        for (int i = 0; i < parent.size(); ++i) {
            if (findRoot(i) == root) {
                size++;
            }
        }
        return size;
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
            uf.unite(u, v);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            int root = uf.findRoot(v);
            int size = uf.getSize(root);
            if (k > size) {
                cout << -1 << endl;
            } else {
                vector<int> components;
                for (int i = 0; i < n; ++i) {
                    if (uf.findRoot(i) == root) {
                        components.push_back(i);
                    }
                }
                sort(components.rbegin(), components.rend());
                cout << components[k - 1] + 1 << endl;
            }
        }
    }

    return 0;
}