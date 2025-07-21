#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    
    vector<vector<pair<int, int>>> adj(n + 1);
    for(int j = 0; j < m; ++j){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    
    vector<long long> dist(n + 1, LLONG_MAX);
    dist[1] = a[0];
    
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.emplace(a[0], 1);
    
    while(!pq.empty()) {
        auto [cost, node] = pq.top(); pq.pop();
        
        // If we have already found a shorter path to this node, skip further processing
        if(cost > dist[node]) continue;
        
        for(const auto& [neighbor, weight] : adj[node]) {
            long long new_cost = cost + weight + a[neighbor - 1];
            
            // Update distance and push into queue if a shorter path is found
            if(new_cost < dist[neighbor]) {
                dist[neighbor] = new_cost;
                pq.emplace(new_cost, neighbor);
            }
        }
    }
    
    for(int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    
    return 0;
}