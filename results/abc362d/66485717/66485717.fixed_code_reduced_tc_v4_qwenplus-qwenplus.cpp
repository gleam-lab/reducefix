#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr i64 INF = 9223372036854775807; // Proper max value for 64-bit signed integer

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

    vector<i64> dist(n + 1, INF);
    priority_queue<Node> pq;

    dist[1] = A[1]; // Start from vertex 1 with its weight
    pq.push({1, dist[1]});

    while (!pq.empty()) {
        auto [u, d] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, b] : graph[u]) {
            i64 new_dist = dist[u] + b + A[v]; // Path weight to neighbor
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({v, dist[v]});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}