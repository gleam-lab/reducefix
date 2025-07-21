#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

vector<vector<pair<int, int>>> graph(200005); // adjacency list: {v, edge_weight}
int A[200005]; // vertex weights
int dist[200005]; // shortest path distances from node 1

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Initialize distances
    for(int i = 0; i <= 200004; ++i) {
        dist[i] = INF;
    }
    
    // Start from node 1, initial distance is the weight of node 1
    dist[1] = A[1];
    pq.push({dist[1], 1});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int current_dist = pq.top().first;
        pq.pop();
        
        // If we've already found a shorter path to u, skip
        if (current_dist > dist[u]) continue;
        
        // Explore neighbors
        for (auto &edge : graph[u]) {
            int v = edge.first;
            int edge_weight = edge.second;
            
            // Calculate new distance to v
            int new_dist = dist[u] + edge_weight + A[v];
            
            // If new path is shorter, update
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({dist[v], v});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // Since the graph is undirected
    }
    
    dijkstra();
    
    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";
    
    return 0;
}