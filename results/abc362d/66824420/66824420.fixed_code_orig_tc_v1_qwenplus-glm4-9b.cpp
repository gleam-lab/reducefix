#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    for (int i = 2; i <= n; i++) {
        vector<long long> dist(n + 1, 1e10 + 1);
        dist[i] = 0; // Start from vertex 1
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        q.push({0, 1}); // vertex, current distance
        
        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            long long d = p.first, node = p.second;
            
            for (auto &it : adj[node]) {
                int nextNode = it.first;
                long long nextDist = d + it.second + a[nextNode - 1];
                if (nextDist < dist[nextNode]) {
                    dist[nextNode] = nextDist;
                    q.push({nextDist, nextNode});
                }
            }
        }
        
        cout << dist[i] << " ";
    }
    
    return 0;
}