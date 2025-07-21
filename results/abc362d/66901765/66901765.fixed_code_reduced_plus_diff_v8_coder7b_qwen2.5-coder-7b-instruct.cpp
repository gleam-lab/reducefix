#include<bits/stdc++.h>
using namespace std;

const int INF = 1e18;

struct Edge {
    int v, w;
};

vector<Edge> G[200005];
int dis[200005], a[200005], n, m, vis[200005];

void dij(int s) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    fill(dis, dis + n + 1, INF);
    dis[s] = a[s];
    pq.push({dis[s], s});

    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        if (dist > dis[u]) continue;
        for (auto [v, w] : G[u]) {
            if (dis[v] > dist + w + a[v]) {
                dis[v] = dist + w + a[v];
                pq.push({dis[v], v});
            }
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
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    memset(vis, 0, sizeof vis);
    dij(1);

    for (int i = 2; i <= n; ++i) {
        printf("%lld ", dis[i]);
    }
    return 0;
}