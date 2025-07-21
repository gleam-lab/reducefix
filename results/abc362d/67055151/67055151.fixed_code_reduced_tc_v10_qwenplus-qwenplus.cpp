#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 5LL << 60;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<ll> A(n);
    for (ll i = 0; i < n; ++i) {
        cin >> A[i];
    }

    vector<vector<pair<ll, ll>>> adj(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        --u; --v;
        adj[u].emplace_back(v, b);
        adj[v].emplace_back(u, b);
    }

    // Dijkstra's algorithm using min-heap (priority_queue)
    vector<ll> dist(n, INF);
    dist[0] = A[0];  // Starting node includes its own vertex weight

    using State = pair<ll, ll>;  // (current_cost, node)
    priority_queue<State, vector<State>, greater<>> pq;
    pq.emplace(dist[0], 0);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, b] : adj[u]) {
            ll new_cost = d + b + A[v];  // current cost + edge weight + destination vertex weight
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.emplace(new_cost, v);
            }
        }
    }

    // Output results for nodes 2 to N
    for (ll i = 1; i < n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}