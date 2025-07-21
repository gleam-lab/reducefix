#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>; // (distance, node)

const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<vector<P>> G(N); // G[u] contains pairs (v, edge_weight)
    for (ll i = 0; i < M; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        --u; --v;
        G[u].push_back({v, b});
        G[v].push_back({u, b});
    }

    priority_queue<P, vector<P>, greater<>> pq;
    vector<ll> dist(N, INF);

    // Start from node 0 with cost A[0] (weight of starting vertex)
    pq.push({A[0], 0});
    dist[0] = A[0];

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (cost > dist[u]) continue;

        for (auto [v, b] : G[u]) {
            ll new_cost = cost + b + A[v]; // current path cost to v
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({new_cost, v});
            }
        }
    }

    // Output results for nodes 2 to N (1-based index)
    for (ll i = 1; i < N; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}