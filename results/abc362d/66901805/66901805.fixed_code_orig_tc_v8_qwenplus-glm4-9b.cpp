#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

vector<pair<int, int>> adj[200005];  // Adjacency list for the graph
int dist[200005];  // Distance array
int a[200005];  // Vertex weights

void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // Min-heap for Dijkstra's
    pq.push({0, src});
    dist[src] = a[src];  // Distance to the source itself is its weight

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist[u] < d) continue;  // Skip if already processed with better distance

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight + a[v] < dist[v]) {
                dist[v] = dist[u] + weight + a[v];
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    fill(dist, dist + n + 1, INF);  // Initialize distances to infinity
    dijkstra(1);  // Run Dijkstra's from vertex 1

    // Output the results for vertices 2 to N
    for (int i = 2; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}