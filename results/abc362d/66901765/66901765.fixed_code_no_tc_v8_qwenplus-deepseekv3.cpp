#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int,int>>G[200005];
int dis[200005],a[200005],n,m;
bool vis[200005];

void dij(int u) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    dis[u] = a[u];
    q.push({dis[u], u});
    while(!q.empty()) {
        int u = q.top().second;
        int d = q.top().first;
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto [v,w] : G[u]) {
            if(dis[v] > d + a[v] + w) {
                dis[v] = d + a[v] + w;
                q.push({dis[v], v});
            }
        }
    }
}

signed main() {
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        dis[i] = LLONG_MAX;
    }
    for(int i=1;i<=m;i++) {
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    dij(1);
    for(int i=2;i<=n;i++) {
        printf("%lld ",dis[i]);
    }
    printf("\n");
    return 0;
}