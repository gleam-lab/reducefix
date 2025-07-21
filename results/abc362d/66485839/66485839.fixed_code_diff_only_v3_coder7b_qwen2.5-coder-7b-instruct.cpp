#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define INF LLONG_MAX
#define all(x) x.begin(), x.end()

typedef pair<ll, ll> pll;

vector<pll> adj[200005];
ll dist[200005];

void dijkstra(int src, int n) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    fill(dist, dist+n+1, INF);
    dist[src] = 0;
    pq.push({0, src});
    
    while(!pq.empty()) {
        ll u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();
        
        if(d > dist[u]) continue;
        
        for(auto v : adj[u]) {
            ll child = v.first;
            ll wt = v.second;
            
            if(dist[u] + wt < dist[child]) {
                dist[child] = dist[u] + wt;
                pq.push({dist[child], child});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<ll> a(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];
    
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    dijkstra(1, n);
    
    for(int i=2; i<=n; i++) cout << dist[i] + a[i] << " ";
    
    return 0;
}