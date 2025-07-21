#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;

const ll INF = LLONG_MAX;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> A(n);
    for (ll &i : A) cin >> i;

    vector<vector<pair<int, ll>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        u--, v--;
        adj[u].emplace_back(v, b + A[u] + A[v]);
        adj[v].emplace_back(u, b + A[u] + A[v]);
    }

    vector<ll> dist(n, INF);
    dist[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        auto [current_dist, u] = pq.top();
        pq.pop();
        if (current_dist > dist[u]) continue;

        for (auto [v, weight] : adj[u]) {
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
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