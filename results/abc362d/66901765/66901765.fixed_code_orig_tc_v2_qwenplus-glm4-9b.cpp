#include<bits/stdc++.h>
using namespace std;
#define int long long 

vector<pair<int, int>> G[200005];

int dis[200005];
int a[200005];
int n, m;

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});  // Use a max-heap to get the minimum distance in O(log N) time.
    dis[1] = a[1];   // The distance to the starting vertex is its weight.

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (dis[u] < 0) continue;  // If the vertex has already been visited, skip it.

        for (auto &edge : G[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dis[u] + weight < dis[v]) {  // Relax the edge if it gives a shorter path.
                dis[v] = dis[u] + weight;
                pq.push({dis[v], v});
            }
        }
    }
}

signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dis[i] = -1;  // Initialize distances with -1 (unvisited).
    }
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    dijkstra();

    for (int i = 2; i <= n; i++) {
        cout << dis[i] << (i == n ? "\n" : " ");
    }

    return 0;
}