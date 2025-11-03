#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int j = 0; j < m; j++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<long long> dist(n + 1, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    
    // Start from vertex 1: include its vertex weight
    dist[1] = a[0];
    pq.push({a[0], 1});

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        // Skip if we have found a better distance already
        if (d > dist[node]) continue;

        for (auto [neighbor, edge_weight] : adj[node]) {
            // Calculate new distance: current distance + edge weight + neighbor's vertex weight
            long long new_dist = d + edge_weight + a[neighbor - 1];
            
            if (new_dist < dist[neighbor]) {
                dist[neighbor] = new_dist;
                pq.push({new_dist, neighbor});
            }
        }
    }

    // Output distances for vertices 2 to n
    for (int i = 2; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}