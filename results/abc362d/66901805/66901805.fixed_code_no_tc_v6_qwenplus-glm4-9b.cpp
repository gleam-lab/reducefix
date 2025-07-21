#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int, int>> G[200005];
int dis[200005], dis2[200005], a[200005], n, m;
int vis[200005];

void dijkstra(int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (vis[u]) continue;
        vis[u] = 1;
        
        for (auto &edge : G[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (current_dist + weight < dis[v]) {
                dis[v] = current_dist + weight;
                pq.push({dis[v], v});
            }
        }
    }
}

signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    
    memset(dis, 0x3f, sizeof(dis));
    memset(dis2, 0x3f, sizeof(dis2));
    dis[1] = a[1];
    dijkstra(1);
    
    for (int i = 2; i <= n; i++) {
        dis2[i] = min(dis[i], dis2[i] + a[i]);
    }
    
    for (int i = 2; i <= n; i++) {
        cout << dis2[i] << " ";
    }
    cout << "\n";
    
    return 0;
}