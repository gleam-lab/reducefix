#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>; // (cost, node)

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

    vector<vector<P>> graph(N);
    for (ll i = 0; i < M; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        --u; --v;
        graph[u].push_back({b, v});
        graph[v].push_back({b, u});
    }

    vector<ll> dist(N, INF);
    priority_queue<P, vector<P>, greater<P>> pq;

    // Start from node 0 with cost A[0] (vertex weight included at start)
    dist[0] = A[0];
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [b, v] : graph[u]) {
            ll new_cost = d + b + A[v]; // current path cost + edge + target vertex weight
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({dist[v], v});
            }
        }
    }

    // Output results for nodes 2 to N (1-based index -> skip first element)
    for (ll i = 1; i < N; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}