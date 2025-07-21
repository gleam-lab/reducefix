#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define INF LLONG_MAX

struct Edge {
    int to, cost;
};

class Graph {
public:
    vector<vector<Edge>> adjList;
    vector<long long> dist;
    vector<bool> visited;

    Graph(int n) : adjList(n), dist(n, INF), visited(n, false) {}

    void addEdge(int u, int v, int w) {
        adjList[u].emplace_back(v, w);
        adjList[v].emplace_back(u, w);
    }

    void dijkstra(int start) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, start});
        dist[start] = 0;

        while (!pq.empty()) {
            auto [dist_u, u] = pq.top(); pq.pop();
            if (visited[u]) continue;
            visited[u] = true;

            for (auto &[v, w] : adjList[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    vector<long long> getDistances() const {
        return dist;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Graph g(n);

    vector<long long> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v; // Convert to zero-based indexing
        g.addEdge(u, v, w);
    }

    g.dijkstra(0); // Start from vertex 1 (zero-based index)

    vector<long long> distances = g.getDistances();

    for (int i = 1; i < n; ++i) {
        cout << distances[i] + weights[i] << " ";
    }

    return 0;
}