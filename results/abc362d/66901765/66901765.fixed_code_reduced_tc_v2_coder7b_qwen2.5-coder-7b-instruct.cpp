#include<bits/stdc++.h>
using namespace std;
#define ll long long 
vector<pair<ll,ll>>G[200005];
ll dis[200005],a[200005],n,m;
void dij(){
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();
        if(d > dis[u]) continue;
        for(auto [v, w]: G[u]){
            if(dis[v] > d + a[v] + w){
                dis[v] = d + a[v] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

signed main() {
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    memset(dis,0x3f,sizeof dis);
    dis[1]=a[1];
    dij();
    for(int i=2;i<=n;i++){
        cout<<dis[i]<<' ';
    }
    cout<<"\n";
    return 0;
}