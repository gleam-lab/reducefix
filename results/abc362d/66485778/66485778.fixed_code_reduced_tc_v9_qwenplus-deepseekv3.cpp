#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node {
    int x;
    int64_t w;
    bool operator < (const Node& other) const {
        return w > other.w;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int64_t> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<vector<pair<int, int64_t>>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        int64_t b;
        cin >> u >> v >> b;
        g[u].emplace_back(v, b + a[v]);
        g[v].emplace_back(u, b + a[u]);
    }
    vector<int64_t> d(n + 1, LLONG_MAX);
    vector<bool> vis(n + 1, false);
    priority_queue<Node> pq;
    d[1] = a[1];
    pq.push({1, d[1]});
    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        int x = node.x;
        if (vis[x]) continue;
        vis[x] = true;
        for (const auto& [y, cost] : g[x]) {
            if (d[x] + cost < d[y]) {
                d[y] = d[x] + cost;
                pq.push({y, d[y]});
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        cout << d[i] << (i == n ? '\n' : ' ');
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}