#include<bits/stdc++.h>
using namespace std;

typedef pair<long long, pair<int, int>> pi;

vector<vector<pi>> adj;
long long n, m;
vector<long long> dist, dist2;

void dijkstra(int start) {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({dist[start], {start, 0}});
    
    while (!pq.empty()) {
        auto [cost, node] = pq.top(); pq.pop();
        int u = node.first, prev_cost = node.second;
        
        if (prev_cost != dist2[u]) continue;
        
        for (auto &[v, w] : adj[u]) {
            long long new_cost = cost + dist[v] + w;
            
            if (new_cost < dist2[v]) {
                dist2[v] = new_cost;
                pq.push({new_cost, {v, dist2[v]}});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    dist.resize(n + 1, LLONG_MAX);
    dist2.resize(n + 1, LLONG_MAX);
    
    for (int i = 1; i <= n; ++i) {
        cin >> dist[i];
    }
    
    adj.resize(n + 1);
    
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    dist[1] = 0;
    dist2[1] = 0;
    
    dijkstra(1);
    
    for (int i = 2; i <= n; ++i) {
        cout << dist2[i] << " ";
    }
    
    return 0;
}