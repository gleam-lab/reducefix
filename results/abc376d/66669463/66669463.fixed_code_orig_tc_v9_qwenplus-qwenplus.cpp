#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

// Structure to represent edges in the graph
struct Edge {
    int to;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Adjacency list for the graph
    vector<vector<Edge>> graph(n + 1);

    // Read all directed edges
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back({v});
    }

    // Distance array initialized to infinity
    const int INF = numeric_limits<int>::max();
    vector<int> dist(n + 1, INF);
    dist[1] = 0;

    // Queue for BFS
    queue<int> q;
    q.push(1);

    // BFS traversal to find shortest cycle length
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (const auto& e : graph[u]) {
            int v = e.to;
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    // Output the result: minimum cycle length back to node 1
    if (dist[1] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[1] << endl;
    }

    return 0;
}