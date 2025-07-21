#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }

    vector<long long> dist(n + 1, LLONG_MAX);
    dist[1] = a[0]; // Corrected to use the vertex weight of the starting vertex

    // Use a priority queue to ensure we are always expanding from the vertex with the shortest path
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({dist[1], 1});

    while (!pq.empty()) {
        auto [curr_dist, u] = pq.top();
        pq.pop();

        if (curr_dist > dist[u]) continue; // Skip if we have already found a better path

        for (auto &edge : adj[u]) {
            int v = edge.first;
            long long edge_weight = edge.second;

            // Calculate the total distance to vertex v considering both its vertex weight and the edge weight
            long long total_dist = curr_dist + edge_weight + a[v - 1];

            if (total_dist < dist[v]) {
                dist[v] = total_dist;
                pq.push({dist[v], v});
            }
        }
    }

    // Output the minimum distances from vertex 1 to all other vertices from 2 to N
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}