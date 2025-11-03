#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int j = 0; j < m; j++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<long long> dist(n + 1, LLONG_MAX);
    dist[1] = a[1]; // Include vertex weight of starting node

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.emplace(a[1], 1);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) continue;

        for (auto [v, edge_weight] : adj[u]) {
            long long new_dist = d + edge_weight + a[v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.emplace(new_dist, v);
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}