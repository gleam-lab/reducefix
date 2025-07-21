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
        auto [val, node] = q.top();
        q.pop();
        if (val > dist[node]) continue;
        for (auto [neighbor, w] : adj[node]) {
            long long total_dist = val + w + a[neighbor - 1];
            if (total_dist < dist[neighbor]) {
                dist[neighbor] = total_dist;
                q.emplace(total_dist, neighbor);
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << dist[i] << " ";
    }
    return 0;
}