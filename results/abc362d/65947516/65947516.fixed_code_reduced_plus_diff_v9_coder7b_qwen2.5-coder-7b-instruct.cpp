#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define INF LLONG_MAX

typedef long long ll;
typedef pair<ll,ll> pll;

vector<pll> g[MAXN];
ll dist[MAXN];

void dijkstra(int start){
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    memset(dist,INF,sizeof(dist));
    dist[start] = 0;
    pq.push({0,start});

    while(!pq.empty()){
        auto [d,node] = pq.top(); pq.pop();

        if(d > dist[node]) continue;

        for(auto &[neigh,weight]: g[node]){
            ll ndist = d + weight + a[neigh];
            if(ndist < dist[neigh]){
                dist[neigh] = ndist;
                pq.push({ndist,neigh});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,m; cin >> n >> m;
    vector<ll> a(n+1);
    for(int i=1; i<=n; ++i) cin >> a[i];

    for(int i=1; i<=m; ++i){
        int u,v,b; cin >> u >> v >> b;
        g[u].push_back({v,b});
        g[v].push_back({u,b});
    }

    dijkstra(1);

    for(int i=2; i<=n; ++i){
        cout << dist[i] + a[i] << " ";
    }

    return 0;
}