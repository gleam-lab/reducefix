#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int,int>> G[200005];
int dis[200005], dis2[200005], a[200005], n, m, vis[200005];

// Function to perform Dijkstra's algorithm to find shortest paths from source to all other nodes
void dijkstra(int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dis, dis + n + 1, INT_MAX);
    fill(vis, vis + n + 1, 0);
    dis[source] = a[source];
    pq.push({dis[source], source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;

        for (auto [v, w] : G[u]) {
            if (dis[v] > dis[u] + w + a[v]) {
                dis[v] = dis[u] + w + a[v];
                pq.push({dis[v], v});
            }
        }
    }
}

signed main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    // Perform Dijkstra's algorithm starting from vertex 1
    dijkstra(1);

    // Print the results for vertices 2 to n
    for (int i = 2; i <= n; i++) {
        printf("%lld ", dis[i]);
    }
    printf("\n");

    return 0;
}