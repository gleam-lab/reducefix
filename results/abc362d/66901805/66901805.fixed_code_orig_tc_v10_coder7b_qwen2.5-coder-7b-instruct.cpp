#include<bits/stdc++.h>
using namespace std;

#define int long long

struct Edge {
    int v, w;
};

vector<Edge> G[200005];
int dis[200005], dis2[200005], a[200005], n, m, vis[200005];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    memset(dis, 0x3f, sizeof(dis));
    dis[start] = a[start];
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dis[u]) continue;
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto &e : G[u]) {
            int v = e.v, w = e.w;
            dis[v] = min(dis[v], d + a[v] + w);
            pq.push({dis[v], v});
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

    dijkstra(1);

    for (int i = 2; i <= n; i++) {
        printf("%lld ", dis[i]);
    }
    printf("\n");

    return 0;
}