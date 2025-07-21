#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
using ll = long long;

struct UnionFind {
    vector<int> parent, rank, size;
    UnionFind(int n) : parent(n), rank(n, 0), size(n, 1) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int findRoot(int x) {
        if (parent[x] != x) parent[x] = findRoot(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int rx = findRoot(x), ry = findRoot(y);
        if (rx == ry) return false;
        if (rank[rx] < rank[ry]) swap(rx, ry);
        if (rank[rx] == rank[ry]) rank[rx]++;
        parent[ry] = rx;
        size[rx] += size[ry];
        return true;
    }
    int getSize(int x) {
        return size[findRoot(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    vector<vector<int>> adj(n);
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
            if (uf.getSize(root) < k) {
                cout << -1 << endl;
            } else {
                auto it = upper_bound(all(adj[root]), k - 1);
                if (it != adj[root].end()) {
                    cout << *it + 1 << endl;
                } else {
                    cout << -1 << endl;
                }
            }
        }
    }
    return 0;
}