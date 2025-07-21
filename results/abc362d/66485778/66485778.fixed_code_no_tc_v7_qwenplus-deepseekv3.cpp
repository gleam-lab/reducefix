#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll INF = 1e18;

struct Node {
    int x;
    ll w;
    bool operator < (const Node& other) const {
        return w > other.w; // For min-heap
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    vector<vector<pair<int, ll>>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        g[u].emplace_back(v, b);
        g[v].emplace_back(u, b);
    }
    
    vector<ll> dist(n + 1, INF);
    vector<bool> vis(n + 1, false);
    priority_queue<Node> pq;
    
    dist[1] = a[1];
    pq.push({1, dist[1]});
    
    while (!pq.empty()) {
        auto [x, w] = pq.top();
        pq.pop();
        if (vis[x]) continue;
        vis[x] = true;
        for (const auto& [y, dw] : g[x]) {
            if (dist[x] + dw + a[y] < dist[y]) {
                dist[y] = dist[x] + dw + a[y];
                pq.push({y, dist[y]});
            }
        }
    }
    
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << (i == n ? "\n" : " ");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}