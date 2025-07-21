#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;

struct Node {
    int node;
    i64 dist;
    bool operator<(const Node& other) const {
        return dist > other.dist; // min-heap based on distance
    }
};

constexpr int MAXN = 2 * 100000 + 10;

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

    vector<i64> min_dist(n + 1, numeric_limits<i64>::max());
    priority_queue<Node> pq;

    // Start from node 1 with initial cost A[1]
    min_dist[1] = A[1];
    pq.push({1, min_dist[1]});

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();

        int u = current.node;
        i64 current_dist = current.dist;

        if (current_dist > min_dist[u]) continue;

        for (auto& edge : graph[u]) {
            int v = edge.first;
            i64 edge_cost = edge.second;
            i64 new_dist = current_dist + edge_cost + A[v];

            if (new_dist < min_dist[v]) {
                min_dist[v] = new_dist;
                pq.push({v, new_dist});
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