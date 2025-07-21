#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 5LL << 60;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<ll> A(n);
    for (ll i = 0; i < n; ++i) cin >> A[i];

    // Build adjacency list: Graph[u] contains pairs (v, B_uv)
    vector<vector<pair<ll, ll>>> graph(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        --u; --v;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b}); // Undirected
    }

    // Dijkstra's Algorithm
    vector<ll> dist(n, INF);
    dist[0] = A[0]; // Starting point includes A[0]

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, b] : graph[u]) {
            ll new_cost = d + b + A[v];
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({dist[v], v});
            }
        }
    }

    // Output results for nodes 2 through N
    for (ll i = 1; i < n; ++i) {
        cout << dist[i] << " ";
    }
    cout << '\n';

    return 0;
}