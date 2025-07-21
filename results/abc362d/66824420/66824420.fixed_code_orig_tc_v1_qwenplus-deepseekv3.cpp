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
    for (int j = 0; j < m; j++) {
        int x, y;
        long long w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    vector<long long> dist(n + 1, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    dist[1] = a[0];
    q.push({dist[1], 1});

    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        long long val = p.first;
        int node = p.second;
        if (val > dist[node]) continue;
        for (auto it : adj[node]) {
            int neighbor = it.first;
            long long edge_weight = it.second;
            long long total_dist = val + edge_weight + a[neighbor - 1];
            if (total_dist < dist[neighbor]) {
                dist[neighbor] = total_dist;
                q.push({dist[neighbor], neighbor});
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}