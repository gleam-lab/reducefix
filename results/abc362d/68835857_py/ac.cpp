#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int64_t> a(n);
    for (auto& x : a) cin >> x;
    vector<vector<pair<int, int64_t>>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        int64_t b;
        cin >> u >> v >> b;
        u--, v--;
        g[u].push_back({v, b});
        g[v].push_back({u, b});
    }
    vector<int64_t> dist(n, LLONG_MAX);
    priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> pq;
    dist[0] = a[0];
    pq.push({dist[0], 0});
    while (!pq.empty()) {
        int64_t d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, b] : g[u]) {
            int64_t new_cost = dist[u]+b+a[v];
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 1; i < n; i++) cout << dist[i] << " \n"[i+1 == n];
    return 0;
}
