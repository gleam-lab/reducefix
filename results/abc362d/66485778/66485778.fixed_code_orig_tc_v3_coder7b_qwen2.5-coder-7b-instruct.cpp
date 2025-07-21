#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define INF LLONG_MAX

struct Edge {
    int v, w;
};

vector<Edge> adj[100001];

void dijkstra(int n, int src, vector<LL>& dist) {
    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> pq;
    
    dist[src] = 0;
    pq.push({0, src});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        LL d = pq.top().first;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& edge : adj[u]) {
            int v = edge.v;
            LL w = edge.w;
            
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
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
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vector<LL> dist(n + 1, INF);
    
    dijkstra(n, 1, dist);
    
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] + a[i] << " ";
    }
    cout << endl;
    
    return 0;
}