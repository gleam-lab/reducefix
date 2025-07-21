#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

const ll INF = numeric_limits<ll>::max();

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    vector<vector<pli>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        u--, v--;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }

    vector<ll> dist(n, INF);
    priority_queue<pli, vector<pli>, greater<pli>> pq;

    dist[0] = A[0]; // Start node includes its own vertex weight
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, b] : adj[u]) {
            ll new_cost = d + b + A[v]; // Add edge weight and target vertex weight
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i < n; ++i)
        cout << dist[i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}