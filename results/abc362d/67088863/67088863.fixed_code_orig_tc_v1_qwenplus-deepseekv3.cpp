#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
typedef long long ll;

const ll INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (ll &i : a) cin >> i;
    
    vector<vector<pair<int, ll>>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        u--, v--;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }

    vector<ll> dist(n, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[0] = a[0];
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, b] : adj[u]) {
            ll new_dist = d + b + a[v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i < n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}