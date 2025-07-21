#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<pair<int, long long>>> adj(n);
    
    for (int j = 0; j < m; ++j) {
        int x, y, w;
        cin >> x >> y >> w;
        // Adjust for 0-based indexing
        adj[x - 1].push_back({y - 1, w});
        adj[y - 1].push_back({x - 1, w});
    }
    
    vector<long long> dist(n, 1e18);
    dist[0] = a[0];
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({a[0], 0});
    
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        long long d = p.first;
        int v = p.second;
        
        if (d > dist[v]) continue;
        
        for (auto &u : adj[v]) {
            int to = u.first;
            long long weight = u.second;
            long long cost = d + weight + a[to];
            if (cost < dist[to]) {
                dist[to] = cost;
                pq.push({cost, to});
            }
        }
    }
    
    for (int i = 1; i < n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
    
    return 0;
}