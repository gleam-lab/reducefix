#include <bits/stdc++.h>
using namespace std;

constexpr long long INF = 1e18;
using i64 = long long;

struct Node {
    int x;
    i64 w;
    bool operator < (const Node& u) const {
        return w > u.w; // min-heap: smaller weight has higher priority
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
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
    
    // Start from vertex 1 with initial cost of A[1]
    dist[1] = a[1];
    pq.push({1, dist[1]});
    
    while (!pq.empty()) {
        auto [u, d] = pq.top();
        pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        
        // For each neighbor
        for (auto [v, edge_weight] : g[u]) {
            i64 new_dist = dist[u] + edge_weight + a[v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({v, dist[v]});
            }
        }
    }
    
    // Output distances for vertices 2 to N
    for (int i = 2; i <= n; ++i) {
        cout << dist[i];
        if (i < n) cout << ' ';
    }
    cout << '\n';
    
    return 0;
}