#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<pair<int, long long>>> adj(n + 1); // Store the weight of the edge
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<long long> dist(n + 1, 1e18); // Use a large value
    dist[1] = a[0];
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    q.push({a[0], 1});

    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        if (d > dist[u]) continue; //Skip if the node is already visited with a smaller distance
        for (auto &nei : adj[u]) {
            int v = nei.first;
            long long weight = nei.second;
            long long new_dist = d + weight + a[v - 1]; // Subtract 1 because vertices are 1-indexed
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                q.push({new_dist, v});
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}