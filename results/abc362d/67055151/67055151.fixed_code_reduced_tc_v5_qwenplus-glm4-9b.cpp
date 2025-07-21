#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Define constants and types
const int MAX_N = 200000;  // Maximum number of vertices and edges
const long long INF = 1e18;  // Large number to represent infinity

// Define the graph structure
vector<pair<int, int>> graph[MAX_N];  // Adjacency list representation

// Function to add an edge to the graph
void addEdge(int u, int v, long long weight) {
    graph[u].push_back({v, weight});
    graph[v].push_back({u, weight});
}

// Function to calculate the shortest path from vertex 1 to all other vertices
vector<long long> shortestPathFrom1(int n) {
    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    // Distance from 1 to 1 is 0
    dist[1] = 0;
    // Push the starting vertex with distance 0 into the priority queue
    pq.push({0, 1});

    while (!pq.empty()) {
        int u = pq.top().second;
        long long d = pq.top().first;
        pq.pop();

        // Only process vertex if the popped distance is the shortest distance
        if (dist[u] < d) continue;

        // Explore all adjacent vertices
        for (auto& edge : graph[u]) {
            int v = edge.first;
            long long weight = edge.second;
            if (d + weight < dist[v]) {
                // Update the shortest distance to v
                dist[v] = d + weight;
                // Push the updated vertex with distance into the priority queue
                pq.push({dist[v], v});
            }
        }
    }

    // Remove the distance for vertex 1 (not needed for the output)
    dist[1] = 0;

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Read the vertex weights
    vector<long long> A(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }

    // Read the edges and construct the graph
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        addEdge(u, v, weight);
    }

    // Calculate the shortest paths from vertex 1 to all other vertices
    vector<long long> dist = shortestPathFrom1(n);

    // Output the results
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}