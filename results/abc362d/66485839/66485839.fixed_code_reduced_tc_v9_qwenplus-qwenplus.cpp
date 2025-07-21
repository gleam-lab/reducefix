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

constexpr int MAXN = 2 * 100000 + 5;
constexpr i64 INF = numeric_limits<i64>::max() / 2;

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
    vector<i64> minPath(n + 1, INF);
    vector<bool> visited(n + 1, false);
    
    // Start from vertex 1
    minPath[1] = A[1];
    pq.push({1, minPath[1]});
    
    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        
        int u = current.vertex;
        if (visited[u]) continue;
        visited[u] = true;
        
        for (const auto& edge : graph[u]) {
            int v = edge.first;
            i64 edgeWeight = edge.second;
            
            i64 newPath = minPath[u] + edgeWeight + A[v];
            if (newPath < minPath[v]) {
                minPath[v] = newPath;
                pq.push({v, minPath[v]});
            }
        }
    }
    
    for (int i = 2; i <= n; ++i) {
        cout << minPath[i] << " ";
    }
    cout << endl;
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