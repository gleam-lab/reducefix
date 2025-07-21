#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<long long> A(N + 1); // Vertex weights (1-indexed)
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    // Build adjacency list: each entry is a pair of (neighbor, edge weight)
    vector<vector<pair<int, long long>>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        long long b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }

    // Dijkstra's algorithm
    vector<long long> dist(N + 1, 1e18);
    dist[1] = A[1]; // Start from vertex 1, include its weight

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({dist[1], 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, b] : adj[u]) {
            long long new_dist = d + b + A[v]; // current path cost + edge + destination node weight
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({dist[v], v});
            }
        }
    }

    // Output result for nodes 2 to N
    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}