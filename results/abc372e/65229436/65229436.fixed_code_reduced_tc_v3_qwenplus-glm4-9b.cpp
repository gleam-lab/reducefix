#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
using ll = long long;

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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    
    UnionFind uf(n + 1);
    vector<vector<int>> adj(n + 1);
    
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            uf.unite(u, v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            int root = uf.findRoot(v);
            set<int> group = {root};
            for (int x : adj[root])
                group.insert(uf.findRoot(x));
            
            int ans = -1;
            int count = 0;
            for (int x : group) {
                for (int elem : adj[x]) {
                    if (uf.findRoot(elem) != root)
                        continue;
                    if (++count == k)
                        ans = elem;
                    if (count == k)
                        break;
                }
                if (count == k)
                    break;
            }
            cout << ans + 1 << endl;
        }
    }
    
    return 0;
}