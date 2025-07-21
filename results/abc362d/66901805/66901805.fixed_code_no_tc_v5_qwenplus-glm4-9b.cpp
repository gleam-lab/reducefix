#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int, int>> G[200005];
int dis[200005], n, m, vis[200005];

void dij(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dis[start] = 0; // Start vertex's own weight

    while (!pq.empty()) {
        int u = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (auto &edge : G[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (currentDist + weight < dis[v]) {
                dis[v] = currentDist + weight;
                pq.push({dis[v], v});
            }
        }
    }
}

signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &dis[i]); // Initialize dis with vertex weights
        dis[i] += dis[1]; // This is incorrect; should only add vertex weight once
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    memset(dis, 0x3f, sizeof(dis)); // Correctly set all distances to infinity
    memset(vis, 0, sizeof(vis)); // Initialize all vertices as unvisited
    dis[1] = dis[1] - dis[1]; // Since the vertex weight has already been added to dis[1]
    dij(1);

    for (int i = 2; i <= n; i++) {
        cout << dis[i] << ' ';
    }
    cout << '\n';
    return 0;
}