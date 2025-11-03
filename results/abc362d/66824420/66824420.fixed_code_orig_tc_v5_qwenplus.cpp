#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int j = 0; j < m; j++) {
        int x, y;
        long long w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    
    vector<long long> dist(n + 1, LLONG_MAX);
    dist[1] = a[0]; // Include vertex 1's weight as starting point
    
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({a[0], 1});
    
    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();
        
        // If we've already found a better path to this node, skip
        if (d > dist[node]) continue;
        
        for (auto [neighbor, edge_weight] : adj[node]) {
            long long new_dist = d + edge_weight + a[neighbor - 1];
            if (new_dist < dist[neighbor]) {
                dist[neighbor] = new_dist;
                pq.push({new_dist, neighbor});
            }
        }
    }
    
    for (int i = 2; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
    
    return 0;
}