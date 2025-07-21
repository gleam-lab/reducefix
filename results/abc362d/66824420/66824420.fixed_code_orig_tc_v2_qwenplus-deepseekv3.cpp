#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<long long> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    vector<vector<pair<int, long long>>> adj(n+1);
    for (int j = 0; j < m; j++) {
        int x, y;
        long long w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    
    const long long INF = 1e18;
    vector<long long> dist(n+1, INF);
    dist[1] = 0;
    
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        auto [current_dist, u] = pq.top();
        pq.pop();
        
        if (current_dist > dist[u]) continue;
        
        for (auto [v, w] : adj[u]) {
            long long new_dist = current_dist + w;
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({dist[v], v});
            }
        }
    }
    
    for (int i = 2; i <= n; i++) {
        cout << dist[i] + a[1] + a[i] << " ";
    }
    
    return 0;
}