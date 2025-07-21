#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 1LL << 60;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Build graph: adjacency list with (neighbor, edge_weight)
    vector<vector<pair<ll, ll>>> graph(N);
    for (ll i = 0; i < M; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        --u, --v; // convert to 0-based index
        graph[u].emplace_back(v, b);
        graph[v].emplace_back(u, b);
    }

    // Dijkstra's algorithm
    vector<ll> dist(N, INF);
    dist[0] = A[0]; // start from vertex 0 (which is vertex 1 in problem statement)

    using P = pair<ll, ll>; // (distance, node)
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(dist[0], 0);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, b] : graph[u]) {
            ll new_dist = d + b + A[v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.emplace(dist[v], v);
            }
        }
    }

    // Output results for vertices 2 to N
    for (ll i = 1; i < N; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}