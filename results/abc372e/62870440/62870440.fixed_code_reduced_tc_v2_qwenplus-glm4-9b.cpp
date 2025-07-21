#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

struct UnionFind {
    vector<int> parent;
    vector<vector<int>> sizes;

    UnionFind(int n) : parent(n + 1), sizes(n + 1) {
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
            sizes[i] = {i};
        }
    }

    int find(int x) {
        if (x == parent[x]) return x;
        int rootX = find(parent[x]);
        sizes[x].insert(sizes[x].end(), sizes[parent[x]].begin(), sizes[parent[x]].end());
        sizes[parent[x]].clear();
        parent[x] = rootX;
        return rootX;
    }

    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return false;

        if (sizes[rootX].size() > sizes[rootY].size()) {
            sizes[rootX].insert(sizes[rootY].end(), sizes[rootY].begin(), sizes[rootY].end());
            sizes[rootY].clear();
            parent[rootY] = rootX;
        } else {
            sizes[rootY].insert(sizes[rootX].end(), sizes[rootX].begin(), sizes[rootX].end());
            sizes[rootX].clear();
            parent[rootX] = rootY;
        }
        return true;
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    UnionFind uf(n);

    for (int i = 0; i < q; ++i) {
        int op, v, k;
        cin >> op >> v >> k;

        if (op == 1) {
            int u;
            cin >> u;
            uf.unionSets(u, v);
        } else {
            int rootV = uf.find(v);
            int count = 0;
            for (int x : uf.sizes[rootV]) {
                if (x != v) ++count;
                if (count == k) {
                    cout << x << endl;
                    break;
                }
            }
            if (count < k) cout << -1 << endl;
        }
    }

    return 0;
}