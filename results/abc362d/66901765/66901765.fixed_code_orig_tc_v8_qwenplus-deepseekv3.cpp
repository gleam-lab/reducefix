#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int,int>> G[200005];
int dis[200005], a[200005], n, m;

void dij(int u) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({a[u], u});
    dis[u] = a[u];
    
    while(!q.empty()) {
        int cost = q.top().first;
        int u = q.top().second;
        q.pop();
        
        if(cost > dis[u]) continue;
        
        for(auto [v, w]: G[u]) {
            int new_cost = cost + w + a[v];
            if(new_cost < dis[v]) {
                dis[v] = new_cost;
                q.push({dis[v], v});
            }
        }
    }
}

signed main() {
    scanf("%lld%lld", &n, &m);
    for(int i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
        dis[i] = LLONG_MAX;
    }
    
    for(int i=1; i<=m; i++) {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    
    dij(1);
    
    for(int i=2; i<=n; i++) {
        printf("%lld ", dis[i]);
    }
    printf("\n");
    return 0;
}