#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int di[] = {1, -1, 0, 0};
const int dj[] = {0, 0, 1, -1};
const int INF = 1e9;
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
    bool unite(int x, int y) {
        int rx = findRoot(x), ry = findRoot(y);
        if (rx == ry) return false;
        if (rank[rx] < rank[ry]) {
            parent[rx] = ry;
            size[ry] += size[rx];
        } else {
            parent[ry] = rx;
            size[rx] += size[ry];
            if (rank[rx] == rank[ry])
                rank[rx]++;
        }
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
    vector<set<int>> adj(n);
    vector<int> ans;
    
    rep(qi, q) {
        int com;
        cin >> com;
        if (com == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            if (uf.findRoot(u) != uf.findRoot(v)) {
                uf.unite(u, v);
                adj[u].insert(v);
                adj[v].insert(u);
            }
        } else {
            int v, k;
            cin >> v >> k;
            v--;
            if (adj[v].size() < k) ans.push_back(-1);
            else {
                auto it = adj[v].rbegin();
                advance(it, k - 1);
                ans.push_back(*it + 1);
            }
        }
    }
    for (auto x : ans) cout << x << endl;
    return 0;
}