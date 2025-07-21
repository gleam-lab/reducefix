#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, int>; // (cost, node)

const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<vector<P>> G(N); // Adjacency list: G[u] contains (v, B_uv)
    for (int i = 0; i < M; ++i) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        u--; v--;
        G[u].push_back({b, v});
        G[v].push_back({b, u});
    }

    vector<ll> dist(N, INF);
    dist[0] = A[0]; // Start from node 0 with its value included

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto [b, v] : G[u]) {
            ll new_cost = d + b + A[v]; // current cost + edge + target vertex
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({new_cost, v});
            }
        }
    }

    for (int i = 1; i < N; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}