#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    // Adjusting indices for zero-based indexing
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int j = 0; j < m; j++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].push_back({v - 1, w});
        adj[v - 1].push_back({u - 1, w});
    }

    vector<long long> dist(n, LLONG_MAX);
    dist[0] = a[0]; // Start node is 0 based index
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({a[0], 0}); // Start node is 0 based index
    
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int u = p.second, d = p.first;
        
        // Skip already processed nodes
        if (d > dist[u]) continue;
        
        for (auto &edge : adj[u]) {
            int v = edge.first, weight = edge.second;
            long long newDist = d + weight + a[v]; // Update distance
            
            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }
    
    for (int i = 1; i < n; i++) {
        cout << dist[i] << " ";
    }
    return 0;
}