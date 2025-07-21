#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

vector<vector<pair<int, ll>>> adj(N);

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> val(n);
    for (ll& i : val) cin >> i;
    
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        a--, b--;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    vector<ll> dist(n, INF);

    dist[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [w, v] = pq.top();
        pq.pop();
        if (w > dist[v]) continue;
        
        for (auto [u, ww] : adj[v]) {
            if (ww + dist[v] < dist[u]) {
                dist[u] = ww + dist[v];
                pq.push({dist[u], u});
            }
        }
    }
    
    for (int i = 1; i < n; i++) cout << dist[i] << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}