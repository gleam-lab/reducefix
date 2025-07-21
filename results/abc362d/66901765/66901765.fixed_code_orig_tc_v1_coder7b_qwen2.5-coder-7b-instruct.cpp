#include<bits/stdc++.h>
using namespace std;

const int INF = INT_MAX / 2;

struct Edge {
    int to, w;
};

vector<Edge> adj[200005];
int n, m, d[200005];

void dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(d, d + n + 1, INF);
    d[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        if (d[u] != dist) continue;

        for (auto& e : adj[u]) {
            int v = e.to, w = e.w;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra(1);

    for (int i = 2; i <= n; ++i) {
        printf("%lld ", d[i] + a[i]);
    }
    return 0;
}