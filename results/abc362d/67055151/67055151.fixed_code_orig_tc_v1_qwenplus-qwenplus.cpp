#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<ll> A(n);
    for (ll i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // Build graph: adjacency list of (neighbor, edge weight)
    vector<vector<pair<ll, ll>>> graph(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        u--; v--;
        graph[u].emplace_back(v, b);
        graph[v].emplace_back(u, b);
    }

    // Dijkstra's algorithm to find minimum path weights from node 0
    vector<ll> dist(n, INF);
    dist[0] = A[0];  // Starting node's cost includes its vertex weight

    using pll = pair<ll, ll>;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.emplace(A[0], 0);  // (cost, node)

    while (!pq.empty()) {
        ll d = pq.top().first;
        ll u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& [v, w] : graph[u]) {
            ll new_cost = dist[u] + w + A[v];  // current cost + edge weight + destination vertex weight
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.emplace(dist[v], v);
            }
        }
    }

    // Output results from node 1 to node n-1
    for (ll i = 1; i < n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}