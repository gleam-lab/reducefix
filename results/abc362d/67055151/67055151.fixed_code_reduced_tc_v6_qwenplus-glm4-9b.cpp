#include <vector>
#include <queue>
#include <limits>
#include <iostream>
using namespace std;

const int MAX_N = 200100;
vector<pair<int, int>> adj[MAX_N]; // adj[u]: list of (v, weight) pairs for vertex u
int dist[MAX_N]; // dist[v]: minimum distance from vertex 1 to vertex v

void dijkstra(int start_vertex) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
    for (int i = 0; i < MAX_N; ++i) {
        dist[i] = numeric_limits<int>::max(); // Initialize distances to infinite
    }
    dist[start_vertex] = 0;
    min_heap.push({0, start_vertex});

    while (!min_heap.empty()) {
        int current_dist = min_heap.top().first;
        int current_vertex = min_heap.top().second;
        min_heap.pop();

        if (current_dist > dist[current_vertex]) {
            continue;
        }

        for (auto edge : adj[current_vertex]) {
            int neighbor = edge.first;
            int weight = edge.second;
            int new_dist = current_dist + weight;
            if (new_dist < dist[neighbor]) {
                dist[neighbor] = new_dist;
                min_heap.push({new_dist, neighbor});
            }
        }
    }
}

int main() {
    // Read number of vertices and edges
    int n, m;
    cin >> n >> m;

    // Read vertex weights
    vector<int> vertex_weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> vertex_weights[i];
    }

    // Read edges and construct the graph
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--; // Adjust for 0-based indexing
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Solve the problem for vertices from 1 to N
    dijkstra(0); // Vertex 1 is 0-indexed

    // Output the shortest distances from vertex 1 to all other vertices
    for (int i = 1; i < n; ++i) {
        cout << dist[i] + vertex_weights[i] << " "; // Add vertex weight to the result
    }
    cout << endl;

    return 0;
}