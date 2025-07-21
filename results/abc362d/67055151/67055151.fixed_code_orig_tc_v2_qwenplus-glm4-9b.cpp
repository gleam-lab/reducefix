#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> vertex_weights(n + 1);
    vector<int> dist(n + 1, INF);

    for (int i = 1; i <= n; i++) {
        cin >> vertex_weights[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v, b;
        cin >> u >> v >> b;
        graph[u].emplace_back(v, b);
        graph[v].emplace_back(u, b);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, 1);
    dist[1] = 0;

    while (!pq.empty()) {
        int current = pq.top().second;
        int current_weight = pq.top().first;
        pq.pop();

        if (current_weight > dist[current]) continue;

        for (auto& edge : graph[current]) {
            int next_vertex = edge.first;
            int weight = edge.second;

            int new_weight = current_weight + weight + vertex_weights[next_vertex];
            if (new_weight < dist[next_vertex]) {
                dist[next_vertex] = new_weight;
                pq.emplace(new_weight, next_vertex);
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}