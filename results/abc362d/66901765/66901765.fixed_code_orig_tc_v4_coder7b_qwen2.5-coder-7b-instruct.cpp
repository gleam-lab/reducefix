#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<pair<ll, ll>>> adj;
vector<ll> dist;

void dijkstra(ll start) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

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
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    dist.assign(n + 1, LLONG_MAX);

    for (ll i = 1; i <= n; ++i) {
        cin >> dist[i]; // Read weights of nodes
    }

    for (ll i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra(1);

    for (ll i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}