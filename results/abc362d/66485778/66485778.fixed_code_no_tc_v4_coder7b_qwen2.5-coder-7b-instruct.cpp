#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>

const int N = 2e5 + 7;
const int INF = 1e18;

vector<pii> adj[N];
vector<int> dist(N);

void dijkstra(int src, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist.begin(), dist.end(), INF);
    dist[src] = 0;
    pq.push({0, src});
    
    while (!pq.empty()) {
        auto [u_dist, u] = pq.top();
        pq.pop();
        
        if (u_dist > dist[u]) continue;
        
        for (auto &[v, w] : adj[u]) {
            int v_dist = u_dist + w + dist[v];
            
            if (v_dist < dist[v]) {
                dist[v] = v_dist;
                pq.push({v_dist, v});
            }
        }
    }
}

signed main() {
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
    
    dijkstra(1, n);
    
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    
    return 0;
}