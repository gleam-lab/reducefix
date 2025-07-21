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

    vector<long long> dist(n + 1, LLONG_MAX);
    dist[1] = a[0];
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({a[0], 1});

    while (!pq.empty()) {
        auto [curr_dist, u] = pq.top();
        pq.pop();

        if (curr_dist > dist[u]) continue;

        for (auto &edge : adj[u]) {
            long long w = edge.second;
            int v = edge.first;
            long long new_dist = curr_dist + a[v] + w;
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << dist[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}