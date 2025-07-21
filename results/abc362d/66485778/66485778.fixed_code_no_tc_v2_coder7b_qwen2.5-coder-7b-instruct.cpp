#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define INF 1LL<<60

typedef long long ll;

ll dist[MAXN];

void dijkstra(vector<pair<ll,ll>> adj[], ll src, ll n){
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    memset(dist, INF, sizeof dist);
    dist[src] = 0;
    pq.push({0, src});
    
    while(!pq.empty()){
        ll u = pq.top().second;
        ll du = pq.top().first;
        pq.pop();
        
        if(du > dist[u])
            continue;
        
        for(auto &v : adj[u]){
            ll dv = v.second + dist[u] + v.first;
            if(dv < dist[v.first]){
                dist[v.first] = dv;
                pq.push({dv, v.first});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<pair<ll,ll>> adj[n+1];
    for(int i = 1; i <= n; i++)
        cin >> dist[i];
    
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    
    dijkstra(adj, 1, n);
    
    for(int i = 2; i <= n; i++)
        cout << dist[i] << " ";
    
    return 0;
}