#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;

struct Node {
    int vertex;
    i64 dist;
    bool operator<(const Node& other) const {
        return dist > other.dist; // Min-heap based on distance
    }
};

constexpr int N = 2 * 1e5 + 10;
constexpr i64 INF = 1e18;

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

    vector<i64> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);
    priority_queue<Node> pq;

    // Start from vertex 1 with path weight equal to A[1]
    dist[1] = A[1];
    pq.push({1, dist[1]});

    while (!pq.empty()) {
        auto [u, d] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto &[v, edge_cost] : graph[u]) {
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
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}