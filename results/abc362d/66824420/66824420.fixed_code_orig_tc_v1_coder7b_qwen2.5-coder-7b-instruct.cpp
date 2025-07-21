#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int j = 0; j < m; ++j) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<long long> dist(n + 1, 1e10 + 0);
    dist[1] = a[0];
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({a[0], 1});

    while (!pq.empty()) {
        auto [val, node] = pq.top();
        pq.pop();

        if (val > dist[node]) continue;

        for (auto& [neighbor, weight] : adj[node]) {
            long long total_dist = val + weight + a[neighbor - 1];
            if (total_dist < dist[neighbor]) {
                dist[neighbor] = total_dist;
                pq.push({total_dist, neighbor});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }

    return 0;
}