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
        u--; v--;
        graph[u].emplace_back(v, b);
        graph[v].emplace_back(u, b);
    }

    // Dijkstra's Algorithm
    vector<ll> dist(N, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;

    // Start from node 0 with cost A[0]
    dist[0] = A[0];
    pq.emplace(dist[0], 0);

    while (!pq.empty()) {
        auto [current_cost, u] = pq.top();
        pq.pop();

        if (current_cost > dist[u]) continue;

        for (const auto& [v, b] : graph[u]) {
            ll new_cost = current_cost + b + A[v]; // Cost to reach v via u
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.emplace(dist[v], v);
            }
        }
    }

    // Output results for nodes 2 to N (1-based)
    for (ll i = 1; i < N; ++i) {
        cout << dist[i] << " ";
    }
    cout << '\n';

    return 0;
}