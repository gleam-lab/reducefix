#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF LLONG_MAX

vector<pair<int, int>> adj[200010]; // Adjacency list to store the graph
vector<int> weights; // Vector to store weights of nodes
vector<int> dist; // Distance array to store shortest paths

void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Initialize distances with infinity
    dist.assign(weights.size(), INF);
    dist[src] = weights[src];
    
    pq.push({weights[src], src});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int u_dist = pq.top().first;
        pq.pop();
        
        // If we've already found a shorter path to this node, skip it
        if (u_dist > dist[u])
            continue;
        
        // Explore neighbors
        for (auto &v : adj[u]) {
            int v_id = v.first;
            int v_weight = v.second;
            
            // Calculate new distance
            int new_dist = u_dist + v_weight + weights[v_id];
            
            // If a shorter path is found, update distance and push to queue
            if (new_dist < dist[v_id]) {
                dist[v_id] = new_dist;
                pq.push({new_dist, v_id});
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    weights.resize(n+1);
    dist.resize(n+1);
    
    for (int i = 1; i <= n; ++i)
        cin >> weights[i];
    
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    // Run Dijkstra's algorithm starting from node 1
    dijkstra(1);
    
    // Print the shortest path distances for nodes 2 through n
    for (int i = 2; i <= n; ++i)
        cout << dist[i] << " ";
    
    return 0;
}