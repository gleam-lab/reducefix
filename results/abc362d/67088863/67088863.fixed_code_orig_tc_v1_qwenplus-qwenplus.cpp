#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> A(n);
    for (ll& x : A) cin >> x;

    vector<vector<pair<int, ll>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        u--; v--;
        // The edge weight includes the vertex value at the other end
        adj[u].push_back({v, b + A[v]});
        adj[v].push_back({u, b + A[u]});
    }

    vector<ll> dist(n, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

    // Start from node 0 (node 1 in 1-based)
    dist[0] = A[0]; // Include starting node's value
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, cost] : adj[u]) {
            if (dist[v] > dist[u] + cost - A[v]) { // Subtract A[v] because it's included in both edge cost and initial path
                dist[v] = dist[u] + cost - A[v];
                pq.push({dist[v], v});
            }
        }
    }

    // Output distances from node 1 to nodes 2..n
    for (int i = 1; i < n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}