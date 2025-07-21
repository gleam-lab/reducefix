#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int, int>> adj[200005]; // Adjacency list with edge weights
int dist[200005]; // Distance array
int n, m; // Number of vertices and edges

void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap
    pq.push({0, src});
    dist[src] = 0; // Set the distance to the source to 0

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (current_dist > dist[u]) continue; // Skip if already visited

        // Visit all adjacent vertices
        for (auto &edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (current_dist + weight < dist[v]) {
                dist[v] = current_dist + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    scanf("%lld %lld", &n, &m);
    int a[200005]; // Vertex weights

    // Read vertex weights
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }

    // Read edges
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Initialize distances to a large value
    fill(dist, dist + n + 1, 1e18);

    // Run Dijkstra's algorithm from vertex 1
    dijkstra(1);

    // Output the minimum distances to all other vertices
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] + a[i] << " ";
    }
    cout << endl;

    return 0;
}