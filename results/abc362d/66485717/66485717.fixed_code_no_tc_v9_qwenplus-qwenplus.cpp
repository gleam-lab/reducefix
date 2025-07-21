#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr i64 INF = 1e18;

struct Node {
    int vertex;
    i64 dist;
    bool operator<(const Node& other) const {
        return dist > other.dist; // Min-heap based on distance
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

    vector<i64> minDist(n + 1, INF);
    priority_queue<Node> pq;

    // Start from node 1, the initial cost is just A[1] since we're at the starting vertex
    minDist[1] = A[1];
    pq.push({1, minDist[1]});

    while (!pq.empty()) {
        int curr = pq.top().vertex;
        i64 currDist = pq.top().dist;
        pq.pop();

        // Skip if we've found a better path already
        if (currDist > minDist[curr]) continue;

        for (const auto& [next, edgeCost] : graph[curr]) {
            i64 newDist = currDist + edgeCost + A[next];
            if (newDist < minDist[next]) {
                minDist[next] = newDist;
                pq.push({next, newDist});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << minDist[i] << " ";
    }
    cout << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}