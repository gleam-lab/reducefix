#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 300010;
vector<pair<int, int>> adj[N]; // adj[i] will store pairs (j, weight of edge from i to j)
vector<long long> vertex_weights(N); // vertex_weights[i] will store the weight of vertex i

// Function to perform BFS and find the minimum path distances from source to all other vertices
void bfs(int source) {
    queue<int> q;
    q.push(source);
    vertex_weights[source] = 0; // Distance from source to itself is 0
    while (!q.empty()) {
        int current = q.front(); q.pop();
        long long current_vertex_weight = vertex_weights[current];
        
        for (auto &edge : adj[current]) {
            int neighbor = edge.first;
            long long edge_weight = edge.second;
            // Calculate the total path weight to the neighbor
            long long path_weight = current_vertex_weight + edge_weight + vertex_weights[neighbor];
            // If we found a shorter path to the neighbor, update and continue BFS
            if (path_weight < vertex_weights[neighbor]) {
                vertex_weights[neighbor] = path_weight;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> vertex_weights[i];
    }
    for (int i = 1; i <= m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    // Start BFS from vertex 1 (assuming 1-based index)
    bfs(1);

    // Output the minimum path weight to each vertex from 1 (excluding vertex 1 itself)
    for (int i = 2; i <= n; ++i) {
        cout << vertex_weights[i] << " ";
    }
    cout << endl;

    return 0;
}