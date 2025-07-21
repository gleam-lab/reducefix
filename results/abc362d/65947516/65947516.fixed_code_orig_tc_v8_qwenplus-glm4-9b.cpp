#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int N = 200005;
vector<pair<int, int>> adj[N]; // adj[i] stores pairs (j, weight) indicating an edge from i to j
long long weights[N]; // weights[i] stores the weight of vertex i
long long dist[N]; // dist[i] stores the shortest path distance from vertex 1 to vertex i

// Priority queue to sort the nodes by their distance in increasing order
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

void dijkstra(int n) {
    dist[1] = weights[1];
    pq.push({dist[1], 1});

    while (!pq.empty()) {
        int u = pq.top().second;
        long long d = pq.top().first;
        pq.pop();

        if (dist[u] < d) continue;

        for (auto &p : adj[u]) {
            int v = p.first;
            long long weight = p.second;
            long long new_dist = d + weights[v] + weight;

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> weights[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    dijkstra(n);

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }

    return 0;
}