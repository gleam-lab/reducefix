#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;
const int MAXN = 2e5 + 5;

vector<vector<pair<int, int>>> graph(MAXN); // {to, weight}
int A[MAXN]; // Vertex weights
int dist[MAXN]; // Minimum distance from vertex 1

void dijkstra(int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    // Initialize distances to infinity
    for (int i = 1; i <= n; ++i) {
        dist[i] = INF;
    }
    
    // Start from node 1 with path weight including A[1]
    dist[1] = A[1];
    pq.push({dist[1], 1});
    
    while (!pq.empty()) {
        auto [current_dist, u] = pq.top();
        pq.pop();
        
        // If we've already found a better path to u, skip
        if (current_dist > dist[u]) continue;
        
        // Explore neighbors
        for (auto [v, edge_weight] : graph[u]) {
            // Calculate new path cost: current path cost - A[u] (already included in dist[u]) + edge weight + A[v]
            int new_dist = current_dist - A[u] + edge_weight + A[v];
            
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
        int u, v, b;
        cin >> u >> v >> b;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }
    
    dijkstra(N);
    
    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";
    
    return 0;
}