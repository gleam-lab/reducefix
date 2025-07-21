#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<vector<pair<int, long long>>> adj(N + 1); // adj[u] contains pairs (v, edge_weight)
    for (int j = 0; j < M; ++j) {
        int u, v;
        long long b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }

    const long long INF = 1e18;
    vector<long long> dist(N + 1, INF);
    dist[1] = A[0]; // Start node's cost includes its vertex weight

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({dist[1], 1});

    while (!pq.empty()) {
        auto [current_dist, u] = pq.top();
        pq.pop();

        if (current_dist > dist[u]) continue;

        for (auto &[v, edge_cost] : adj[u]) {
            long long new_cost = current_dist + edge_cost + A[v - 1]; // Add edge and destination vertex weight
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({new_cost, v});
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << " ";
    }
    cout << '\n';

    return 0;
}