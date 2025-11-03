#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int j = 0; j < m; j++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vector<long long> dist(n + 1, LLONG_MAX);
    dist[1] = a[0]; // Starting at vertex 1, we pay its vertex weight
    
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({a[0], 1});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u]) continue; // Skip outdated entries
        
        for (auto [v, edge_weight] : adj[u]) {
            long long new_dist = d + edge_weight + a[v - 1]; // current distance + edge weight + destination vertex weight
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
    
    for (int i = 2; i <= n; i++) {
        cout << dist[i] << (i == n ? "\n" : " ");
    }
    
    return 0;
}