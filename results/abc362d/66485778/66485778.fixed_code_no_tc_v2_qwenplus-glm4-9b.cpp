#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 300010;
vector<pair<int, int>> adj[N]; // adj[i] will store pairs (j, weight of edge i-j)

// Dijkstra's algorithm to find the shortest path from node 1 to all other nodes
void dijkstra(int n, vector<long long>& dist, vector<long long>& node_weights) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({node_weights[1], 1});
    dist[1] = node_weights[1];

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (int v : adj[u]) {
            int weight = v.second + node_weights[v.first];
            if (d + weight < dist[v.first]) {
                dist[v.first] = d + weight;
                pq.push({dist[v.first], v.first});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> node_weights(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> node_weights[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }

    vector<long long> dist(n + 1, 1e18); // Initialize distances to a large value
    dijkstra(n, dist, node_weights);

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << (i == n ? "" : " ");
    }
    cout << endl;

    return 0;
}