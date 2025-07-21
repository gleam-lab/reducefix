#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18 + 7;

struct Edge {
    int to, w;
};

vector<Edge> G[200005];
ll dist[200005];

void dijkstra(int n, int src) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    memset(dist, INF, sizeof dist);
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue;

        for (auto &e : G[u]) {
            int v = e.to, w = e.w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) cin >> dist[i];

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    dijkstra(n, 1);

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    return 0;
}