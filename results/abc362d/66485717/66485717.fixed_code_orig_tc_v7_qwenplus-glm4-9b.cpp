#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAX_N = 200000;
vector<pair<int, int>> graph[MAX_N + 1]; // pair<neighbor, edge_weight>
int vertex_weights[MAX_N + 1];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
    vector<int> min_distance(MAX_N + 1, INT_MAX);
    min_heap.push({0, start}); // {distance, vertex}
    min_distance[start] = 0;

    while (!min_heap.empty()) {
        int dist = min_heap.top().first;
        int u = min_heap.top().second;
        min_heap.pop();

        if (min_distance[u] < dist) continue;

        for (auto& [v, weight] : graph[u]) {
            int new_dist = dist + weight + vertex_weights[v];
            if (min_distance[v] > new_dist) {
                min_distance[v] = new_dist;
                min_heap.push({new_dist, v});
            }
        }
    }

    // Output the minimum distances for vertices 2 through N
    for (int i = 2; i <= MAX_N; ++i) {
        if (min_distance[i] != INT_MAX) {
            cout << min_distance[i] << " ";
        } else {
            cout << "-1 "; // If vertex i is unreachable
        }
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Input vertex weights
    for (int i = 1; i <= n; ++i) {
        cin >> vertex_weights[i];
    }

    // Input edges
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    // Run Dijkstra from vertex 1 (assuming 1-based indexing)
    dijkstra(1);

    return 0;
}