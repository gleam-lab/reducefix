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

constexpr int MAXN = 2 * 1e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<i64> A(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    
    vector<vector<pair<int, i64>>> graph(n + 1);
    
    for(int i = 0; i < m; ++i) {
        int u, v;
        i64 b;
        cin >> u >> v >> b;
        graph[u].emplace_back(v, b);
        graph[v].emplace_back(u, b);
    }
    
    vector<i64> min_dist(n + 1, numeric_limits<i64>::max());
    priority_queue<Node> pq;
    
    min_dist[1] = A[1]; // Start from vertex 1 with its weight
    pq.push({1, min_dist[1]});
    
    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();
        
        if (curr.dist > min_dist[curr.vertex]) {
            continue;
        }
        
        for (auto [neighbor, edge_weight] : graph[curr.vertex]) {
            i64 new_dist = curr.dist + edge_weight + A[neighbor];
            
            if (new_dist < min_dist[neighbor]) {
                min_dist[neighbor] = new_dist;
                pq.push({neighbor, new_dist});
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