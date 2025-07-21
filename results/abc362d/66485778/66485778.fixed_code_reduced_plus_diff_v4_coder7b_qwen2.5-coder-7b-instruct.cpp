#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v, w;
};

const int MAXN = 200005;
const int INF = 1e18;

vector<Edge> adj[MAXN];
long long dist[MAXN];

void dijkstra(int src, int n) {
    fill(dist, dist + n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    
    dist[src] = 0;
    pq.push({dist[src], src});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        for (auto &edge : adj[u]) {
            int v = edge.v;
            long long w = edge.w;
            
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
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
        cout << dist[i] << " ";
    }
    cout << "\n";
    
    return 0;
}