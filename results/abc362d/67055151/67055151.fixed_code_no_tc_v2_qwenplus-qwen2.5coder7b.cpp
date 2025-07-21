#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int to, cost;
    Edge(int t, int c) : to(t), cost(c) {}
};

void dijkstra(const vector<vector<Edge>>& graph, int start, vector<int>& dist) {
    dist.resize(graph.size(), numeric_limits<int>::max());
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.cost;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v; // Convert to 0-based index
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    vector<int> distances(n);
    dijkstra(graph, 0, distances);

    for (int i = 1; i < n; ++i) {
        cout << distances[i] << ' ';
    }
    cout << endl;

    return 0;
}