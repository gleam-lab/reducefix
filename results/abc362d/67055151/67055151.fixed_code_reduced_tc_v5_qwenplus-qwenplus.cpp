#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
constexpr ll INF = 5e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Build graph: adjacency list of (neighbor, edge weight)
    vector<vector<pll>> graph(N);
    for (ll i = 0; i < M; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        u--; v--;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }

    // Dijkstra's algorithm
    vector<ll> dist(N, INF);
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    dist[0] = A[0]; // Starting point includes vertex weight
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, b] : graph[u]) {
            ll new_dist = d + b + A[v]; // Add edge weight and vertex weight of v
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({dist[v], v});
            }
        }
    }

    // Output result for nodes 2 to N (1-based -> 1 to N-1 in 0-based)
    for (ll i = 1; i < N; ++i) {
        cout << dist[i] << " ";
    }
    cout << '\n';

    return 0;
}