#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

using i64 = long long;
#define INF I64_MAX

int n, m;
vector<pair<i64, i64>> adj[200001]; // adj[u] contains {v, distance_from_v_to_u}

i64 dijkstra(int src) {
    priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<pair<i64, int>>> pq;
    vector<i64> dist(n + 1, INF);

    pq.push({0, src}); // push {distance, vertex}
    dist[src] = 0;

    while (!pq.empty()) {
        i64 cd = pq.top().first;
        int cv = pq.top().second;
        pq.pop();

        if (cd != dist[cv]) continue; // Skip if we've already found a shorter path

        for (auto [nv, weight] : adj[cv]) {
            i64 new_dist = dist[cv] + weight;
            if (new_dist < dist[nv]) {
                dist[nv] = new_dist;
                pq.push({new_dist, nv});
            }
        }
    }

    return dist[src];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> adj[i][0].second; // vertex weight
    }

    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }

    cout << dijkstra(1) << endl; // Print the shortest path from vertex 1 to all other vertices

    return 0;
}