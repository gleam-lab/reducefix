#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int to, weight;
};

int n, m;
vector<Edge> graph[200001];

void dijkstra(int source) {
    vector<long long> dist(n + 1, 1e18);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    pq.push({0, source});
    dist[source] = 0;

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if (dist[node] < d) continue;

        for (auto& e : graph[node]) {
            long long nextDist = dist[node] + e.weight;
            if (nextDist < dist[e.to]) {
                dist[e.to] = nextDist;
                pq.push({nextDist, e.to});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << (i == n ? "" : " ");
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> graph[i].front().weight;
    }

    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    dijkstra(1);

    return 0;
}