#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 5;

struct Edge {
    int to, w;
};

void dijkstra(const vector<vector<Edge>>& g, const vector<ll>& a, vector<ll>& dist, int start) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[start] = a[start];
    pq.push({dist[start], start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d != dist[u]) continue;

        for (auto& e : g[u]) {
            int v = e.to;
            ll cost = d + e.w + a[v];

            if (cost < dist[v]) {
                dist[v] = cost;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<Edge>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v; // Adjust for 0-based indexing
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    vector<ll> dist(n, LLONG_MAX);
    dijkstra(g, a, dist, 0);

    for (int i = 1; i < n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}