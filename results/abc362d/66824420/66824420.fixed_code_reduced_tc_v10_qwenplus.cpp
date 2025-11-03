#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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
        adj[x].emplace_back(y, w);
        adj[y].emplace_back(x, w);
    }

    vector<long long> dist(n + 1, LLONG_MAX);
    dist[1] = a[0]; // Include starting vertex weight

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
    q.emplace(a[0], 1);

    while (!q.empty()) {
        auto [d, node] = q.top();
        q.pop();

        if (d != dist[node]) continue;

        for (auto [neighbor, edge_weight] : adj[node]) {
            long long new_dist = dist[node] + edge_weight + a[neighbor - 1];
            if (new_dist < dist[neighbor]) {
                dist[neighbor] = new_dist;
                q.emplace(new_dist, neighbor);
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << dist[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}