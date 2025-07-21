#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

vector<vector<ll>> adj;
vector<bool> visited;
vector<ll> dist;

void dijkstra(ll start) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    dist.assign(n + 1, INF);
    visited.assign(n + 1, false);

    for (ll i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Assuming undirected graph
    }

    dijkstra(1);

    if (dist[1] == INF) {
        cout << "-1" << endl;
    } else {
        cout << dist[1] << endl;
    }

    return 0;
}