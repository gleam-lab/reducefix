#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

vector<pair<int, int>> adj[200001]; // Adjacency list representation

// Dijkstra's algorithm to find the shortest path from vertex 1 to all other vertices
void dijkstra(int start, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start}); // {weight, vertex}

    vector<int> dist(n + 1, INF);
    dist[start] = 0;

    while (!pq.empty()) {
        int currentWeight = pq.top().first;
        int currentVertex = pq.top().second;
        pq.pop();

        if (currentWeight > dist[currentVertex]) continue;

        for (auto &edge : adj[currentVertex]) {
            int nextVertex = edge.first;
            int weight = edge.second;

            if (dist[nextVertex] > currentWeight + weight) {
                dist[nextVertex] = currentWeight + weight;
                pq.push({dist[nextVertex], nextVertex});
            }
        }
    }

    // Output the minimum weight for each vertex from 2 to n
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    int a[n + 1];
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }

    dijkstra(1, n);

    return 0;
}