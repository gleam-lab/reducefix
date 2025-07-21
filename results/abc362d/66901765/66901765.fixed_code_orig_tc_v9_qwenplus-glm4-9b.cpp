#include <bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int, int>> G[200005];
int dist[200005];
int n, m;
void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto& [v, w] : G[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

signed main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &dist[i]); // dist is now initialized to the vertex weights
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    dijkstra(1); // Call dijkstra for vertex 1
    for (int i = 2; i <= n; i++) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
    return 0;
}