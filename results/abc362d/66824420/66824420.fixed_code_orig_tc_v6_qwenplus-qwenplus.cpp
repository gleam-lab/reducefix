#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<long long> A(n);
    for(int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    vector<vector<pair<int, long long>>> adj(n + 1); // Adjacency list: node -> {neighbor, edge_weight}
    for(int j = 0; j < m; ++j) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<long long> dist(n + 1, 1e18);
    dist[1] = A[0]; // Start from node 1, include its vertex weight

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
    q.push({dist[1], 1});

    while (!q.empty()) {
        auto [curr_cost, u] = q.top();
        q.pop();

        if (curr_cost > dist[u]) continue;

        for (auto &[v, edge_cost] : adj[u]) {
            long long new_cost = curr_cost + edge_cost + A[v - 1];

            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                q.push({new_cost, v});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";
}