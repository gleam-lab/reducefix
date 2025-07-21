#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int, int>> G[200005];
int dis[200005], a[200005], n, m;
void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto [v, w] : G[u]) {
            int nextDis = dis[u] + a[u] + w; // Consider both the vertex and edge weights
            if (nextDis < dis[v]) {
                dis[v] = nextDis;
                pq.push({dis[v], v});
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
        scanf("%lld%lld%lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    for (int i = 0; i <= n; i++) {
        dis[i] = 1e18; // Initialize distances with a large number
    }
    dis[1] = 0; // Start only from vertex 1
    dijkstra(1);
    for (int i = 2; i <= n; i++) {
        cout << dis[i] << (i < n ? ' ' : '\n');
    }
    return 0;
}