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
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(current_dist > dis[u]) continue;
        for(auto [v, w]: G[u]){
            int new_dist = dis[u] + a[v] + w;
            if(new_dist < dis[v]){
                dis[v] = new_dist;
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
    for(int i=1;i<=n;i++){
        dis[i] = LLONG_MAX;
    }
    dij(1);
    for(int i=2;i<=n;i++){
        if(dis[i] == LLONG_MAX){
            printf("9223372036854775807 ");
        } else {
            printf("%lld ", dis[i]);
        }
    }
    printf("\n");
    return 0;
}