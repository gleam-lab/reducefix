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
        // When moving from u to v, we include u's vertex weight + edge weight
        // This way, when reaching v, only v's weight is missing
        adj[u].push_back({v, A[u] + b});
        adj[v].push_back({u, A[v] + b});
    }

    vector<ll> dist(n, INF);
    dist[0] = 0;  // Start from vertex 0 (vertex 1 in original problem)
    
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    // When printing, add A[i] because:
    // - The path cost includes all vertex weights except the destination
    // - So we need to add A[i] to complete the path cost
    for (int i = 1; i < n; ++i) {
        cout << dist[i] + A[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}