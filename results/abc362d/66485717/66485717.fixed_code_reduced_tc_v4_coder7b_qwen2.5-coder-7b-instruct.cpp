#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define INF 1LL << 60

struct Node {
    int id;
    LL dist;
    bool operator<(const Node &other) const { return dist > other.dist; }
};

vector<pair<int, int>> adj[200010];
LL dist[200010];

void dijkstra(int src, int n) {
    priority_queue<Node> pq;
    pq.push({src, dist[src] = 0});
    
    while (!pq.empty()) {
        auto [u, du] = pq.top(); pq.pop();
        
        if (du > dist[u]) continue;
        
        for (auto &[v, dv] : adj[u]) {
            LL ndist = du + dv + dist[v];
            
            if (ndist < dist[v]) {
                dist[v] = ndist;
                pq.push({v, ndist});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) {
        cin >> dist[i];
    }
    
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    dijkstra(1, n);
    
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << (i == n ? '\n' : ' ');
    }
    
    return 0;
}