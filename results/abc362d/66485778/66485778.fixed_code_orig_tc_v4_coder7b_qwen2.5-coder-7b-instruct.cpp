#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const ll INF = 1e18;

struct DSU {
    vector<ll> parent, rank;
    DSU(ll n) : parent(n + 1), rank(n + 1, 1) {
        for (ll i = 1; i <= n; ++i) parent[i] = i;
    }

    ll find(ll u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }

    void merge(ll u, ll v) {
        ll pu = find(u), pv = find(v);
        if (pu == pv) return;
        if (rank[pu] < rank[pv]) swap(pu, pv);
        parent[pv] = pu;
        rank[pu] += rank[pv];
    }
};

struct Edge {
    ll u, v, w;
    Edge(ll _u, ll _v, ll _w) : u(_u), v(_v), w(_w) {}
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

vector<vector<pii>> adj;

void dijkstra(ll start, vector<ll>& dist) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        ll u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto &[v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; ++i) cin >> a[i];

    adj.resize(n + 1);
    for (ll i = 1; i <= m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<ll> dist(n + 1, INF);
    dijkstra(1, dist);

    for (ll i = 2; i <= n; ++i) {
        cout << dist[i] + a[i] << " ";
    }
    cout << "\n";

    return 0;
}