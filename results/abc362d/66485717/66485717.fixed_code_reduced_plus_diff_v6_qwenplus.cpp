#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Node {
    int x;
    i64 w;
    bool operator < (const Node& u) const {
        return w > u.w; // Min-heap: smaller weight has higher priority
    }
};

constexpr i64 INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    
    vector<i64> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);
    priority_queue<Node> pq;
    
    // Start from vertex 1 with cost A[1] (only the starting vertex weight)
    dist[1] = a[1];
    pq.push({1, dist[1]});
    
    while (!pq.empty()) {
        auto [u, d] = pq.top();
        pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        
        // For each neighbor
        for (auto [v, edge_weight] : g[u]) {
            // New cost: current distance + edge weight + vertex weight of destination
            i64 new_cost = dist[u] + edge_weight + a[v];
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({v, new_cost});
            }
        }
    }
    
    // Output answers for vertices 2 to N
    for (int i = 2; i <= n; ++i) {
        cout << dist[i];
        if (i < n) cout << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}