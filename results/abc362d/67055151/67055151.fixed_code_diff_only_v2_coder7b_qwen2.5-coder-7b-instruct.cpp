#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge {
    int to;
    ll cost;
};

const ll INF = 1e18;

void dijkstra(int src, vector<vector<Edge>>& adj, vector<ll>& dist) {
    int n = adj.size();
    dist.assign(n, INF);
    dist[src] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto& [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<vector<Edge>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        --u, --v;
        adj[u].emplace_back(v, b);
        adj[v].emplace_back(u, b);
    }

    vector<ll> ans(n - 1, INF);
    for (int i = 1; i < n; ++i) {
        vector<ll> dist;
        dijkstra(0, adj, dist);
        ans[i - 1] = dist[i] + a[i];
    }

    for (int i = 0; i < n - 1; ++i)
        cout << ans[i] << ' ';
    cout << endl;

    return 0;
}