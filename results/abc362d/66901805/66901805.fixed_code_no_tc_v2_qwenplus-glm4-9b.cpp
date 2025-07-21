#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int, int>> G[200005];
int dist[200005], a[200005], n, m, vis[200005];

void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dist[src] = a[src];

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (vis[u]) continue;
        vis[u] = 1;

        for (auto &edge : G[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    memset(dist, 0x3f, sizeof(dist));
    dijkstra(1);

    for (int i = 2; i <= n; i++) {
        cout << dist[i] << (i < n ? " " : "\n");
    }
    return 0;
}