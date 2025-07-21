#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

struct Node {
    int x;
    ll w;
    bool operator < (const Node& other) const {
        return w > other.w;
    }
};

vector<vector<pair<int, int>>> g;
vector<ll> d;
vector<bool> vis;

void solve() {
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    d.assign(n + 1, INF);
    vis.assign(n + 1, false);

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
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
        Node node = pq.top();
        pq.pop();
        int x = node.x;
        if (vis[x]) continue;
        vis[x] = true;
        for (auto [y, b] : g[x]) {
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