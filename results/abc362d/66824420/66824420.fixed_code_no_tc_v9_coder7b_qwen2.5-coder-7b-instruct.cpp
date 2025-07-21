#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int j = 0; j < m; j++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<long long> dist(n + 1, 1e18);
    dist[1] = a[0];
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({a[0], 1});

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int node = p.second;
        long long currentDist = p.first;

        if (currentDist > dist[node])
            continue;

        for (auto &neighbor : adj[node]) {
            int neighborNode = neighbor.first;
            long long newDist = currentDist + neighbor.second + a[neighborNode - 1];

            if (newDist < dist[neighborNode]) {
                dist[neighborNode] = newDist;
                pq.push({newDist, neighborNode});
            }
        }
    }

    for (int i = 2; i <= n; i++)
        cout << dist[i] << " ";

    return 0;
}