#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;

vector<pair<int, int>> graph[N]; // adjacency list for the graph
long long vertex_weights[N]; // weights of the vertices
vector<pair<pair<int, int>, int>> edges; // edges with their weights

// Custom comparator for the priority queue
struct Compare {
    bool operator()(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b) {
        return a.second > b.second;
    }
};

// Function to perform Dijkstra's algorithm
void dijkstra(int start, vector<long long>& distances) {
    distances.assign(N, 1e18); // Initialize distances with a large number
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, Compare> pq;
    distances[start] = vertex_weights[start]; // Distance to the start vertex is its own weight
    pq.push({{start, 0}, vertex_weights[start]});

    while (!pq.empty()) {
        auto [u, _] = pq.top();
        pq.pop();

        int current = u.first;
        long long currentWeight = u.second;

        if (currentWeight > distances[current]) continue;

        for (auto& [neighbor, weight] : graph[current]) {
            int next = neighbor;
            long long nextWeight = currentWeight + weight + vertex_weights[next];

            if (nextWeight < distances[next]) {
                distances[next] = nextWeight;
                pq.push({{next, 0}, nextWeight});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    cin >> vertex_weights + 1; // Read vertex weights

    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
        edges.emplace_back({{u, v}, b});
    }

    vector<long long> distances;
    dijkstra(1, distances); // Compute shortest paths from vertex 1

    for (int i = 2; i <= n; ++i) {
        cout << distances[i] << (i < n ? " " : ""); // Output distances to each vertex from 1, skipping vertex 1
    }

    return 0;
}