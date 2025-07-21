#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int INF = LLONG_MAX / 2;

vector<pair<int,int>> G[200005];
int dis[200005], a[200005], n, m;

void dijkstra(int s) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    fill(dis, dis + n + 1, INF);
    dis[s] = a[s];
    pq.push({dis[s], s});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dis[u]) continue; // Skip outdated entries

        for (auto [v, w] : G[u]) {
            long long nd = d + a[v] + w;
            if (nd < dis[v]) {
                dis[v] = nd;
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
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    dijkstra(1);

    for (int i = 2; i <= n; i++) {
        printf("%lld ", dis[i]);
    }
    printf("\n");

    return 0;
}