#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    // Adjacency list representation of the graph
    vector<vector<pair<int, long long>>> adj(n + 1);
    for(int j = 0; j < m; j++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Distance array to store the minimum distance from vertex 1 to all other vertices
    vector<long long> dist(n + 1, LLONG_MAX);
    dist[1] = a[0]; // Starting point

    // Priority queue to process nodes based on their current shortest distance
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({a[0], 1});

    while(!pq.empty()) {
        auto [current_dist, node] = pq.top();
        pq.pop();

        // If we have already found a shorter path to this node, skip further processing
        if(current_dist > dist[node]) continue;

        // Explore all adjacent nodes
        for(const auto& [neighbor, edge_weight] : adj[node]) {
            long long new_distance = current_dist + edge_weight + a[neighbor - 1];

            // Update the distance if a shorter path is found
            if(new_distance < dist[neighbor]) {
                dist[neighbor] = new_distance;
                pq.push({new_distance, neighbor});
            }
        }
    }

    // Print the results for vertices 2 through n
    for(int i = 2; i <= n; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}