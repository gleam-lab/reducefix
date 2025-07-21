#include<bits/stdc++.h>
using namespace std;
#define int long long 
using pii = pair<int, int>;

vector<pii> G[200005];
int dis[200005];
int a[200005];
int n, m;

void dij(int u) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[u] = a[u];
    pq.push({dis[u], u});
    
    while (!pq.empty()) {
        int u_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (u_dist > dis[u]) continue;
        
        for (auto [v, w] : G[u]) {
            if (dis[v] > dis[u] + a[v] + w) {
                dis[v] = dis[u] + a[v] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    
    memset(dis, 0x3f, sizeof dis);
    dis[1] = a[1];
    dij(1);
    
    for (int i = 2; i <= n; i++) {
        printf("%lld ", dis[i]);
    }
    printf("\n");
    
    return 0;
}