#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findRoot(int x) {
        if (parent[x] != x)
            parent[x] = findRoot(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int rx = findRoot(x), ry = findRoot(y);
        if (rx == ry) return false;
        if (rank[rx] < rank[ry]) {
            parent[rx] = ry;
        } else {
            parent[ry] = rx;
            if (rank[rx] == rank[ry])
                rank[rx]++;
        }
        return true;
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    UnionFind uf(n);
    vector<set<int>> components(n);

    for (int i = 0; i < q; i++) {
        int queryType, u, v, k;
        cin >> queryType;

        if (queryType == 1) {
            cin >> u >> v;
            uf.unite(u - 1, v - 1);
        } else if (queryType == 2) {
            cin >> v >> k;
            int rootV = uf.findRoot(v - 1);
            if (components[rootV].size() < k) {
                cout << -1 << endl;
            } else {
                auto it = components[rootV].rbegin();
                advance(it, k - 1);
                cout << *it + 1 << endl;
            }
        }
    }

    return 0;
}