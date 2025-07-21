#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, int> pii;

void dijkstra(vector<vector<pii>>& adj, vector<long long>& dist, vector<long long>& a) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({a[0], 1});
    dist[1] = a[0];

    while (!pq.empty()) {
        auto [currentDist, node] = pq.top();
        pq.pop();

        if (currentDist > dist[node]) continue;

        for (auto [neighbor, edgeWeight] : adj[node]) {
            long long newDist = currentDist + a[neighbor - 1] + edgeWeight;
            if (newDist < dist[neighbor]) {
                dist[neighbor] = newDist;
                pq.push({newDist, neighbor});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<pii>> adj(n + 1);
    for (int j = 0; j < m; ++j) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<long long> dist(n + 1, LLONG_MAX);
    dijkstra(adj, dist, a);

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }

    return 0;
}