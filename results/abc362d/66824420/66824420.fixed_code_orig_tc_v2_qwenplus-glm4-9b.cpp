#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }

    vector<long long> dist(n + 1, 1e10 + 7); // Using 1e10+7 instead of 1E10+0 for better readability
    dist[1] = a[0];
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({a[0], 1});

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();
        
        if (d > dist[node]) continue; // Skip if the popped node has a greater distance than already recorded
        
        for (auto &edge : adj[node]) {
            long long nextNode = edge.first;
            long long edgeWeight = edge.second;
            long long nextDist = d + a[nextNode - 1] + edgeWeight;
            if (nextDist < dist[nextNode]) {
                dist[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}