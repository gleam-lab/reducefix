#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int MAX_N = 200001;
const long long INF = (long long)1e18;

vector<pair<int, int>> edges[MAX_N]; // adjacency list for the graph
long long vertex_weights[MAX_N]; // weights of the vertices
long long min_path_weights[MAX_N]; // minimum path weights from vertex 1 to other vertices

void dijkstra(int start_vertex) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    q.push({0, start_vertex});
    min_path_weights[start_vertex] = 0;

    while (!q.empty()) {
        long long current_weight = q.top().first;
        int current_vertex = q.top().second;
        q.pop();

        for (auto& edge : edges[current_vertex]) {
            int next_vertex = edge.first;
            long long next_weight = edge.second;

            // Calculate the new path weight
            long long new_weight = current_weight + vertex_weights[next_vertex] + next_weight;

            // If the new weight is smaller, update it and push to the queue
            if (new_weight < min_path_weights[next_vertex]) {
                min_path_weights[next_vertex] = new_weight;
                q.push({new_weight, next_vertex});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Read vertex weights
    for (int i = 1; i <= n; ++i) {
        cin >> vertex_weights[i];
        min_path_weights[i] = INF; // Initially set to infinite
    }

    // Read edges and construct the graph
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        edges[u].push_back({v, b});
        edges[v].push_back({u, b});
    }

    // Run Dijkstra's algorithm from vertex 1
    dijkstra(1);

    // Output the minimum path weights from vertex 1 to all other vertices
    for (int i = 2; i <= n; ++i) {
        cout << min_path_weights[i] << " ";
    }
    cout << endl;

    return 0;
}