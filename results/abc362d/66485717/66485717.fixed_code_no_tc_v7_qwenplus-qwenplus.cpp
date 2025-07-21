#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;

const i64 INF = 1e18;

struct Node {
    int vertex;
    i64 dist;
    bool operator<(const Node& other) const {
        return dist > other.dist; // min-heap (priority_queue)
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

    vector<i64> dist(n + 1, INF);
    priority_queue<Node> pq;

    // Start from node 1, path weight includes A[1]
    dist[1] = A[1];
    pq.push({1, dist[1]});

    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        int u = curr.vertex;
        i64 d = curr.dist;

        if (d > dist[u]) continue;

        for (auto [v, edge_cost] : graph[u]) {
            i64 new_dist = dist[u] + edge_cost + A[v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({v, dist[v]});
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