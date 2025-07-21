#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int, int>> G[200005];
int dist[200005], dist2[200005], a[200005], n, m;

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    fill(dist, dist + n + 1, 1e18); // Use 1e18 for initialization to ensure any valid path will be shorter
    dist[start] = a[start];

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (currentDist > dist[u]) continue; // Skip if we have already found a shorter path

        for (auto [v, weight] : G[u]) {
            int nextDist = currentDist + weight + a[v];
            if (nextDist < dist[v]) {
                dist[v] = nextDist;
                pq.push({dist[v], v});
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
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    dijkstra(1);
    for (int i = 2; i <= n; ++i) {
        printf("%lld ", dist[i]);
    }
    printf("\n");
    return 0;
}