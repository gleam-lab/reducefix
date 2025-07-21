#include<bits/stdc++.h>
using namespace std;

const int INF = 1e18;

vector<pair<int, int>> G[200005];
int n, m;
long long dis[200005];

void dijkstra(int start) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    fill(dis, dis + n + 1, INF);
    dis[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();

        if (dist > dis[u]) continue;

        for (auto &[v, w] : G[u]) {
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    scanf("%lld %lld", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &dis[i]);
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    dijkstra(1);

    for (int i = 2; i <= n; i++) {
        printf("%lld ", dis[i]);
    }

    return 0;
}