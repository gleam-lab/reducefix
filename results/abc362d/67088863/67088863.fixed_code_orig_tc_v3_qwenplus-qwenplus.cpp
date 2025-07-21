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

    vector<ll> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    vector<vector<pair<int, ll>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w + A[v]});
        adj[v].push_back({u, w + A[u]});
    }

    vector<ll> dist(n, INF);
    dist[0] = A[0]; // Starting from node 1 (index 0), include its own weight

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, cost] : adj[u]) {
            if (dist[v] > d + cost) {
                dist[v] = d + cost;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
}