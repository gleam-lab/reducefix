#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<ll, int>;

const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N, M;
    cin >> N >> M;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Build graph: adjacency list of pairs (neighbor, edge weight)
    vector<vector<P>> G(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        u--;
        v--;
        G[u].push_back({v, b});
        G[v].push_back({u, b});
    }

    // Dijkstra's algorithm
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<ll> dist(N, INF);

    // Start from node 0 with initial cost A[0]
    dist[0] = A[0];
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, b] : G[u]) {
            ll new_cost = d + b + A[v]; // path cost to v via u
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({dist[v], v});
            }
        }
    }

    // Output results for nodes 2 to N
    for (int i = 1; i < N; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}