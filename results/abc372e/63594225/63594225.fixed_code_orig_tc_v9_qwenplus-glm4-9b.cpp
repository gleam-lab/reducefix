#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 200000;

struct UnionFind {
    vector<int> parent;
    vector<int> size;

    UnionFind(int n) : parent(n + 1), size(n + 1, 1) {
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
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

    int getSize(int x) {
        return size[find(x)];
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);

    while (q--) {
        int t, u, v, k;
        cin >> t >> u >> v;
        if (t == 1) {
            uf.unite(u, v);
        } else {
            int rootV = uf.find(v);
            int size = uf.getSize(rootV);
            if (k > size) {
                cout << -1 << '\n';
            } else {
                // Output the k-th largest element in the sorted order of vertices
                // This part requires additional logic to maintain a sorted list within each component
            }
        }
    }

    return 0;
}