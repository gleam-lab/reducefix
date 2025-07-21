#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 10;
const ll INF = 1e18;

struct Edge {
    int v, w;
};

vector<Edge> adj[MAXN];
ll dist[MAXN];

void dijkstra(int n, int src) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    fill(dist, dist + n + 1, INF);
    dist[src] = 0;
    pq.push({0, src});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        ll du = pq.top().first;
        pq.pop();
        
        if (du > dist[u]) continue;
        
        for (auto &e : adj[u]) {
            int v = e.v;
            ll dv = du + e.w;
            
            if (dv < dist[v]) {
                dist[v] = dv;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
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
    
    dijkstra(n, 1);
    
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";
    
    return 0;
}