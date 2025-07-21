#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

// Function to find the shortest paths using Dijkstra's Algorithm
vector<ll> dijkstra(int n, vector<vector<pii>>& adj, int start) {
    vector<ll> dist(n + 1, LLONG_MAX);
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<ll> A(n + 1);
    for (int i = 1; i <= n; ++i) cin >> A[i];

    vector<vector<pii>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        adj[u].emplace_back(v, b);
        adj[v].emplace_back(u, b);
    }

    // Perform Dijkstra's Algorithm from each node
    vector<ll> result(n);
    for (int i = 1; i <= n; ++i) {
        auto dist = dijkstra(n, adj, i);
        for (int j = 1; j <= n; ++j) {
            result[j - 1] += dist[j];
        }
    }

    // Subtract the initial weights from the results
    for (int i = 0; i < n - 1; ++i) {
        result[i] -= A[1];
    }

    // Print the results
    for (int i = 0; i < n - 1; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}