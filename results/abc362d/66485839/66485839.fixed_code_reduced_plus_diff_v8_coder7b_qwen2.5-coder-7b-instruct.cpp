#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define INF 1e18

struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

void dijkstra(int src, vector<pair<int, int>> adj[], vector<LL> &dist) {
    priority_queue<pair<int, LL>, vector<pair<int, LL>>, greater<pair<int, LL>>> pq;
    dist[src] = 0;
    pq.push({src, 0});
    
    while (!pq.empty()) {
        int u = pq.top().first;
        LL d = pq.top().second;
        pq.pop();
        
        if (d > dist[u])
            continue;
        
        for (auto &e : adj[u]) {
            int v = e.first;
            LL w = e.second;
            
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({v, dist[v]});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<vector<pair<int, int>>> adj(n + 1);
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }
    
    vector<LL> dist(n + 1, INF);
    dijkstra(1, adj, dist);
    
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] + a[i] << " ";
    }
    cout << endl;
    
    return 0;
}