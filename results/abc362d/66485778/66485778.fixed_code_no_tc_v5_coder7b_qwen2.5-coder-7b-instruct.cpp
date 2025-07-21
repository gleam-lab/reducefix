#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define INF 1e18
#define MAXN 2e5 + 7

typedef pair<LL, LL> pll;

vector<vector<pll>> adj(MAXN);
LL dist[MAXN];

void dijkstra(int src, int n) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    fill(dist, dist + n + 1, INF);
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w + v < dist[v]) {
                dist[v] = dist[u] + w + v;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> dist[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra(1, n);

    for (int i = 2; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}