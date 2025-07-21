#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<long long> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int j = 0; j < m; ++j) {
        int u, v;
        long long b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }

    // Use a large enough "infinity" value
    const long long INF = numeric_limits<long long>::max() / 2;
    vector<long long> dist(n + 1, INF);
    dist[1] = A[0]; // Starting from node 1, include its vertex weight

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({dist[1], 1});

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (cost > dist[u]) continue;

        for (auto &[v, edge_cost] : adj[u]) {
            long long new_cost = cost + edge_cost;
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({new_cost, v});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << '\n';

    return 0;
}