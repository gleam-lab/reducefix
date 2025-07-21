#include<bits/stdc++.h>
using namespace std;

const long long INF = numeric_limits<long long>::max();

vector<pair<int, int>> G[200005];
long long dis[200005], a[200005], n, m;
bool vis[200005];

void dij(int start) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({a[start], start});
    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        dis[u] = dist;
        for (auto [v, w] : G[u]) {
            if (!vis[v] && dis[v] > dis[u] + w + a[v]) {
                dis[v] = dis[u] + w + a[v];
                pq.push({dis[v], v});
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

    memset(vis, false, sizeof(vis));
    memset(dis, INF, sizeof(dis));
    dis[1] = a[1];
    dij(1);

    for (int i = 2; i <= n; i++) {
        printf("%lld ", dis[i] == INF ? INF : dis[i]);
    }
    printf("\n");

    return 0;
}