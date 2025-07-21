#include <bits/stdc++.h>
using namespace std;

#define vec vector
#define ll long long
#define INF 5LL << 60

template <typename T>
void chmin(T& x, const T& y) { x = min(x, y); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vec<ll> A(n);
    for (ll i = 0; i < n; ++i) cin >> A[i];

    // Build graph: adjacency list of (neighbor, edge weight)
    vec<vec<pair<ll, ll>>> graph(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        u--; v--;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }

    // Dijkstra setup
    vec<ll> dist(n, INF);
    dist[0] = A[0]; // Start from node 1 (0-based), include its own weight

    using P = pair<ll, ll>; // (distance, node)
    priority_queue<P, vec<P>, greater<P>> pq;
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, b] : graph[u]) {
            ll new_cost = d + b + A[v]; // Add edge weight and destination vertex weight
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({dist[v], v});
            }
        }
    }

    // Output results for nodes 2 to N
    for (ll i = 1; i < n; ++i) {
        cout << dist[i] << " ";
    }
    cout << '\n';

    return 0;
}