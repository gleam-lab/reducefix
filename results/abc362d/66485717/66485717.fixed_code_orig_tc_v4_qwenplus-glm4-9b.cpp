#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int MAX_N = 200000 + 10;
vector<pair<int, int>> adj[MAX_N]; // Adjacency list to store (neighbor, weight)
vector<long long> dist(MAX_N, numeric_limits<long long>::max()); // Distance array initialized to max long long
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; // Min-heap priority queue

void dijkstra(int src) {
    dist[src] = 0; // Distance to the source vertex is 0
    pq.push({0, src});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u]) continue; // Skip if we've found a better path already
        
        for (auto [v, weight] : adj[u]) {
            long long alt = d + weight + dist[v]; // Calculate alternative path distance
            if (dist[v] > alt) {
                dist[v] = alt;
                pq.push({alt, v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) {
        cin >> dist[i]; // Read vertex weights
    }
    
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight; // Read edges
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }
    
    dijkstra(1); // Run Dijkstra's algorithm from vertex 1
    
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " "; // Output the minimum distance to each vertex starting from 2
    }
    cout << endl;
    
    return 0;
}