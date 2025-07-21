#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define vvi vector<vi>

struct DSU {
    vi parent, rank;
    DSU(ll n) : parent(n+1), rank(n+1, 1) {
        for(ll i=1;i<=n;i++) parent[i]=i;
    }
    
    ll find(ll u){
        if(u!=parent[u]) parent[u] = find(parent[u]);
        return parent[u];
    }
    
    void merge(ll u, ll v){
        ll pu=find(u), pv=find(v);
        if(pu==pv) return;
        
        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
            rank[pu]+=rank[pv];
        } else {
            parent[pu]=pv;
            rank[pv]+=rank[pu];
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll n,m; cin >> n >> m;
    vi a(n+1), dist(n+1, LLONG_MAX);
    vvi adj(n+1);
    for(ll i=1;i<=n;i++) cin >> a[i];

    for(ll i=0;i<m;i++){
        ll u,v,c; cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({a[1], 1});

    while(!pq.empty()){
        auto [cost, node] = pq.top(); pq.pop();

        if(cost > dist[node]) continue;

        for(auto &child : adj[node]){
            ll child_node = child.first, child_cost = child.second;
            if(dist[child_node] > cost + child_cost + a[child_node]){
                dist[child_node] = cost + child_cost + a[child_node];
                pq.push({dist[child_node], child_node});
            }
        }
    }

    for(ll i=2;i<=n;i++){
        cout << dist[i] << " ";
    }
    return 0;
}