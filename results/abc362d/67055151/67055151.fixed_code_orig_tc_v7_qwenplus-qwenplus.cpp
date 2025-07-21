#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<vector<pair<ll, ll>>> adj(N);
    for (ll i = 0; i < M; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        u--;
        v--;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }

    vector<ll> dist(N, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;

    // Start from node 0 (vertex 1)
    dist[0] = A[0];  // Include A[0] since it's part of the path
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (cost > dist[u]) continue;

        for (auto [v, b] : adj[u]) {
            ll new_cost = cost + A[v] + b;
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({new_cost, v});
            }
        }
    }

    // Output results for vertices 2 to N
    for (ll i = 1; i < N; ++i) {
        cout << dist[i] << " ";
    }
    cout << '\n';

    return 0;
}