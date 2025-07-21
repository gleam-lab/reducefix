#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;

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
        int u, v;
        i64 b;
        cin >> u >> v >> b;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }

    vector<i64> minDist(n + 1, numeric_limits<i64>::max());
    priority_queue<Node> pq;

    // Start from vertex 1, path weight includes A[1]
    minDist[1] = A[1];
    pq.push({1, minDist[1]});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int u = current.vertex;
        i64 currentDist = current.dist;

        if (currentDist > minDist[u]) continue;

        for (auto [v, edgeWeight] : graph[u]) {
            i64 newDist = currentDist + edgeWeight + A[v];

            if (newDist < minDist[v]) {
                minDist[v] = newDist;
                pq.push({v, newDist});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << minDist[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}