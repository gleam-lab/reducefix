#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
const ll INF = 1e18;

struct Edge {
    int v, w;
};

vector<Edge> adj[N];
ll dist[N];

void dijkstra(int n, int start) {
    fill(dist, dist + n + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();
        
        if (d > dist[u])
            continue;
        
        for (auto &e : adj[u]) {
            int v = e.v;
            ll w = e.w;
            
            if (dist[u] + w + min(a[u], a[v]) < dist[v]) {
                dist[v] = dist[u] + w + min(a[u], a[v]);
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    dijkstra(n, 1);
    
    for (int i = 2; i <= n; ++i)
        cout << dist[i] << " ";
    
    return 0;
}