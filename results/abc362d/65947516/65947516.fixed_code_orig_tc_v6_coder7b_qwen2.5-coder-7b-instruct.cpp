#include <iostream>
#include <vector>
#include <queue>
#include <limits>

#define INF std::numeric_limits<long long>::max()

struct Edge {
    int to, weight;
};

std::vector<Edge> adj[200005];
long long dist[200005];

void dijkstra(int start, int n) {
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        auto [current_dist, u] = pq.top(); pq.pop();

        if (current_dist > dist[u]) continue;

        for (auto &edge : adj[u]) {
            int v = edge.to;
            long long new_dist = current_dist + edge.weight + dist[u];

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        std::cin >> dist[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    dijkstra(1, n);

    for (int i = 2; i <= n; ++i) {
        std::cout << dist[i] + dist[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}