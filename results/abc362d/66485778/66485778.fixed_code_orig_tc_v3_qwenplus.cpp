#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr i64 INF = 1e18;

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
        i64 w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    
    vector<i64> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);
    priority_queue<Node> pq;
    
    dist[1] = a[1];
    pq.push({1, a[1]});
    
    while (!pq.empty()) {
        auto [u, d] = pq.top();
        pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        
        for (auto [v, w] : g[u]) {
            if (!visited[v] && dist[u] + w + a[v] < dist[v]) {
                dist[v] = dist[u] + w + a[v];
                pq.push({v, dist[v]});
            }
        }
    }
    
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}