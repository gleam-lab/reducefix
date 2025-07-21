#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int,int>>G[200005];
int dis[200005],a[200005],n,m,vis[200005];

void dij(int u, int dist[], vector<pair<int, int>>& edges){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, u});
    while (!pq.empty()) {
        int d = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if (vis[v]) continue;
        vis[v] = 1;
        for (auto [nextV, weight] : edges[v]) {
            if (dist[nextV] > d + a[nextV] + weight) {
                dist[nextV] = d + a[nextV] + weight;
                pq.push({dist[nextV], nextV});
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
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    memset(dis, 0x3f, sizeof dis);
    vector<pair<int, int>> edges(n+1);
    for (int i = 1; i <= n; i++) {
        edges[i].push_back({0, a[i]});
        for (auto [next, w] : G[i]) {
            edges[i].push_back({next, w});
        }
    }
    dis[1] = a[1];
    dij(1, dis, edges);
    for(int i=2;i<=n;i++){
        cout<<dis[i]<<' ';
    }
    cout<<"\n";
    return 0;
}