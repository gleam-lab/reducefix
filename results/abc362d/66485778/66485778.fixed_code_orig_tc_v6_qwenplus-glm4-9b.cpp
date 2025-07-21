#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to, weight;
};

using AdjList = vector<vector<Edge>>;

void dijkstra(const AdjList& graph, vector<int>& dist, int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    dist[source] = 0;

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        if (current_dist > dist[current_vertex]) continue;

        for (const auto& [to, weight] : graph[current_vertex]) {
            int new_dist = current_dist + weight + graph[to][source].weight;
            if (new_dist < dist[to]) {
                dist[to] = new_dist;
                pq.push({new_dist, to});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    AdjList graph(n + 1);
    vector<int> vertex_weights(n + 1);
    
    for (int i = 1; i <= n; ++i) {
        cin >> vertex_weights[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    vector<int> dist(n + 1, INT_MAX);
    dijkstra(graph, dist, 1);

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }

    return 0;
}