#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int j = 0; j < m; j++) {
        int x, y;
        long long w;
        cin >> x >> y >> w;
        adj[x].emplace_back(y, w);
        adj[y].emplace_back(x, w);
    }
    
    vector<long long> dist(n + 1, LLONG_MAX);
    dist[1] = a[0];
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    q.emplace(dist[1], 1);
    
    while (!q.empty()) {
        auto [current_dist, u] = q.top();
        q.pop();
        if (current_dist > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            long long new_dist = current_dist + w + a[v - 1];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                q.emplace(new_dist, v);
            }
        }
    }
    
    for (int i = 2; i <= n; i++) {
        cout << dist[i] << " ";
    }
    return 0;
}