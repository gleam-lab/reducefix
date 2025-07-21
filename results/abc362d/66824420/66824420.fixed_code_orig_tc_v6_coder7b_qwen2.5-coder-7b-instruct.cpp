#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<pair<int, int>>> adj(n + 1);
    for(int j = 0; j < m; ++j){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<long long> dist(n + 1, LLONG_MAX);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.emplace(a[0], 1);
    dist[1] = a[0];

    while (!pq.empty()) {
        auto [val, node] = pq.top(); pq.pop();

        if (dist[node] < val) continue;

        for (auto& [neighbor, weight] : adj[node]) {
            long long newDist = val + weight + a[neighbor - 1];
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