#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int N = 200001; // Maximum number of vertices

vector<pair<int, int>> graph[N]; // Adjacency list representation of the graph
int distances[N]; // Distance to each vertex from the source

void dijkstra(int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initialize distances and add the source to the priority queue
    fill(distances, distances + N, INT_MAX);
    distances[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int currentDistance = pq.top().first;
        int currentVertex = pq.top().second;
        pq.pop();

        // If the popped vertex has a distance that's not the one we just saw, we've found a shorter path
        if (currentDistance > distances[currentVertex]) continue;

        // Explore each neighbor
        for (const auto& neighbor : graph[currentVertex]) {
            int nextVertex = neighbor.first;
            int edgeWeight = neighbor.second;
            int nextDistance = currentDistance + edgeWeight;

            // If we found a shorter path to the neighbor, update the distance and add it to the priority queue
            if (nextDistance < distances[nextVertex]) {
                distances[nextVertex] = nextDistance;
                pq.push({nextDistance, nextVertex});
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    // Read vertex weights
    for (int i = 1; i <= N; ++i) {
        cin >> distances[i]; // We can ignore the vertex weights if we don't need them
    }

    // Read edges
    for (int i = 0; i < M; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b}); // Since the graph is undirected
    }

    // Run Dijkstra's algorithm from vertex 1
    dijkstra(1);

    // Output the distances to all vertices from 2 to N
    for (int i = 2; i <= N; ++i) {
        cout << distances[i] << (i < N ? " " : "");
    }

    return 0;
}