#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF LLONG_MAX

vector<pair<int, int>> G[200005];  // Graph adjacency list
int dist[200005], vertex_weights[200005], n, m;

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});  // Push initial position with 0 distance
    dist[start] = vertex_weights[start];  // Set the distance of the start node to its own weight

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist[u] < current_dist) continue;  // Skip if we have already found a shorter path

        for (auto &edge : G[u]) {
            int v = edge.first;
            int weight = edge.second;
            int new_dist = dist[u] + weight;
            if (new_dist < dist[v]) {  // If a shorter path to v is found
                dist[v] = new_dist;
                pq.push({dist[v], v});
            }
        }
    }
}

signed main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &vertex_weights[i]);  // Read the weight of each vertex
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    for (int i = 2; i <= n; ++i) {
        dist[i] = INF;  // Initialize distances to INF
    }
    dijkstra(1);  // Run Dijkstra's algorithm from vertex 1

    for (int i = 2; i <= n; ++i) {
        printf("%lld ", dist[i]);
    }
    printf("\n");

    return 0;
}