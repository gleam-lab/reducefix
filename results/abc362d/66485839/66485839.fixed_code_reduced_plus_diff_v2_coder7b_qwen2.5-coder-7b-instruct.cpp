#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define pb push_back
#define mp make_pair
#define INF LLONG_MAX
#define MOD 1000000007

struct DSU {
    vector<ll> parent, rank;
    DSU(ll n) : parent(n + 1), rank(n + 1, 1) {
        for (ll i = 1; i <= n; ++i) parent[i] = i;
    }
    ll find(ll x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void merge(ll x, ll y) {
        ll px = find(x), py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        rank[px] += rank[py];
    }
};

struct Edge {
    ll u, v, w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

vvi adj;
vi dist;
vi minDist;
DSU dsu;

void dijkstra(ll src, ll n) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dist.assign(n + 1, INF);
    dist[src] = 0;
    pq.push({0, src});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto &[v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

void dfs(ll u, ll p, ll cost) {
    if (cost < minDist[u]) {
        minDist[u] = cost;
        dsu.merge(u, p);
    }
    for (auto &[v, _] : adj[u]) {
        if (v != p) dfs(v, u, cost + dsu.find(v));
    }
}

void preprocess(ll n) {
    for (ll i = 1; i <= n; ++i) {
        dijkstra(i, n);
        minDist.assign(n + 1, INF);
        dfs(i, -1, 0);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    adj.resize(n + 1);
    dsu = DSU(n);
    
    for (ll i = 1; i <= n; ++i) {
        ll a; cin >> a;
        dist.assign(n + 1, a);
        minDist.assign(n + 1, a);
    }
    
    for (ll i = 0; i < m; ++i) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    
    preprocess(n);
    
    for (ll i = 2; i <= n; ++i) {
        cout << minDist[i] << " ";
    }
    cout << "\n";
    return 0;
}