#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n + 1); // Adjusted size to accommodate 1-based indexing
    for (int i = 1; i <= n; i++) cin >> a[i]; // Corrected loop condition
    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int j = 0; j < m; j++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    vector<long long> dist(n + 1, 1e18); // Initialize with a large number
    dist[1] = a[1]; // Corrected index access
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({a[1], 1});

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        long long val = p.first, node = p.second;
        if (val > dist[node]) continue; // Skip if current value is not optimal
        for (auto it : adj[node]) {
            long long total_dist = val + it.second + a[it.first]; // Corrected index access
            if (total_dist < dist[it.first]) {
                dist[it.first] = total_dist;
                pq.push({total_dist, it.first});
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}