#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
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
    
    vector<long long> dist(n + 1, 1e18);
    dist[1] = a[1];  // Start with vertex weight of node 1
    
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    q.push({a[1], 1});
    
    while (!q.empty()) {
        auto [d, node] = q.top();
        q.pop();
        
        if (d != dist[node]) continue;  // Skip outdated entries
        
        for (auto [neighbor, edge_weight] : adj[node]) {
            long long new_dist = dist[node] + edge_weight + a[neighbor];
            if (new_dist < dist[neighbor]) {
                dist[neighbor] = new_dist;
                q.push({new_dist, neighbor});
            }
        }
    }
    
    for (int i = 2; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
    
    return 0;
}