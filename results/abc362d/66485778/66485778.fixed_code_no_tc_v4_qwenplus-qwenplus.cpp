#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;

struct Node {
    int node;
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
    for(int i = 0; i < m; ++i) {
        int u, v;
        i64 b;
        cin >> u >> v >> b;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }

    vector<i64> min_dist(n + 1, numeric_limits<i64>::max());
    priority_queue<Node> pq;

    // Start from node 1, path weight includes A[1] since we step on it
    min_dist[1] = A[1];
    pq.push({1, A[1]});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int u = current.node;
        i64 current_dist = current.dist;

        if (current_dist > min_dist[u]) continue;

        for (auto [v, b] : graph[u]) {
            // When moving to v, we add edge weight b and vertex weight A[v]
            i64 new_dist = current_dist + b + A[v];

            if (new_dist < min_dist[v]) {
                min_dist[v] = new_dist;
                pq.push({v, new_dist});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << min_dist[i] << " ";
    }
    cout << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}