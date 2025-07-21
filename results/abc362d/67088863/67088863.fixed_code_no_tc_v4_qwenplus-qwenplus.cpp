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
    for (ll &a : A) cin >> a;

    vector<vector<pair<int, ll>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        u--; v--;
        // When moving from u to v, we include edge weight b and vertex weight of v
        // Similarly for v to u
        adj[u].push_back({v, b + A[v]});
        adj[v].push_back({u, b + A[u]});
    }

    vector<ll> dist(n, INF);
    dist[0] = A[0];  // Starting point includes vertex weight of A[0]

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, cost] : adj[u]) {
            if (dist[v] > dist[u] + cost - A[v]) {  // Exclude A[v] because it's already included in the node-to-node cost
                dist[v] = dist[u] + cost - A[v];
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}