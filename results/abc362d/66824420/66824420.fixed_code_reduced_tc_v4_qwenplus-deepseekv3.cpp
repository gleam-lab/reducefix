#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int j = 0; j < m; j++) {
        int x, y;
        long long w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    
    vector<long long> dist(n + 1, LLONG_MAX);
    dist[1] = a[0];
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    q.push({dist[1], 1});
    
    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        long long current_dist = p.first;
        int u = p.second;
        
        if (current_dist > dist[u]) continue;
        
        for (auto edge : adj[u]) {
            int v = edge.first;
            long long edge_weight = edge.second;
            long long new_dist = current_dist + edge_weight + a[v - 1];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                q.push({dist[v], v});
            }
        }
    }
    
    for (int i = 2; i <= n; i++) {
        cout << dist[i] << " ";
    }
    
    return 0;
}