#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <functional>
#include <iostream>

using namespace std;

typedef long long ll;

struct Edge {
    int to;
    int weight;
};

const int INF = 1e9;

vector<vector<Edge>> graph;
vector<ll> dist;
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

void solve(int n, int m, vector<ll>& weights, vector<vector<int>>& edges) {
    // Initialize graph and distance vector
    graph.resize(n);
    dist.resize(n, INF);
    dist[0] = weights[0]; // Start from vertex 0

    // Construct the graph
    for (int i = 0; i < m; ++i) {
        int u = edges[i][0] - 1; // Convert to 0-based index
        int v = edges[i][1] - 1; // Convert to 0-based index
        int b = edges[i][2];
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }

    // Dijkstra's algorithm
    pq.push({0, 0}); // Start from vertex 0
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u] < d) continue;

        for (const auto& edge : graph[u]) {
            int to = edge.to;
            int weight = edge.weight;
            int nd = d + weight + weights[to]; // Vertex weight + edge weight
            if (nd < dist[to]) {
                dist[to] = nd;
                pq.push({dist[to], to});
            }
        }
    }

    // Output the minimum weights for paths from vertex 0 to all other vertices
    for (int i = 1; i < n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<ll> weights(n);
    for (ll& w : weights) cin >> w;

    vector<vector<int>> edges(m);
    for (vector<int>& edge : edges) {
        int u, v, b;
        cin >> u >> v >> b;
        edge = {u, v, b};
    }

    solve(n, m, weights, edges);

    return 0;
}