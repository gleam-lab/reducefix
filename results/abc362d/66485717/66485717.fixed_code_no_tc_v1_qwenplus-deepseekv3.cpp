#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr i64 inf = 1e18;

struct Node {
    int x;
    i64 w;
    bool operator < (const Node& u) const {
        return w > u.w;
    }
};

vector<pair<int, int>> g[200005];
i64 d[200005];
bool vis[200005];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        g[i].clear();
        d[i] = inf;
        vis[i] = false;
    }
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        g[u].emplace_back(v, b);
        g[v].emplace_back(u, b);
    }
    priority_queue<Node> pq;
    d[1] = a[1];
    pq.push({1, d[1]});
    while (!pq.empty()) {
        auto [x, w] = pq.top();
        pq.pop();
        if (vis[x]) continue;
        vis[x] = true;
        for (const auto& [y, b] : g[x]) {
            if (d[y] > d[x] + b + a[y]) {
                d[y] = d[x] + b + a[y];
                pq.push({y, d[y]});
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        cout << d[i] << (i == n ? "\n" : " ");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}