#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll INF = 5LL << 60;

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
        --u; --v;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }

    vector<ll> dist(n, INF);
    dist[0] = A[0]; // Starting node includes its own vertex weight

    using T = pair<ll, ll>; // (distance, node)
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, b] : graph[u]) {
            ll new_cost = d + b + A[v];
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({dist[v], v});
            }
        }
    }

    for (ll i = 1; i < n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}