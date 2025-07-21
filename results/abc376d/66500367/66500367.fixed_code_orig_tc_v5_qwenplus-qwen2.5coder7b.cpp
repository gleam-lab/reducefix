#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m, dep[N], parent[N];

void dfs(int u, int p) {
    parent[u] = p;
    dep[u] = dep[p] + 1;
    for(auto v : g[u]) if(v != p) dfs(v, u);
}

int lca(int u, int v) {
    while(dep[u] > dep[v]) u = parent[u];
    while(dep[v] > dep[u]) v = parent[v];
    while(u != v) u = parent[u], v = parent[v];
    return u;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }

    dfs(1, 0);

    int q; cin >> q;
    while(q--) {
        int u, v; cin >> u >> v;
        cout << dep[u] + dep[v] - 2 * dep[lca(u, v)] << '\n';
    }

    return 0;
}