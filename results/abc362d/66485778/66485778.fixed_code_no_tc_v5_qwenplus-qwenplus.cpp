#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;

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

    const i64 INF = numeric_limits<i64>::max() / 2;
    vector<i64> dist(n + 1, INF);
    priority_queue<Node> pq;

    // Start from node 1, path weight includes A[1]
    dist[1] = A[1];
    pq.push({1, dist[1]});

    while (!pq.empty()) {
        auto [u, d] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, edge_cost] : graph[u]) {
            i64 new_dist = dist[u] + edge_cost + A[v];

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({v, new_dist});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}