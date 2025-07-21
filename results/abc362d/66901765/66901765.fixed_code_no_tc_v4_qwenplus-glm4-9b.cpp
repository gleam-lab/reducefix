#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int,pair<int, int>>>G[200005]; // modified edge vector to store both vertex and edge weight
int dis[200005], n, m;

// Dijkstra's algorithm with a priority queue to find the shortest path
void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    fill(dis, dis + n + 1, LLONG_MAX);
    dis[src] = 0;

    while (!pq.empty()) {
        int current_weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for (auto &edge : G[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (current_weight + weight < dis[v]) {
                dis[v] = current_weight + weight;
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &dis[i]); // read vertex weights and initialize distance array
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    dijkstra(1); // run Dijkstra's algorithm from vertex 1

    for (int i = 2; i <= n; i++) {
        printf("%lld ", dis[i]); // output the minimum distance to each vertex from 1, excluding vertex 1
    }
    printf("\n");
    return 0;
}