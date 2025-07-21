#include <bits/stdc++.h>
using namespace std;

#define MAXN 200010 // Maximum number of vertices and edges

using i64 = long long;

const i64 INF = 1e18;

// Dijkstra's algorithm to find the shortest path from a single source
void dijkstra(int source, const vector<pair<int, i64>>& adj[], i64 dist[]) {
    priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<pair<i64, int>>> pq;
    pq.push({0, source}); // Start with the source vertex
    dist[source] = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue; // Skip if already visited with a shorter path

        // Process all adjacent vertices
        for (auto [v, weight] : adj[u]) {
            i64 nextDist = d + weight + adj[v][0].second; // + adj[v][0].second is the vertex weight
            if (dist[v] > nextDist) {
                dist[v] = nextDist;
                pq.push({nextDist, v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, i64>> adj[MAXN + 1]; // Adjacency list with weights
    i64 dist[MAXN + 1];

    for (int i = 1; i <= n; ++i) {
        cin >> dist[i]; // Each vertex has a weight
    }

    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Since the graph is undirected
    }

    // Run Dijkstra's algorithm from vertex 1
    dijkstra(1, adj, dist);

    // Output the minimum weight for paths from vertex 1 to all other vertices
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}