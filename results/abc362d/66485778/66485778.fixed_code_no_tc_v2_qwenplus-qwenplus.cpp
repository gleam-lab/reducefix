#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;

const i64 INF = 1e18;

struct Node {
    int vertex;
    i64 dist;
    bool operator<(const Node& other) const {
        return dist > other.dist;
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
        int u, v, b;
        cin >> u >> v >> b;
        graph[u].emplace_back(v, b);
        graph[v].emplace_back(u, b);
    }

    vector<i64> min_dist(n + 1, INF);
    vector<bool> visited(n + 1, false);
    priority_queue<Node> pq;

    // Start from node 1, path weight starts with A[1]
    min_dist[1] = A[1];
    pq.push({1, min_dist[1]});

    while (!pq.empty()) {
        int u = pq.top().vertex;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto [v, edge_weight] : graph[u]) {
            // Path cost: current path cost to u + edge weight + vertex weight of v
            i64 new_cost = min_dist[u] + edge_weight + A[v];
            if (!visited[v] && new_cost < min_dist[v]) {
                min_dist[v] = new_cost;
                pq.push({v, new_cost});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << min_dist[i] << " ";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}