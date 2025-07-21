#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> val(n);
    for (int i = 0; i < n; ++i) cin >> val[i];
    
    vector<vector<pair<int, ll>>> adj(n);

    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;

        a--, b--;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    
    vector<ll> dist(n, INF);
    dist[0] = val[0]; // Start with the weight of the starting vertex

    priority_queue<pair<ll, int>> pq;
    pq.push({val[0], 0});

    while (!pq.empty()) {
        auto [w, v] = pq.top();
        pq.pop();

        if (w > dist[v]) continue; // Skip if we've already found a shorter path

        for (auto [u, ww] : adj[v]) {
            if (w + ww < dist[u]) {
                dist[u] = w + ww;
                pq.push({dist[u], u});
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}