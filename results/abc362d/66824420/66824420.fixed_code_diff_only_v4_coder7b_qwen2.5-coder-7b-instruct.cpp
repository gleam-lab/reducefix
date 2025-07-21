#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int j = 0; j < m; j++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<long long> dist(n + 1, 1e18); // Initialize distance array with a large number
    dist[1] = a[0]; // Distance to the starting node is just its own weight

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({a[0], 1}); // Push the starting node into the priority queue

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        long long val = p.first, node = p.second;

        for (auto &it : adj[node]) { // Reference to avoid unnecessary copies
            long long total_dist = val + it.second + a[it.first - 1]; // Calculate total distance
            if (total_dist < dist[it.first]) { // If a shorter path is found
                dist[it.first] = total_dist; // Update the distance
                pq.push({total_dist, it.first}); // Push the updated node into the priority queue
            }
        }
    }

    for (int i = 2; i <= n; i++)
        cout << dist[i] << " ";

    return 0;
}