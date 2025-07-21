#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int j = 0; j < m; ++j) {
        int u, v;
        long long b;
        cin >> u >> v >> b;
        adj[u].emplace_back(v, b);
        adj[v].emplace_back(u, b);
    }
    
    vector<long long> dist(n + 1, LLONG_MAX);
    dist[1] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.emplace(0, 1);
    
    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();
        long long current_dist = current.first;
        int u = current.second;
        
        if (current_dist > dist[u]) {
            continue;
        }
        
        for (auto &edge : adj[u]) {
            int v = edge.first;
            long long cost = edge.second;
            long long new_dist = current_dist + cost + a[v - 1];
            if (u == 1) {
                new_dist = current_dist + cost + a[u - 1] + a[v - 1];
            } else {
                new_dist = current_dist + cost + a[v - 1];
            }
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.emplace(new_dist, v);
            }
        }
    }
    
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
    
    return 0;
}