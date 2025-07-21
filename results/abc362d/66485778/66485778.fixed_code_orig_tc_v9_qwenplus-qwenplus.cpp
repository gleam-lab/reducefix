#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr i64 INF = 1e18;

struct Node {
    int node;
    i64 dist;
    bool operator<(const Node& other) const {
        return dist > other.dist; // min-heap
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<i64> A(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> A[i];
    
    vector<vector<pair<int, i64>>> graph(n + 1);
    while (m--) {
        int u, v;
        i64 w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    priority_queue<Node> pq;
    vector<i64> dist(n + 1, INF);
    dist[1] = A[1]; // start from node 1 with its weight
    pq.push({1, dist[1]});

    while (!pq.empty()) {
        auto [u, d] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        
        for (auto& [v, cost] : graph[u]) {
            if (dist[u] + cost + A[v] < dist[v]) {
                dist[v] = dist[u] + cost + A[v];
                pq.push({v, dist[v]});
            }
        }
    }

    for (int i = 2; i <= n; ++i)
        cout << dist[i] << " ";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}