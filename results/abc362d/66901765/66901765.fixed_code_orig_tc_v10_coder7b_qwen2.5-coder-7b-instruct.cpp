#include<bits/stdc++.h>
using namespace std;

const int INF = 1e18;
const int MAXN = 2e5 + 10;

struct Edge {
    int v, w;
};

vector<Edge> G[MAXN];
long long dist[MAXN];

void dijkstra(int s) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    fill(dist, dist + MAXN, INF);
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (dist[u] != d) continue;

        for (auto &e : G[u]) {
            int v = e.v, w = e.w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    // Initialize distance array with INF except for starting node
    for (int i = 1; i <= n; ++i) {
        dist[i] = a[i];
    }

    // Run Dijkstra from each node to find the shortest path
    for (int i = 1; i <= n; ++i) {
        dijkstra(i);
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            dist[j] += a[j]; // Add vertex weight to get total path cost
        }
    }

    // Print results excluding the first element since it's always zero
    for (int i = 2; i <= n; ++i) {
        printf("%lld ", dist[i]);
    }
    printf("\n");

    return 0;
}