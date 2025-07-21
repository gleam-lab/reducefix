#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int MAX_N = 200010; // Maximum number of vertices and edges

struct Edge {
    int to, weight;
};

vector<Edge> graph[MAX_N];
long long vertex_weights[MAX_N];
long long min_path_weights[MAX_N];

void dijkstra(int n) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.emplace(0, 1); // Start from vertex 1 with an initial cumulative weight of 0
    min_path_weights[1] = vertex_weights[1];

    while (!pq.empty()) {
        long long current_weight = pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        if (current_vertex > 1 && current_vertex < n) {
            min_path_weights[current_vertex] = current_weight + vertex_weights[current_vertex];
        }

        if (min_path_weights[current_vertex] != numeric_limits<long long>::max()) continue;

        for (const Edge& edge : graph[current_vertex]) {
            long long next_weight = current_weight + edge.weight;
            if (next_weight < min_path_weights[edge.to]) {
                min_path_weights[edge.to] = next_weight;
                pq.emplace(next_weight, edge.to);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> vertex_weights[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    dijkstra(n);

    cout << min_path_weights[2];
    for (int i = 3; i <= n; ++i) {
        cout << " " << min_path_weights[i];
    }
    cout << endl;

    return 0;
}