#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int j = 0; j < m; ++j) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<long long> dist(n + 1, LLONG_MAX);
    dist[1] = a[0];
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({a[0], 1});

    while (!pq.empty()) {
        auto [current_dist, node] = pq.top(); pq.pop();

        // If we've already found a shorter path to this node, skip processing
        if (current_dist > dist[node]) continue;

        for (auto& [neighbor, weight] : adj[node]) {
            long long new_dist = current_dist + weight + a[neighbor - 1];
            if (new_dist < dist[neighbor]) {
                dist[neighbor] = new_dist;
                pq.push({new_dist, neighbor});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }

    return 0;
}