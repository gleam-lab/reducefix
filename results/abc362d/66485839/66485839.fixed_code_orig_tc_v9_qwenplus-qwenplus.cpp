#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;
using tup = tuple<int, int, int>;

const int N = 2e5 + 10;
const i64 INF = 1e18;

vector<vector<pii>> adj(N);
i64 dist[N];
int A[N];

void solve() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        dist[i] = INF;
    }
    
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<>> pq;
    dist[1] = A[1];
    pq.emplace(dist[1], 1);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w + A[v]) {
                dist[v] = dist[u] + w + A[v];
                pq.emplace(dist[v], v);
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}