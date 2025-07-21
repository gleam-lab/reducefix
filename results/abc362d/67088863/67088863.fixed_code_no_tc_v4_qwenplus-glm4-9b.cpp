#include <iostream>
#include <vector>
#include <queue>
#include <climits> // For LLONG_MAX

using namespace std;
typedef long long ll;

const int N = 200005; // 2 * 10^5 + 5

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> val(N);
    for (int i = 0; i < n; i++) cin >> val[i];

    vector<vector<pair<int, ll>>> adj(N);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<ll> dist(N, LLONG_MAX); // Use LLONG_MAX for initialization
    dist[0] = 0; // Starting point
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [w, v] = pq.top();
        pq.pop();
        if (w > dist[v]) continue; // Skip if we already have a shorter path to v

        for (auto [u, weight] : adj[v]) {
            ll newDist = w + weight;
            if (newDist < dist[u]) {
                dist[u] = newDist;
                pq.push({dist[u], u});
            }
        }
    }

    for (int i = 1; i < n; i++) {
        cout << (dist[i] + val[i]) << " ";
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