#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

ll dp[200005]; // dp[i] will store the minimum weight to reach vertex i

vector<pair<int, ll>> adj[200005]; // adj[i] will store the pair (neighbor, edge_weight + vertex_weight)

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> dp[i]; // dp[0] is not used

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Start Dijkstra's algorithm from vertex 0
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    dp[0] = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dp[u]) continue;

        for (auto [v, edge_weight] : adj[u]) {
            ll new_dist = dp[u] + edge_weight;
            if (new_dist < dp[v]) {
                dp[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }

    // Output the results for vertices 1 to N-1
    for (int i = 1; i < n; i++) {
        cout << dp[i] << " ";
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