#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

using ll = long long;
const ll INF = 1LL << 60;

template <typename T>
void chmin(T& x, const T& y) { x = min(x, y); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<pair<ll, ll>>> graph(n);
    for (ll i = 0; i < m; i++) {
        ll u, v, b;
        cin >> u >> v >> b;
        u--; v--;
        graph[u].emplace_back(v, b);
        graph[v].emplace_back(u, b);
    }

    // Dijkstra's algorithm
    vector<ll> dist(n, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    
    // Start from vertex 0 (vertex 1 in 1-indexed)
    // The initial cost includes the weight of vertex 0
    dist[0] = a[0];
    pq.emplace(dist[0], 0);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, edge_weight] : graph[u]) {
            ll new_cost = dist[u] + edge_weight + a[v];
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.emplace(new_cost, v);
            }
        }
    }

    // Output results for vertices 2 to N (1-indexed), which are indices 1 to n-1 (0-indexed)
    for (ll i = 1; i < n; i++) {
        cout << dist[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;

    return 0;
}