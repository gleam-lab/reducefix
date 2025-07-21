#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int, int>> G[200005]; // Graph represented as adjacency list
int dist[200005]; // Distance to each vertex
int vertex_weight[200005]; // Vertex weights
int n, m; // Number of vertices and edges

void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist, dist + n + 1, LLONG_MAX); // Initialize distances to maximum possible values
    dist[src] = vertex_weight[src]; // Distance to the source vertex is its own weight
    pq.push({dist[src], src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto edge : G[u]) {
            int v = edge.first;
            int weight = edge.second + vertex_weight[v]; // Include vertex weight
            if (dist[v] > weight) {
                dist[v] = weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> vertex_weight[i]; // Read vertex weights
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    dijkstra(1); // Run Dijkstra's from vertex 1

    for (int i = 2; i <= n; i++) {
        cout << dist[i] << ' '; // Print the minimum distance to each vertex
    }
    cout << '\n';

    return 0;
}