#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;

struct Node {
    int node;
    i64 dist;
    bool operator<(const Node& other) const {
        return dist > other.dist;
    }
};

constexpr int MAXN = 2 * 1e5 + 10;
constexpr i64 INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<i64> A(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    
    vector<vector<pair<int, i64>>> graph(n + 1);
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        i64 b;
        cin >> u >> v >> b;
        graph[u].emplace_back(v, b);
        graph[v].emplace_back(u, b);
    }
    
    priority_queue<Node> pq;
    vector<i64> min_dist(n + 1, INF);
    vector<bool> visited(n + 1, false);
    
    // Start from node 1, initial distance is just A[1]
    min_dist[1] = A[1];
    pq.push({1, min_dist[1]});
    
    while (!pq.empty()) {
        auto [u, dist] = pq.top();
        pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        
        for (const auto& [v, edge_cost] : graph[u]) {
            i64 new_dist = dist + edge_cost + A[v];
            if (!visited[v] && new_dist < min_dist[v]) {
                min_dist[v] = new_dist;
                pq.push({v, new_dist});
            }
        }
    }
    
    for (int i = 2; i <= n; ++i) {
        cout << min_dist[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}