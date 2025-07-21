#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>; // {distance, node}

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

    vector<vector<P>> G(N); // adjacency list

    for (int i = 0; i < M; ++i) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        u--; v--;
        G[u].push_back({v, b});
        G[v].push_back({u, b});
    }

    priority_queue<P, vector<P>, greater<P>> pq;
    vector<ll> dist(N, INF);

    // Start from node 0 with cost A[0] (vertex cost)
    dist[0] = A[0];
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        ll d = pq.top().first;
        ll u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, b] : G[u]) {
            ll new_dist = dist[u] + b + A[v]; // include edge weight and destination vertex weight
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({dist[v], v});
            }
        }
    }

    // Output results for nodes 1 to N-1 (i.e., vertices 2 to N in 1-based)
    for (int i = 1; i < N; ++i) {
        cout << dist[i] << " ";
    }
    cout << '\n';

    return 0;
}