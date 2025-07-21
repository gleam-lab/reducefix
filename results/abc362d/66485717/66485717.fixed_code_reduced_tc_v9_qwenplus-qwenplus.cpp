#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr i64 INF = 1e18;

struct Node {
    int vertex;
    i64 distance;
    bool operator<(const Node& other) const {
        return distance > other.distance; // Min-heap based on distance
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

    // Start from node 1 with its weight only
    minPath[1] = A[1];
    pq.push({1, minPath[1]});

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();

        int u = current.vertex;
        i64 distU = current.distance;

        if (distU > minPath[u]) continue;

        for (auto& [v, edgeWeight] : graph[u]) {
            i64 newPath = distU + edgeWeight + A[v];
            if (newPath < minPath[v]) {
                minPath[v] = newPath;
                pq.push({v, minPath[v]});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << minPath[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}