#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = LLONG_MAX;

vector<pair<ll,ll>> G[200005];
ll dis[200005], a[200005], n, m;

void dijkstra(int start) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    fill(dis, dis + n + 1, INF);
    dis[start] = a[start];
    pq.push({dis[start], start});

    while (!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();
        if (cost > dis[u]) continue; // Skip outdated entries
        for (auto [v, w] : G[u]) {
            ll new_cost = cost + a[v] + w;
            if (new_cost < dis[v]) {
                dis[v] = new_cost;
                pq.push({dis[v], v});
            }
        }
    }
}

signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    memset(dis, 0xff, sizeof dis); // Initialize distance array to a large negative value
    dis[1] = a[1];
    dijkstra(1);

    for (int i = 2; i <= n; ++i) {
        printf("%lld ", dis[i]);
    }
    printf("\n");
    return 0;
}