#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr i64 INF = 9223372036854775807; // Maximum value for signed 64-bit integer

struct Node {
    int vertex;
    i64 cost;
    bool operator<(const Node& other) const {
        return cost > other.cost; // Min-heap based on cost
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

    vector<i64> minPath(n + 1, INF);
    priority_queue<Node> pq;

    // Start from vertex 1 with its weight only
    minPath[1] = A[1];
    pq.push({1, minPath[1]});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int u = current.vertex;
        i64 currentCost = current.cost;

        // Skip if we've already found a better path
        if (currentCost > minPath[u]) continue;

        for (const auto& [v, edgeCost] : graph[u]) {
            i64 newPathCost = currentCost + edgeCost + A[v];

            if (newPathCost < minPath[v]) {
                minPath[v] = newPathCost;
                pq.push({v, newPathCost});
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
    solve();
    return 0;
}