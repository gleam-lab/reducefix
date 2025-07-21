#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int dist[N];

struct Edge {
    int from, to, weight;
};

void dijkstra(int n, vector<Edge>& edges) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1}); // start from vertex 1 with initial distance 0
    fill(dist, dist + n + 1, 1e9); // set initial distances to infinity
    dist[1] = 0; // distance from node 1 to itself is 0

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& edge : edges) {
            int v = edge.to;
            int weight = edge.weight;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    edges.resize(m);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    dijkstra(n, edges);

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << (i < n ? " " : "");
    }

    return 0;
}