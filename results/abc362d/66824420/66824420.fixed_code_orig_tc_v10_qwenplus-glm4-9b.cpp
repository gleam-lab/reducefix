#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> vertex_weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> vertex_weights[i];
    }

    vector<vector<pair<int, long long>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].push_back({v - 1, w});
        adj[v - 1].push_back({u - 1, w});
    }

    vector<long long> dist(n, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({vertex_weights[0], 0});
    dist[0] = vertex_weights[0];

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            long long new_dist = d + vertex_weights[v] + w;
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}