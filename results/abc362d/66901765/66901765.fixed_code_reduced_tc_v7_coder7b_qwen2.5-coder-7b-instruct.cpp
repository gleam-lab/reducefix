#include<bits/stdc++.h>
using namespace std;

const int INF = LLONG_MAX / 2;

vector<pair<int, int>> G[200005];
long long dis[200005], a[200005], n, m;

void dijkstra(int start) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    fill(dis, dis + n + 1, INF);
    dis[start] = a[start];
    pq.push({dis[start], start});

    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();

        if (dist > dis[u]) continue;

        for (auto [v, w] : G[u]) {
            long long new_dist = dist + a[v] + w;
            if (new_dist < dis[v]) {
                dis[v] = new_dist;
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

    dijkstra(1);

    for (int i = 2; i <= n; i++) {
        printf("%lld ", dis[i]);
    }
    printf("\n");

    return 0;
}