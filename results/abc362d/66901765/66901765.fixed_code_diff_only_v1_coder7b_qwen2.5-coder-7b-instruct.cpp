#include<bits/stdc++.h>
using namespace std;
#define ll long long 
vector<pair<ll,ll>>G[200005];
ll dis[200005],a[200005],n,m;
bool vis[200005];

void dij(int s){
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0,s});
    dis[s] = 0;
    
    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        
        if (dist > dis[u]) continue; // Skip outdated distances
        
        for (auto &[v, w] : G[u]) {
            if (dis[u] + a[v] + w < dis[v]) {
                dis[v] = dis[u] + a[v] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

signed main() {
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++){
        ll u,v,w; scanf("%lld%lld%lld",&u,&v,&w);
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    memset(dis,0x3f3f3f3f,sizeof dis);
    dij(1);
    for(int i=2;i<=n;i++)
        printf("%lld ",dis[i]);
    return 0;
}