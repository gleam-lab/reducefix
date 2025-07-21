#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <tuple>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef vector<vector<pl>> graph;

void dijkstra(const graph &g, vector<ll> &dist, int start) {
    dist[start] = 0;
    priority_queue<pl, vector<pl>, greater<pl>> pq;
    pq.emplace(dist[start], start);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        
        if (d > dist[u]) continue;

        for (auto [v, w] : g[u]) {
            ll new_dist = d + w + g[v][u].second; // Total cost includes vertex weights
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.emplace(dist[v], v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    graph g(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        --u, --v;
        g[u].emplace_back(v, b);
        g[v].emplace_back(u, b);
    }

    vector<ll> dist(n, LLONG_MAX);
    dijkstra(g, dist, 0);

    for (ll i = 1; i < n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}