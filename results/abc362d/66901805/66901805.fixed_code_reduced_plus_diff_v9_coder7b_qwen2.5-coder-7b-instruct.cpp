#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

vector<pair<ll,ll>> G[200005];
ll dist[200005];

void dijkstra(int start, vector<ll> &weights) {
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    fill(dist, dist + n + 1, INF);
    dist[start] = weights[start];
    pq.push({dist[start], start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto &[v, w] : G[u]) {
            if (dist[u] + weights[v] + w < dist[v]) {
                dist[v] = dist[u] + weights[v] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll n, m; cin >> n >> m;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    dijkstra(1, a);

    for (int i = 2; i <= n; ++i) cout << dist[i] << " ";
    cout << "\n";

    return 0;
}