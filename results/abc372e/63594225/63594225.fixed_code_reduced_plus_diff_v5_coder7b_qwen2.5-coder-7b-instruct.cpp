#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second
#define ll long long
#define vi vector<int>
#define pb push_back

const int MAXN = 2e5 + 5;
vi adj[MAXN];
int deg[MAXN], parent[MAXN];

struct DSU {
    int parent[MAXN], rank[MAXN];
    void init(int n) {
        iota(parent, parent+n, 0);
        fill(rank, rank+n, 1);
    }
    int find(int x) {
        if(x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return;
        if(rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if(rank[x] == rank[y]) ++rank[x];
    }
} dsu;

void dfs(int node, int p) {
    parent[node] = p;
    for(auto child : adj[node]) {
        if(child == p) continue;
        dfs(child, node);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;
    dsu.init(n);
    for(int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
        dsu.unite(u, v);
    }

    dfs(0, -1);

    vector<set<int>> groups(n);
    for(int i = 0; i < n; ++i) {
        groups[dsu.find(i)].insert(i+1);
    }

    vector<int> res(m);
    for(int i = 0; i < m; ++i) {
        int t, u, k; cin >> t >> u >> k;
        --u;
        if(t == 1) {
            int pu = dsu.find(u);
            groups[pu].erase(u+1);
            dsu.unite(u, parent[u]);
            pu = dsu.find(u);
            groups[pu].insert(u+1);
        } else {
            int pu = dsu.find(u);
            if(groups[pu].size() < k) {
                res[i] = -1;
            } else {
                auto it = groups[pu].rbegin();
                advance(it, k-1);
                res[i] = *it;
            }
        }
    }

    for(int i = 0; i < m; ++i) {
        if(res[i] != -1) {
            cout << res[i] << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}