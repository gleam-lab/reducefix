#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    vector<vector<pair<int, long long>>> adj(n + 1);
    for(int j = 0; j < m; ++j){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v; // Adjust indices to be zero-based
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<long long> dist(n, LLONG_MAX);
    dist[0] = a[0]; // Correctly initialize distance for the first node

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.emplace(dist[0], 0);

    while(!pq.empty()) {
        auto [val, node] = pq.top(); pq.pop();
        if(val != dist[node]) continue; // Skip outdated paths

        for(const auto& [neighbor, weight] : adj[node]) {
            long long total_dist = val + weight + a[neighbor];
            if(total_dist < dist[neighbor]) {
                dist[neighbor] = total_dist;
                pq.emplace(dist[neighbor], neighbor);
            }
        }
    }

    for(int i = 1; i < n; ++i) { // Start from index 1 as we need distances from node 1
        cout << dist[i] << " ";
    }

    return 0;
}