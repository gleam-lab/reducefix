#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using P = pair<ll, ll>; // (distance, node)

const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N, M;
    cin >> N >> M;

    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<vector<pair<ll, ll>>> graph(N); // graph[u] contains pairs (v, edge_weight)
    for (ll i = 0; i < M; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        --u;
        --v;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }

    priority_queue<P, vector<P>, greater<P>> pq;
    vector<ll> dist(N, INF);
    
    // Start from node 0 with its vertex weight
    dist[0] = A[0];
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, b] : graph[u]) {
            ll new_dist = dist[u] + b + A[v]; // Include edge weight and destination vertex weight
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({dist[v], v});
            }
        }
    }

    for (ll i = 1; i < N; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}