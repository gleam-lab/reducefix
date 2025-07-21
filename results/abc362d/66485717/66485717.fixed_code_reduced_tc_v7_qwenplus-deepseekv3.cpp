#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr i64 INF = 9223372036854775807LL;

struct Node {
    int x;
    i64 w;
    bool operator < (const Node& u) const {
        return w > u.w;
    }
};

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
        g[u].emplace_back(v, b);
        g[v].emplace_back(u, b);
    }
    vector<i64> d(n + 1, INF);
    vector<bool> vis(n + 1, false);
    priority_queue<Node> pq;
    d[1] = a[1];
    pq.push({1, d[1]});
    while (!pq.empty()) {
        auto node = pq.top();
        pq.pop();
        int x = node.x;
        if (vis[x]) continue;
        vis[x] = true;
        for (const auto& [y, b] : g[x]) {
            if (d[x] + b + a[y] < d[y]) {
                d[y] = d[x] + b + a[y];
                pq.push({y, d[y]});
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
    solve();
    return 0;
}