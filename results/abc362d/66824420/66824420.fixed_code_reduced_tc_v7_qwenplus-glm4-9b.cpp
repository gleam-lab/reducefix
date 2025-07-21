#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int j = 0; j < m; ++j) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    // Use a priority queue to efficiently get the shortest path
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({a[0], 1}); // Start from vertex 1 with initial distance as the weight of the first vertex

    vector<long long> dist(n + 1, 1e10 + 7); // Use a large initial distance
    dist[1] = a[0]; // Set the distance to the first vertex as its own weight

    while (!pq.empty()) {
        auto [current_dist, u] = pq.top();
        pq.pop();

        if (current_dist > dist[u]) {
            continue; // Skip if we have found a shorter path already
        }

        // Explore neighbors
        for (auto &[v, weight] : adj[u]) {
            long long new_dist = current_dist + weight + a[v - 1]; // Calculate the new distance
            if (new_dist < dist[v]) {
                dist[v] = new_dist; // Update the shortest distance
                pq.push({new_dist, v}); // Add to the priority queue
            }
        }
    }

    // Output the minimum weights from vertex 1 to all other vertices
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}