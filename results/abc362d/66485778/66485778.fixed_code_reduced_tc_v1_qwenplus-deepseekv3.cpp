#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node {
    int x;
    int64_t w;
    bool operator < (const Node& u) const {
        return w > u.w;
    }
};

const int64_t INF = 9223372036854775807LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 1; i <= m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        g[u].emplace_back(v, b);
        g[v].emplace_back(u, b);
    }
    vector<int64_t> d(n + 1, INF);
    vector<bool> vis(n + 1, false);
    priority_queue<Node> pq;
    d[1] = a[1];
    pq.push({1, d[1]});
    while (!pq.empty()) {
        auto [x, w] = pq.top();
        pq.pop();
        if (vis[x]) continue;
        vis[x] = true;
        for (const auto& [y, bw] : g[x]) {
            int64_t new_dist = d[x] + bw + a[y];
            if (new_dist < d[y]) {
                d[y] = new_dist;
                pq.push({y, d[y]});
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        cout << d[i] << " \n"[i == n];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}