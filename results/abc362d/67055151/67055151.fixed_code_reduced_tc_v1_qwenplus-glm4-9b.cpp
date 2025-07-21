#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int MAX_N = 200000;
vector<pair<int, int>> edges[MAX_N]; // Adjacency list for the graph
int vertex_weights[MAX_N];          // Vertex weights
int dist[MAX_N];                    // Distance from vertex 1 to vertex i
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Priority queue for Dijkstra's

int main() {
    int n, m;
    cin >> n >> m;

    // Read vertex weights
    for (int i = 0; i < n; ++i) {
        cin >> vertex_weights[i];
    }

    // Read edges
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        edges[u - 1].push_back({v - 1, b}); // Convert to 0-indexed
        edges[v - 1].push_back({u - 1, b}); // Since it's undirected
    }

    // Initialize distances
    for (int i = 0; i < n; ++i) {
        dist[i] = numeric_limits<int>::max();
    }
    dist[0] = vertex_weights[0]; // Start from vertex 1

    // Dijkstra's algorithm
    pq.push({dist[0], 0});
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();

        if (d > dist[v]) continue;

        for (auto& [u, b] : edges[v]) {
            int new_dist = d + b + vertex_weights[u];
            if (new_dist < dist[u]) {
                dist[u] = new_dist;
                pq.push({new_dist, u});
            }
        }
    }

    // Output results for vertices 2 to N
    for (int v = 1; v < n; ++v) {
        cout << dist[v] << (v < n - 1 ? " " : "\n");
    }

    return 0;
}