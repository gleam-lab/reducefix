#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr i64 INF = 1e18;

struct Node {
    int vertex;
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
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }

    vector<i64> minPath(n + 1, INF);
    priority_queue<Node> pq;

    // Start from node 1, path weight is just A[1] (no edges yet)
    minPath[1] = A[1];
    pq.push({1, A[1]});

    while (!pq.empty()) {
        auto [u, dist] = pq.top();
        pq.pop();

        // If we already found a better path to u, skip
        if (dist > minPath[u]) continue;

        for (auto [v, edgeWeight] : graph[u]) {
            i64 newDist = dist + edgeWeight + A[v];

            if (newDist < minPath[v]) {
                minPath[v] = newDist;
                pq.push({v, newDist});
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