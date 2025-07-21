#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<pair<int, int>> G[200005];
int dis[200005];
int a[200005];
int n, m;

void dijkstra(int u) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[u] = a[u];
    pq.push({dis[u], u});
    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();
        if (current_dist > dis[current_node]) continue;
        for (auto [v, w] : G[current_node]) {
            if (dis[v] > dis[current_node] + w + a[v]) {
                dis[v] = dis[current_node] + w + a[v];
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
    const int INF = 1LL << 60;
    for (int i = 1; i <= n; i++) {
        dis[i] = INF;
    }
    dijkstra(1);
    for (int i = 2; i <= n; i++) {
        printf("%lld ", dis[i]);
    }
    printf("\n");
    return 0;
}