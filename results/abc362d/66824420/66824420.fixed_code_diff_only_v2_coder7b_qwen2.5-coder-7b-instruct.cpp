#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int j = 0; j < m; j++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<long long> dist(n + 1, LLONG_MAX);
    dist[1] = a[1];
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({a[1], 1});

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        long long val = p.first, node = p.second;
        if (val > dist[node]) continue; // Skip outdated entries

        for (auto it : adj[node]) {
            long long total_dist = val + it.second + a[it.first];
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