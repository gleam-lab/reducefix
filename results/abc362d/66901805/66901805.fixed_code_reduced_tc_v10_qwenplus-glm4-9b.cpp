#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

vector<pair<int, int>> adj[200005]; // Adjacency list to store the graph

// Function to perform Dijkstra's algorithm on a given node
void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap based priority queue
    vector<int> dist(200005, INF); // Distance vector initialized to INF
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (current_dist > dist[u]) continue;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            // Calculate new distance through the current vertex
            int new_dist = dist[u] + weight + (v == start ? 0 : a[v]);

            // If the new distance is smaller, update the distance and push to the priority queue
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({dist[v], v});
            }
        }
    }

    // Output the minimum distances for each vertex except the start vertex
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Reading vertex weights
    vector<int> vertices(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> vertices[i];
    }

    // Read edges and construct the graph
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Initialize distances as INF
    vector<int> dist(n + 1, INF);
    dist[1] = a[1]; // Distance to the start vertex is 0 (vertex's own weight)

    // Perform Dijkstra's algorithm from vertex 1
    dijkstra(1);

    return 0;
}