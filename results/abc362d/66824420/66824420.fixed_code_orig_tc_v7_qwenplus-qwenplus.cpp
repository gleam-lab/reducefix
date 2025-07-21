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
        int u, v, b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }

    const long long INF = 1e18;
    vector<long long> dist(n + 1, INF);
    dist[1] = A[0]; // Starting node's cost includes its own vertex weight

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
    q.push({dist[1], 1});

    while (!q.empty()) {
        auto [cost, u] = q.top();
        q.pop();

        if (cost > dist[u]) continue;

        for (auto &[v, edge_cost] : adj[u]) {
            long long new_cost = cost + edge_cost + A[v - 1];

            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                q.push({new_cost, v});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << '\n';
}