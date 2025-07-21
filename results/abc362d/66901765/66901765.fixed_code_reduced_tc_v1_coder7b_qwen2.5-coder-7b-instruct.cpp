#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int INF = numeric_limits<long long>::max();
vector<pair<int,int>>G[200005];
int dis[200005],a[200005],n,m;
void dij(int s){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    memset(dis, 0x3f, sizeof dis);
    dis[s] = a[s];
    q.push({dis[s], s});
    while(!q.empty()){
        auto [dist, u] = q.top(); q.pop();
        if(dist > dis[u]) continue;
        for(auto [v, w]: G[u]){
            if(dis[v] > dis[u] + a[v] + w){
                dis[v] = dis[u] + a[v] + w;
                q.push({dis[v], v});
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
    dij(1);
    for(int i=2;i<=n;i++){
        printf("%lld ", dis[i]);
    }
    printf("\n");
    return 0;
}