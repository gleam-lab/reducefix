#include <bits/stdc++.h>

using namespace std;

struct dsu {
    vector<int> par, sz;
    dsu(int n) : par(n + 1), sz(n + 1, 1) { iota(par.begin(), par.end(), 0); }
    
    int get(int x) {
        if (par[x] == x) return x;
        return par[x] = get(par[x]);
    }
    
    void merge(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<long long> a(n + 1), dist(n + 1, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    vector<vector<pair<int, long long>>> g(n + 1);
    dsu d(n);
    
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    
    pq.push({a[1], 1});
    dist[1] = a[1];
    
    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        
        if (dist[u] < w) continue;
        
        for (auto [v, vw] : g[u]) {
            if (dist[v] > dist[u] + vw + a[v]) {
                dist[v] = dist[u] + vw + a[v];
                pq.push({dist[v], v});
            }
        }
    }
    
    for (int i = 2; i <= n; ++i) cout << dist[i] << ' ';
    
    return 0;
}