#include <bits/stdc++.h>
using namespace std;

#define INF 1e18
#define MAXN 200005

vector<pair<int, int>> G[MAXN]; // adjacency list for the graph
int n, m;
int dist[MAXN]; // to store shortest distances from source

void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    for (int i = 1; i <= n; ++i) dist[i] = INF;
    dist[src] = 0;

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist[u] < d) continue;

        for (auto &edge : G[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> dist[i]; // read vertex weights
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    dijkstra(1); // Dijkstra's algorithm from vertex 1

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] + dist[i] << ' '; // Output the shortest path distance plus the vertex weight
    }
    cout << '\n';

    return 0;
}