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

    vector<vector<pair<ll, ll>>> graph(N);
    for (ll i = 0; i < M; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        u--;
        v--;
        graph[u].emplace_back(v, b);
        graph[v].emplace_back(u, b);
    }

    // Dijkstra's algorithm
    vector<ll> dist(N, INF);
    using P = pair<ll, ll>; // (cost, node)
    priority_queue<P, vector<P>, greater<>> pq;

    dist[0] = A[0]; // Starting point includes vertex weight only
    pq.emplace(dist[0], 0);

    while (!pq.empty()) {
        auto [current_cost, u] = pq.top();
        pq.pop();

        if (current_cost > dist[u]) continue;

        for (const auto& [v, edge_weight] : graph[u]) {
            ll new_cost = current_cost + edge_weight + A[v]; // Include both edge and vertex weight
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.emplace(dist[v], v);
            }
        }
    }

    // Output results for nodes 2..N
    for (ll i = 1; i < N; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}