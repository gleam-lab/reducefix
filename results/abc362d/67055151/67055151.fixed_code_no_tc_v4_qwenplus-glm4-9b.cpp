#include <vector>
#include <queue>
#include <iostream>
#include <climits>

using namespace std;

// Function to perform Dijkstra's algorithm on the graph
void dijkstra(const vector<vector<pair<int, int>>>& graph, int n) {
    vector<int> dist(n, INT_MAX); // Initialize distances to all vertices as MAX_VALUE
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap

    // Priority queue will store vertices and their current distances
    pq.push({0, 0}); // Starting point (vertex 1)
    dist[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second; // Vertex with the smallest distance
        pq.pop();

        for (auto& p : graph[u]) {
            int v = p.first;
            int weight = p.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Output the minimum weight for paths to vertices 2 through N
    for (int i = 1; i < n; ++i) {
        cout << dist[i] + graph[i][0].second << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m; // Number of vertices and edges

    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        // u and v are zero-based, so we decrement by 1
        graph[u - 1].push_back({v - 1, b});
        graph[v - 1].push_back({u - 1, b});
    }

    dijkstra(graph, n);

    return 0;
}