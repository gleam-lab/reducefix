#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge {
    ll u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

struct DSU {
    vector<int> parent, rank;
    
    DSU(int n) : parent(n), rank(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }
    
    void unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return;
        
        if (rank[pu] < rank[pv]) swap(pu, pv);
        parent[pv] = pu;
        rank[pu] += rank[pv];
    }
};

vector<ll> dijkstra(int start, vector<vector<pair<int, ll>>> adj, int n) {
    vector<ll> dist(n, LLONG_MAX);
    dist[start] = 0;
    set<pair<ll, int>> pq;
    pq.insert({dist[start], start});
    
    while (!pq.empty()) {
        auto [d, u] = *pq.begin(); pq.erase(pq.begin());
        if (d > dist[u]) continue;
        
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.insert({dist[v], v});
            }
        }
    }
    
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<vector<pair<int, ll>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    
    vector<ll> result(n - 1, LLONG_MAX);
    DSU dsu(n);
    
    for (int i = 0; i < n; ++i) {
        for (auto [v, w] : adj[i]) {
            if (dsu.find(i) != dsu.find(v)) {
                dsu.unite(i, v);
                result[min(i, v)] = min(result[min(i, v)], a[i] + a[v] + w);
            }
        }
    }
    
    for (int i = 1; i < n; ++i) {
        if (result[i - 1] == LLONG_MAX) result[i - 1] = a[i];
        else result[i - 1] = min(result[i - 1], a[i]);
    }
    
    for (int i = 1; i < n; ++i) {
        cout << result[i - 1] << " ";
    }
    cout << endl;
    
    return 0;
}