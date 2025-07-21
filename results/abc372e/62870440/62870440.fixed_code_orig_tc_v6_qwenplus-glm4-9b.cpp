#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UnionFind {
public:
    vector<int> parent;
    vector<int> size;

    UnionFind(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);
    vector<vector<int>> componentes(N + 1);

    int u, v, k;

    for (int q = 0; q < Q; ++q) {
        cin >> u >> v;
        if (u == 1) {
            uf.unionSet(u, v);
        } else {
            cin >> k;
            int root = uf.find(v);
            if (k > (int)componentes[root].size()) {
                cout << -1 << endl;
            } else {
                cout << componentes[root][componentes[root].size() - k] << endl;
            }
        }
    }

    return 0;
}