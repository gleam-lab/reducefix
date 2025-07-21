#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

struct Edge {
    ll to, cost;
    Edge(ll to, ll cost) : to(to), cost(cost) {}
};

vector<vector<Edge>> adj;

vector<ll> dijkstra(int n, int start) {
    vector<ll> dist(n, INF);
    dist[start] = 0;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue;

        for (auto &e : adj[u]) {
            ll v = e.to, cost = e.cost;
            if (dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<ll> a(n); for (int i = 0; i < n; ++i) cin >> a[i];

    adj.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v, b; cin >> u >> v >> b;
        --u, --v;
        adj[u].emplace_back(v, b);
        adj[v].emplace_back(u, b);
    }

    vector<ll> costs = dijkstra(n, 0);

    for (int i = 1; i < n; ++i) {
        cout << costs[i] + a[i] << " ";
    }
    cout << endl;

    return 0;
}