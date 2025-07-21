#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<long long> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    vector<vector<pair<int, long long>>> adj(n + 1); // adjacency list: node -> (neighbor, edge weight)
    for (int j = 0; j < m; ++j) {
        int u, v;
        long long b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }

    const long long INF = 1e18;
    vector<long long> dist(n + 1, INF);
    dist[1] = A[0]; // Start with the weight of node 1

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({dist[1], 1});

    while (!pq.empty()) {
        auto [current_dist, u] = pq.top();
        pq.pop();

        if (current_dist > dist[u]) continue;

        for (auto &[v, edge_weight] : adj[u]) {
            long long new_cost = current_dist + edge_weight + A[v - 1];
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({new_cost, v});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";
}