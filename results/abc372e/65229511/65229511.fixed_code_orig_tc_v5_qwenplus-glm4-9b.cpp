#include <iostream>
#include <vector>
#include <set>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> size;

public:
    UnionFind(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) {
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
        if (size[rootX] < size[rootY]) {
            swap(rootX, rootY);
        }
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
        return true;
    }

    int getSize(int x) {
        return size[findRoot(x)];
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    vector<set<int>> components(n);
    for (int i = 0; i < n; ++i) {
        components[i].insert(i + 1);
    }

    while (q--) {
        int com;
        cin >> com;
        if (com == 1) {
            int u, v;
            cin >> u >> v;
            uf.unite(u - 1, v - 1);
        } else {
            int v, k;
            cin >> v >> k;
            int root = uf.findRoot(v - 1);
            if (k > components[root].size()) {
                cout << -1 << endl;
            } else {
                auto it = prev(components[root].lower_bound(k));
                cout << *it << endl;
            }
        }
    }

    return 0;
}