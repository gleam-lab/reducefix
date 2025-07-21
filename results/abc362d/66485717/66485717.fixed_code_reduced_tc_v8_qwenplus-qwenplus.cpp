#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct Node {
    int x;
    i64 w;
    bool operator<(const Node& other) const {
        return w > other.w; // min-heap based on path weight
    }
};

constexpr i64 INF = 9223372036854775807; // Proper max value for i64

void solve() {
    int n, m;
    cin >> n >> m;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<vector<pair<int, i64>>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        i64 b;
        cin >> u >> v >> b;
        g[u].push_back({v, b});
        g[v].push_back({u, b});
    }

    vector<i64> d(n + 1, INF);
    vector<bool> vis(n + 1, false);
    priority_queue<Node> pq;

    d[1] = a[1]; // Start from node 1 with its vertex weight
    pq.push({1, d[1]});

    while (!pq.empty()) {
        auto [u, cost] = pq.top();
        pq.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (const auto& [v, edge_cost] : g[u]) {
            i64 new_cost = cost + edge_cost + a[v];
            if (new_cost < d[v]) {
                d[v] = new_cost;
                pq.push({v, d[v]});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << d[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}