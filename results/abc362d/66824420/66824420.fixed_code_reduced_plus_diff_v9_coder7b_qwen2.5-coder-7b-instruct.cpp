#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = LLONG_MAX / 2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<pair<int, ll>>> adj(n + 1);
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<ll> dist(n + 1, INF);
    dist[1] = a[0];
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace(a[0], 1);

    while(!pq.empty()) {
        auto [d, node] = pq.top(); pq.pop();

        if(d > dist[node]) continue;

        for(auto &[neighbor, weight] : adj[node]) {
            ll new_dist = d + a[neighbor - 1] + weight;
            if(new_dist < dist[neighbor]) {
                dist[neighbor] = new_dist;
                pq.emplace(new_dist, neighbor);
            }
        }
    }

    for(int i = 2; i <= n; ++i) {
        cout << min(dist[i], (ll)a[i - 1]) << " ";
    }
    
    return 0;
}