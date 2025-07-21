#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int,int>>G[200005];
int dis[200005], a[200005], n, m;

void dij(int u) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({a[u], u});
    dis[u] = a[u];
    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(d > dis[u]) continue;
        for(auto [v, w] : G[u]) {
            if(dis[v] > dis[u] + a[v] + w) {
                dis[v] = dis[u] + a[v] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

signed main() {
    scanf("%lld%lld", &n, &m);
    for(int i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
    }
    for(int i=1; i<=m; i++) {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    fill(dis, dis+n+1, LLONG_MAX);
    dij(1);
    for(int i=2; i<=n; i++) {
        printf("%lld ", dis[i]);
    }
    printf("\n");
    return 0;
}