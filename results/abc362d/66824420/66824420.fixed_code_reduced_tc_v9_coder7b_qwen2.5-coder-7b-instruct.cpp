#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<long long> a(n + 1), dist(n + 1, LLONG_MAX);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int j = 0; j < m; ++j) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    dist[1] = a[1];
    pq.emplace(dist[1], 1);

    while (!pq.empty()) {
        auto [d, node] = pq.top(); pq.pop();
        if (d > dist[node]) continue;
        for (auto [neighbor, weight] : adj[node]) {
            long long newDist = d + weight + a[neighbor];
            if (newDist < dist[neighbor]) {
                dist[neighbor] = newDist;
                pq.emplace(newDist, neighbor);
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    return 0;
}