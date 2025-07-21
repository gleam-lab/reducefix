#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int j = 0; j < m; j++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    vector<long long> dist(n + 1, 1e18); // Initialize distance to infinity
    dist[1] = a[0]; // Starting point
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({a[0], 1});

    while (!pq.empty()) {
        auto [val, node] = pq.top();
        pq.pop();

        if (val > dist[node]) continue; // Skip outdated entries

        for (auto [neighbor, weight] : adj[node]) {
            long long total_dist = val + weight + a[neighbor - 1]; // Adjusting index for 0-based array
            if (total_dist < dist[neighbor]) {
                dist[neighbor] = total_dist;
                pq.push({total_dist, neighbor});
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}