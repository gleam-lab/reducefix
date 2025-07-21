#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr i64 INF = 1e18;

struct Node {
    int node;
    i64 dist;
    bool operator<(const Node& other) const {
        return dist > other.dist; // min-heap based on distance
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

    vector<i64> min_dist(n + 1, INF);
    priority_queue<Node> pq;

    // Start from node 1, include its vertex weight
    min_dist[1] = A[1];
    pq.push({1, min_dist[1]});

    while (!pq.empty()) {
        auto [current, current_dist] = pq.top();
        pq.pop();

        if (current_dist > min_dist[current]) continue;

        for (const auto &[neighbor, edge_weight] : graph[current]) {
            i64 new_dist = current_dist + edge_weight + A[neighbor];

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
    solve();
    return 0;
}