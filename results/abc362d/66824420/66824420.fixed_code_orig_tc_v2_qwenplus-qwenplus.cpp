#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    vector<vector<pair<int, long long>>> adj(n + 1); // adj[0] unused
    for (int j = 0; j < m; ++j) {
        int u, v;
        long long b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }

    const long long INF = numeric_limits<long long>::max();
    vector<long long> dist(n + 1, INF);
    dist[1] = A[0]; // Start with vertex 1's weight

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
    cout << "\n";

    return 0;
}