#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
typedef long long ll;

const ll INF = LLONG_MAX;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (ll &val : a) cin >> val;

    vector<vector<pair<int, ll>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        u--; v--;
        adj[u].emplace_back(v, b);
        adj[v].emplace_back(u, b);
    }

    vector<ll> dist(n, INF);
    dist[0] = a[0];
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace(dist[0], 0);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, b] : adj[u]) {
            ll new_dist = d + b + a[v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.emplace(dist[v], v);
            }
        }
    }

    for (int i = 1; i < n; i++) {
        cout << dist[i] << " \n"[i == n-1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}