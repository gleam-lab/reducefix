#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int,int>>G[200005];
int dis[200005],a[200005],n,m;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

void dij(int u){
    dis[u] = a[u];
    pq.push({dis[u], u});
    while(!pq.empty()){
        int u = pq.top().second;
        int current_dis = pq.top().first;
        pq.pop();
        if(current_dis > dis[u]) continue;
        for(auto [v,w]:G[u]){
            if(dis[v] > dis[u] + w + a[v]){
                dis[v] = dis[u] + w + a[v];
                pq.push({dis[v], v});
            }
        }
    }
}

signed main() {
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    memset(dis, 0x3f, sizeof dis);
    dij(1);
    for(int i=2;i<=n;i++){
        cout<<dis[i]<<' ';
    }
    cout<<"\n";
    return 0;
}