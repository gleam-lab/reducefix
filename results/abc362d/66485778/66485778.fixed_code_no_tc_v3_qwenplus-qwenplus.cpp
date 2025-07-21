#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;

struct Node {
    int vertex;
    i64 dist;
    bool operator<(const Node& other) const {
        return dist > other.dist; // min-heap
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

    vector<i64> min_path(n + 1, 1e18);
    priority_queue<Node> pq;
    min_path[1] = A[1]; // Start from vertex 1 with its weight
    pq.push({1, min_path[1]});

    while (!pq.empty()) {
        auto [u, dist] = pq.top();
        pq.pop();

        if (dist > min_path[u]) continue;

        for (auto [v, edge_weight] : graph[u]) {
            i64 new_dist = dist + edge_weight + A[v];
            if (new_dist < min_path[v]) {
                min_path[v] = new_dist;
                pq.push({v, new_dist});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << min_path[i] << " ";
    }
    cout << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}