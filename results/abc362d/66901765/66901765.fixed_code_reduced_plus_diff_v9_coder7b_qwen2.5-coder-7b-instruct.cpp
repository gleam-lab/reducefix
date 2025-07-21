#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int,int>>G[200005];
int dis[200005],a[200005],n,m;

void dij(int s){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    fill(dis, dis + n + 1, LLONG_MAX); // Initialize distances to infinity
    dis[s] = a[s]; // Distance to source is its own value
    pq.push({dis[s], s});
    
    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        if (dist > dis[u]) continue; // Skip outdated entries
        
        for (auto [v, w] : G[u]) {
            if (dis[u] + w + a[v] < dis[v]) {
                dis[v] = dis[u] + w + a[v];
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
    
    dij(1); // Start Dijkstra from vertex 1
    
    for (int i = 2; i <= n; i++) {
        printf("%lld ", dis[i]);
    }
    cout << "\n";
    return 0;
}