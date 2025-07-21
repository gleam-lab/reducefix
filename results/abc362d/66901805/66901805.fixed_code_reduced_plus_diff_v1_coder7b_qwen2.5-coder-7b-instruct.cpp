#include<bits/stdc++.h>
using namespace std;

#define int long long 
vector<pair<int, int>> G[200005];
int dis[200005], dis2[200005], a[200005], n, m, vis[200005];

struct Node {
    int dist, id;
    bool operator<(const Node& other) const {
        return dist > other.dist;
    }
};

void dijkstra(int start) {
    memset(vis, 0, sizeof(vis));
    priority_queue<Node> pq;
    pq.push({a[start], start});

    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;

        // If we have already processed this node before, skip further processing
        if (dis[u] != INT_MAX) continue;

        dis[u] = dist;

        for (auto [v, w] : G[u]) {
            if (!vis[v]) {
                pq.push({dis[u] + a[v] + w, v});
            }
        }
    }
}

signed main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    memset(dis, 0x3f, sizeof(dis));
    dis[1] = a[1];
    dijkstra(1);

    for (int i = 2; i <= n; i++) {
        printf("%lld ", dis[i]);
    }
    printf("\n");

    return 0;
}