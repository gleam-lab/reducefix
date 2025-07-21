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

    vector<ll> A(n);
    for (ll &a : A) cin >> a;

    vector<vector<pair<int, ll>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        u--, v--;
        adj[u].emplace_back(v, b);
        adj[v].emplace_back(u, b);
    }

    vector<ll> dist(n, INF);
    dist[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, b] : adj[u]) {
            ll new_dist = d + A[u] + b + A[v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.emplace(dist[v], v);
            }
        }
    }

    for (int i = 1; i < n; i++) {
        cout << dist[i] - A[i] << (i == n - 1 ? "\n" : " ");
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}