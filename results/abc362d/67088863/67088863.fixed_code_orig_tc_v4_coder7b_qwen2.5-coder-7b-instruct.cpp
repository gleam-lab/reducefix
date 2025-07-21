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
int MOD = 1e9 + 7;
const int N = 2e5 + 5;

struct Edge {
    int to, weight;
};

void dijkstra(const vector<vector<Edge>>& adj, const vector<int>& val, int start, vector<ll>& dist) {
    int n = adj.size();
    dist.assign(n, INF);
    dist[start] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto& [v, w] : adj[u]) {
            ll new_dist = d + w + val[v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> val(n);
    for (ll& i : val) cin >> i;

    vector<vector<Edge>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--; // Adjust for zero-based indexing
        adj[u].push_back({v, 1ll * w + val[u]});
        adj[v].push_back({u, 1ll * w + val[v]});
    }

    vector<ll> dist(n, INF);
    dijkstra(adj, val, 0, dist);

    for (int i = 1; i < n; i++)
        cout << dist[i] + val[i] << " ";

    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}