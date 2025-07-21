#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>; // (distance, node)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N, M;
    cin >> N >> M;

    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<vector<pair<ll, ll>>> graph(N); // to, edge_weight
    for (ll i = 0; i < M; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        --u; --v;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }

    vector<ll> dist(N, LLONG_MAX);
    priority_queue<P, vector<P>, greater<P>> pq;

    dist[0] = A[0]; // Start from vertex 1 (0-indexed), include its vertex weight
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, b] : graph[u]) {
            ll new_dist = d + b + A[v]; // path cost: current cost + edge cost + destination vertex cost
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({dist[v], v});
            }
        }
    }

    for (ll i = 1; i < N; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}