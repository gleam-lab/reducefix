#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

struct UnionFind {
    vector<int> parent, rank, size;
    
    UnionFind(int n) : parent(n), rank(n, 0), size(n, 1) {
        iota(all(parent), 0);
    }

    int findRoot(int x) {
        if (parent[x] != x) 
            parent[x] = findRoot(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rx = findRoot(x), ry = findRoot(y);
        if (rx == ry) return;
        
        if (rank[rx] < rank[ry]) {
            parent[rx] = ry;
            size[ry] += size[rx];
        } else {
            parent[ry] = rx;
            size[rx] += size[ry];
            if (rank[rx] == rank[ry])
                rank[rx]++;
        }
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
    vector<set<int>> adj(n + 1);

    while (q--) {
        int com;
        cin >> com;
        if (com == 1) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            int ru = uf.findRoot(u), rv = uf.findRoot(v);
            if (ru != rv) {
                if (adj[ru].size() < adj[rv].size()) swap(ru, rv);
                uf.unite(ru, rv);
                int rnew = uf.findRoot(ru);
                int rold = (rnew == ru ? rv : ru);
                for (int x : adj[rv]) adj[rnew].insert(x);
                adj[rold].clear();
            }
        } else if (com == 2) {
            int v, k;
            cin >> v >> k;
            --v;
            int root = uf.findRoot(v);
            if (adj[root].size() < k) cout << -1 << '\n';
            else {
                auto it = adj[root].rbegin();
                advance(it, k - 1);
                cout << *it + 1 << '\n';
            }
        }
    }

    return 0;
}