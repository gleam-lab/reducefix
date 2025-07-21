#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;
constexpr int N = 2 * 1e5 + 10;
const i64 INF = 1e18;

vector<pii> g[N];
i64 dist[N];
bool vis[N];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<i64> A(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        i64 w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<>> pq;
    fill(dist, dist + n + 1, INF);
    fill(vis, vis + n + 1, false);

    dist[1] = A[1];
    pq.emplace(dist[1], 1);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto [v, cost] : g[u]) {
            if (!vis[v] && dist[v] > d + cost + A[v]) {
                dist[v] = d + cost + A[v];
                pq.emplace(dist[v], v);
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}