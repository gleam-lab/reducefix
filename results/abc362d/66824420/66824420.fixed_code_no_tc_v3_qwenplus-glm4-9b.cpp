#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n + 1); // Using 1-based indexing, so size n+1
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<vector<pair<int, long long>>> adj(n + 1); // Edges
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<long long> dist(n + 1, 1e18); // Using 1e18 as initial distance (larger than max possible value)
    dist[1] = 0; // Starting point, no cost to reach itself
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; // Using min-heap based on distance

    pq.push({0, 1}); // Push starting point

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if (d > dist[node]) continue; // If already found a shorter path, skip

        for (auto &u : adj[node]) {
            long long next_dist = d + u.second + a[u.first]; // Cost to reach node u
            if (next_dist < dist[u.first]) {
                dist[u.first] = next_dist;
                pq.push({next_dist, u.first});
            }
        }
    }

    // Output the minimum distances for each node from 2 to n
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}