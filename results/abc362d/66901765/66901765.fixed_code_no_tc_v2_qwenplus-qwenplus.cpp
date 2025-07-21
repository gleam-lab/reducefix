#include<bits/stdc++.h>
using namespace std;
#define int long long

// Use an adjacency list to store graph edges
vector<vector<pair<int, int>>> graph(200005); // graph[u] contains pairs (v, edge_weight)

// Dijkstra's algorithm variables
int dist[200005];
bool visited[200005];

void dijkstra(int start, const int A[]) {
    // Min-heap priority queue: stores (current_distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initialize distance of starting node
    dist[start] = A[start];  // Only include vertex weight at the start
    pq.push({dist[start], start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto& [v, edge_weight] : graph[u]) {
            // Path cost to v via u = cost to u + edge weight + vertex weight of v
            int new_dist = dist[u] + edge_weight + A[v];

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({dist[v], v});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int A[200005]; // Vertex weights
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        dist[i] = numeric_limits<int>::max(); // Initialize distances to infinity
        visited[i] = false;
    }

    // Read edges and build graph
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    // Run Dijkstra from node 1
    dijkstra(1, A);

    // Output results for nodes 2 through N
    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}