#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll INF = LLONG_MAX;

struct DSU {
    vector<ll> parent, rank;

    DSU(ll n) : parent(n+1), rank(n+1, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    ll find(ll node) {
        if (parent[node] != node)
            parent[node] = find(parent[node]);
        return parent[node];
    }

    void merge(ll u, ll v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (rank[u] > rank[v])
            swap(u, v);
        parent[u] = v;
        if (rank[u] == rank[v])
            rank[v]++;
    }
};

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n+1, 0);
    vector<vector<pll>> adj(n+1);

    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (ll i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<ll> dist(n+1, INF);
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    dist[1] = a[1];
    pq.push({dist[1], 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &[v, w] : adj[u]) {
            if (dist[u] + w + a[v] < dist[v]) {
                dist[v] = dist[u] + w + a[v];
                pq.push({dist[v], v});
            }
        }
    }

    for (ll i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}