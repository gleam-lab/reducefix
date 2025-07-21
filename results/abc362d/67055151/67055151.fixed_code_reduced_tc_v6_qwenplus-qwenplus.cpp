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

    vector<vector<pair<ll, ll>>> graph(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        u--; v--;
        graph[u].emplace_back(v, b);
        graph[v].emplace_back(u, b);
    }

    // dist[i] = min cost to reach node i from node 0
    vector<ll> dist(n, INF);
    dist[0] = A[0];  // Only starting vertex adds its own vertex weight initially

    // Priority queue: pair<current_min_path_cost, current_node>
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.emplace(dist[0], 0);

    while (!pq.empty()) {
        auto [curr_cost, u] = pq.top();
        pq.pop();

        if (curr_cost > dist[u]) continue;

        for (auto [v, b] : graph[u]) {
            ll new_cost = curr_cost + b + A[v];  // Add edge weight and vertex weight of v

            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.emplace(dist[v], v);
            }
        }
    }

    // Output result for nodes 2 to N (1-based index)
    for (ll i = 1; i < n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}