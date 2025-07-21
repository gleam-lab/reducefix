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
        adj[x].push_back({y, w + a[y - 1]});
        adj[y].push_back({x, w + a[x - 1]});
    }
    
    vector<long long> dist(n + 1, LLONG_MAX);
    dist[1] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    q.push({0, 1});
    while (!q.empty()) {
        auto [val, node] = q.top();
        q.pop();
        if (val > dist[node]) continue;
        for (auto [it, w] : adj[node]) {
            long long total_dist = val + w;
            if (total_dist < dist[it]) {
                dist[it] = total_dist;
                q.push({total_dist, it});
            }
        }
    }
    
    for (int i = 2; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}