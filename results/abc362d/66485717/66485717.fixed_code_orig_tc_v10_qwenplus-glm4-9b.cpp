#include <bits/stdc++.h>
using namespace std;

#define INT long long
#define N 200010
vector<pair<int, int>> g[N]; // Adjacency list for graph

// Dijkstra's algorithm to find shortest path from vertex 1 to all other vertices
void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Max-heap to store distances
    vector<int> dist(N, INT_MAX); // Distance array
    dist[src] = 0;
    pq.push({0, src}); // Push starting vertex with distance 0

    while (!pq.empty()) {
        int d = pq.top().first; 
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue; // Skip if a newer, shorter path has already been found

        for (auto edge : g[u]) {
            int v = edge.first;
            int weight = edge.second;

            // Calculate the distance through this edge
            int path_weight = d + weight + g[v][0].second; 

            if (path_weight < dist[v]) {
                dist[v] = path_weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Output the distances for vertices from 2 to N
    for (int i = 2; i < N; ++i) {
        cout << dist[i] << (i == N - 1 ? "\n" : " ");
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> A(N + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i]; // Read vertex weights
    }

    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b; // Read edges
        g[u].push_back({v, b}); // Store edges in both directions
        g[v].push_back({u, b});
    }

    // Find the shortest path from vertex 1
    dijkstra(1);

    return 0;
}