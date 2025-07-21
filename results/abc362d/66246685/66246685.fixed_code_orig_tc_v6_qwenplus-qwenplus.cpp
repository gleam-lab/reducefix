#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<vector<pair<ll, ll>>> G(N);
    for (ll i = 0; i < M; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        u--; v--;
        G[u].push_back({v, b});
        G[v].push_back({u, b});
    }

    // Distance array: dist[i] = minimum path weight from node 0 to node i
    const ll INF = 1e18;
    vector<ll> dist(N, INF);
    dist[0] = A[0];  // Starting at node 1 (index 0), include its own weight

    // Priority queue: {distance_to_node, node}
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;  // Already processed a better path

        for (auto [v, b] : G[u]) {
            ll new_dist = d + b + A[v];

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }

    // Output results for vertices 2 through N
    for (ll i = 1; i < N; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}