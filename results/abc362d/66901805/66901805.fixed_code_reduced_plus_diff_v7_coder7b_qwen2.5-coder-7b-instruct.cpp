#include<bits/stdc++.h>
using namespace std;

const int INF = 1e18;
const int MAXN = 200005;

struct Edge {
    int v, w;
};

vector<Edge> G[MAXN];
int dis[MAXN], dis2[MAXN], a[MAXN], n, m, vis[MAXN];

void dijkstra(int s) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({a[s], s});
    memset(vis, 0, sizeof(vis));
    
    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        
        if (vis[u]) continue;
        vis[u] = 1;
        
        dis2[u] = dist;
        
        for (auto& [v, w] : G[u]) {
            long long newDist = dist + a[v] + w;
            if (newDist < dis[v]) {
                swap(newDist, dis[v]);
            }
            pq.push({newDist, v});
        }
    }
}

int main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    memset(dis, 0x3f, sizeof(dis));
    memset(dis2, 0x3f, sizeof(dis2));
    dis[1] = a[1];
    dis2[1] = 0;
    dijkstra(1);

    for (int i = 2; i <= n; ++i) {
        printf("%lld ", min(dis[i], dis2[i]));
    }
    return 0;
}