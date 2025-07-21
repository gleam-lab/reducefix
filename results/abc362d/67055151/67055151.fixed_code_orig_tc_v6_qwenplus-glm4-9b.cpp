#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
using ll = long long;

const int MAX_N = 200001; // Maximum number of vertices

vector<pair<int, int>> graph[MAX_N]; // Adjacency list representation
int A[MAX_N]; // Vertex weights
int dist[MAX_N]; // Distance from vertex 1

// Function to perform Dijkstra's algorithm from vertex 1
void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start}); // Push the source vertex with distance 0
    dist[start] = 0;

    while (!pq.empty()) {
        auto [d, v] = pq.top(); pq.pop();
        if (d > dist[v]) continue; // Skip if we already found a shorter path

        for (auto &edge : graph[v]) {
            int to = edge.first;
            int weight = edge.second + A[to]; // Weight including vertex weight
            if (dist[to] > weight) {
                dist[to] = weight; // Update distance
                pq.push({weight, to}); // Push to priority queue
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; ++i) cin >> A[i];

    for (int i = 1; i <= M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    dijkstra(1); // Perform Dijkstra's algorithm from vertex 1

    // Output the shortest distances from vertex 1 to all other vertices
    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}