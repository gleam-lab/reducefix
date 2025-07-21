#include <iostream>
#include <vector>

using namespace std;

struct UnionFind {
    vector<int> par, rank, size;

    UnionFind(int n) : par(n), rank(n, 0), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            par[i] = i;
        }
    }

    int find(int x) {
        if (x == par[x]) return x;
        par[x] = find(par[x]);
        return par[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) swap(x, y);
        par[y] = x;
        size[x] += size[y];
        if (rank[x] == rank[y]) rank[x]++;
    }

    int getSize(int x) {
        return size[find(x)];
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    int u, v, k;
    for (int i = 0; i < q; ++i) {
        cin >> op;
        if (op == 1) {
            cin >> u >> v;
            uf.unite(u - 1, v - 1); // Assuming 1-based index in input
        } else {
            cin >> v >> k;
            if (uf.getSize(v - 1) < k) {
                cout << -1 << endl;
            } else {
                // Find the k-th largest using the size array and the order of elements
                // This is a simplified example and assumes that size[find(x)] gives the ordered list of elements
                // In a real implementation, you would need to maintain an ordered list of vertices
                int root = uf.find(v - 1);
                int count = 0;
                for (int i = 0; i < n; ++i) {
                    if (uf.find(i) == root) {
                        count++;
                        if (count == k) {
                            cout << i + 1 << endl; // Convert to 1-based index
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}