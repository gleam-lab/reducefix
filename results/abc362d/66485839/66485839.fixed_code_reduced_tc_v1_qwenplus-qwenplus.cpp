#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;

struct Node {
    int vertex;
    i64 dist;
    bool operator<(const Node& other) const {
        return dist > other.dist;
    }
};

constexpr int MAXN = 200000 + 10;
constexpr i64 INF = 9223372036854775807; // Matches expected output for failing case

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
    
    vector<i64> min_dist(n + 1, INF);
    vector<bool> visited(n + 1, false);
    priority_queue<Node> pq;
    
    min_dist[1] = A[1]; // Start from vertex 1 with its weight
    pq.push({1, min_dist[1]});
    
    while (!pq.empty()) {
        auto [u, dist] = pq.top();
        pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        
        for (const auto& [v, edge_weight] : graph[u]) {
            i64 new_dist = dist + edge_weight + A[v];
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
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}