#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int to, weight;
};

vector<Edge> graph[200005]; // Adjacency list for the graph
int vertexWeights[200005]; // Vertex weights
int distances[200005]; // To store the minimum distance from vertex 1 to each vertex

void dijkstra(int startVertex) {
    fill(distances, distances + 200005, numeric_limits<int>::max());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap to store vertices and their current distances
    distances[startVertex] = vertexWeights[startVertex];
    pq.push({0, startVertex});

    while (!pq.empty()) {
        int currentDistance = pq.top().first;
        int currentVertex = pq.top().second;
        pq.pop();

        if (currentDistance > distances[currentVertex]) continue;

        for (auto &edge : graph[currentVertex]) {
            int nextVertex = edge.to;
            int edgeWeight = edge.weight;
            int distanceThroughEdge = currentDistance + vertexWeights[nextVertex] + edgeWeight;

            if (distanceThroughEdge < distances[nextVertex]) {
                distances[nextVertex] = distanceThroughEdge;
                pq.push({distanceThroughEdge, nextVertex});
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> vertexWeights[i];
    }
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    dijkstra(1); // Run Dijkstra's algorithm starting from vertex 1

    for (int i = 2; i <= N; ++i) {
        cout << distances[i] << " ";
    }
    cout << endl;

    return 0;
}