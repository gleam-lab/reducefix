#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll,ll>> G[200005];
ll dis[200005], dis2[200005], a[200005], n, m, vis[200005];

void dijkstra(int s) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, s});
    memset(vis, 0, sizeof(vis));
    
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        
        // If already visited or distance is larger than current known distance, skip
        if (vis[u]) continue;
        vis[u] = 1;
        
        // Update distance to u
        dis[u] = min(dis[u], d + a[u]);
        
        for (auto &[v, w] : G[u]) {
            if (!vis[v]) {
                pq.push({dis[u] + w, v});
            }
        }
    }
}

int main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        dis[i] = LLONG_MAX;
    }
    
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    // Start Dijkstra from vertex 1
    dijkstra(1);

    // Print results for vertices 2 to n
    for (int i = 2; i <= n; i++) {
        printf("%lld ", dis[i]);
    }
    return 0;
}