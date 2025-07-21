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
    
    vector<i64> minPath(n + 1, INF);
    priority_queue<Node> pq;
    
    minPath[1] = A[1];  // Start from node 1 with its weight
    pq.push({1, minPath[1]});
    
    while (!pq.empty()) {
        auto [current, currentDist] = pq.top();
        pq.pop();
        
        if (currentDist > minPath[current]) continue;
        
        for (const auto& [neighbor, edgeWeight] : graph[current]) {
            i64 newPath = currentDist + edgeWeight + A[neighbor];
            if (newPath < minPath[neighbor]) {
                minPath[neighbor] = newPath;
                pq.push({neighbor, newPath});
            }
        }
    }
    
    for (int i = 2; i <= n; ++i) {
        cout << minPath[i] << " ";
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