#include <bits/stdc++.h>
using namespace std;

const long long INF = numeric_limits<long long>::max();

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector<long long> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<pair<int, long long>>> adj(n + 1);
    for(int j = 0; j < m; ++j){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.emplace(a[0], 1);
    dist[1] = a[0];

    while (!pq.empty()) {
        auto [d, node] = pq.top(); pq.pop();
        
        // If we've already found a shorter path to this node, skip it
        if (d > dist[node]) continue;

        for (auto [neighbor, edge_weight] : adj[node]) {
            long long new_distance = d + edge_weight + a[neighbor - 1];
            if (new_distance < dist[neighbor]) {
                dist[neighbor] = new_distance;
                pq.emplace(new_distance, neighbor);
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }

    return 0;
}