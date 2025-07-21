#include <bits/stdc++.h>
using namespace std;

#define INF 1e18

struct Edge {
    int v, w;
};

vector<Edge> adj[200001];

void dijkstra(int n, int src, vector<long long>& dist) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    dist[src] = 0;
    pq.push({0, src});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        long long d = pq.top().first;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& e : adj[u]) {
            int v = e.v;
            long long w = e.w;
            
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    vector<long long> a(n + 1), dist(n + 1, INF);
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }
    
    dijkstra(n, 1, dist);
    
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] + a[i] << " ";
    }
    cout << "\n";
    
    return 0;
}