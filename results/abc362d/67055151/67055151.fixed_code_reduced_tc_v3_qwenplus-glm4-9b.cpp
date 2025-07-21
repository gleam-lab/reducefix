#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = 1e9; // A large number to represent infinity

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> vertex_weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> vertex_weights[i];
    }

    vector<vector<pair<int, long long>>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        // Adjust 1-based index to 0-based
        graph[u - 1].push_back({v - 1, b});
        graph[v - 1].push_back({u - 1, b});
    }

    // Distance array, initialized to infinity
    vector<long long> dist(n, INF);

    // Priority queue to pick the next vertex with the smallest distance
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    // Start from vertex 0 (1 in 1-based index)
    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [current_dist, current_vertex] = pq.top();
        pq.pop();

        // If the popped vertex has a distance greater than the current recorded, skip it
        if (current_dist > dist[current_vertex]) {
            continue;
        }

        // Explore the neighbors of the current vertex
        for (auto& [neighbor, edge_weight] : graph[current_vertex]) {
            long long new_dist = current_dist + edge_weight + vertex_weights[neighbor];
            // If the new distance is shorter, update and push it to the priority queue
            if (new_dist < dist[neighbor]) {
                dist[neighbor] = new_dist;
                pq.push({new_dist, neighbor});
            }
        }
    }

    // Output the minimum weight of paths from vertex 1 to all other vertices (1-based index)
    for (int i = 1; i < n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}